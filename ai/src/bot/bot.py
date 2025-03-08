from typing import TypeVar
from math import ceil, floor
from time import sleep
from typing import Dict
from ai.src.player.player import Player, TPlayer
from ai.src.client.client import Client, TClient
from ai.src.bot.fork import add_player, update_players, calculate_nb_fork

TBot = TypeVar("TBot", bound="Bot")


class Bot:
    """Bot class.

    Contains methods to:
        - initiate Client and Player classes.
        - analyse the state of the player.
        - choose the best action to do.

    Attributes:
        client (TClient): Class Client.
        player (TPlayer): Class Player.

    """

    def __init__(self, port: int, name: str, host: str, conf: str):
        """Init Bot Class.

        :param int port: the port to connect to the server.
        :param str name: the name of the team.
        :param str host: the host to connect to the server.
        :param str conf: the configuration file for the strategies.
        """
        self.client: TClient = Client(port, name, host)
        self.player: TPlayer = Player(self.client.connect_nbr, self.client.name, conf)

    def analyse_answer(self: TBot) -> None:
        """Analyse my answer to send.

        Send my answer to a broadcast message.
        """
        if len(self.client.command.commands) >= 10:
            return
        self.client.send_message(
            "Broadcast "
            + self.player.my_answer["uuid"]
            + " "
            + self.client.name
            + " "
            + str(self.player.level)
            + " Response "
            + self.player.my_answer["answer"],
            "Broadcast answer",
            True,
        )
        if self.player.my_answer["answer"] == "OK":
            self.player.inc_waiting = True
        self.player.my_answer = {}

    def analyse_confirmation(self: TBot) -> None:
        """Analyse my confirmation to send.

        Send my answer to a broadcast message.
        """
        if len(self.client.command.commands) >= 10:
            return
        self.client.send_message(
            "Broadcast "
            + self.player.my_confirmation["uuid"]
            + " "
            + self.client.name
            + " "
            + str(self.player.level)
            + " Confirmation "
            + self.player.my_confirmation["confirmation"],
            "Broadcast confirmation",
            True,
        )
        if self.player.my_confirmation["confirmation"] == "OK":
            self.player.is_waiting = True
        self.player.my_confirmation = {}
        self.player.players_answer = []

    def update_waiting(self: TBot) -> None:
        """Send a broadcast message to update my position.

        The update is following with a look and an inventory.
        """
        if (
            len(self.client.command.commands) >= 7
            or "Incantation" in self.client.command.commands
            or len(self.player.my_broadcast) == 0
        ):
            return
        self.client.send_message(
            "Broadcast "
            + self.player.my_broadcast[0]
            + " "
            + self.client.name
            + " "
            + str(self.player.level)
            + " Update",
            "Broadcast update",
            True,
        )
        self.client.send_message("Look", "Look", True)
        self.client.send_message("Inventory", "Inventory", True)
        self.player.launch_update = False

    def analyse_ending(self: TBot) -> None:
        """Analyse my ending to send.

        Send a broadcast to end my broadcast.
        """
        if len(self.client.command.commands) >= 10 or len(self.player.my_broadcast) == 0:
            return
        self.client.send_message(
            "Broadcast " + self.player.my_broadcast[0] + " " + self.client.name + " " + str(self.player.level) + " End",
            "Broadcast end",
            True,
        )
        print(f"Ending: {self.player.my_broadcast[0]}")
        self.player.my_broadcast.remove(self.player.my_broadcast[0])
        self.player.nb_player_answer = 0
        self.player.send_inc = False
        self.player.my_ending = False

    def analyse_join(self: TBot) -> None:
        """Analyse my join to send.

        Send a broadcast to ask another player to join me.
        """
        if len(self.client.command.commands) >= 10:
            return
        self.client.send_message(
            "Broadcast "
            + self.player.my_join["my_uuid"]
            + " "
            + self.client.name
            + " "
            + str(self.player.level)
            + " Join "
            + self.player.my_join["your_uuid"],
            "Broadcast join",
            True,
        )
        self.player.send_join = True
        self.player.my_join = {}

    def need_fork(self: TBot) -> int:
        """Calculate the number of fork needed to level up."""
        nb_players: Dict[str, int] = {"Ready": 1, "1": 0, "2": 0, "3": 0, "4": 0, "5": 0, "6": 0, "7": 0, "8": 0}
        needed_player: int = self.player.incantation_levels[self.player.level - 1]["player"]
        if self.player.level == 8:
            return 0
        for answer in self.player.players_answer:
            if nb_players["Ready"] >= needed_player:
                return 0
            if answer["answer"] == "OK":
                add_player("Ready", 1, nb_players)
                continue
            add_player(answer["level"], 1, nb_players)
            update_players(nb_players, str(self.player.level))
        if nb_players["Ready"] >= needed_player:
            return 0
        print(f"Connect nbr: {self.player.connect_nbr}")
        print(f"Client to add: {self.player.client_to_add}")
        nb_fork: float = calculate_nb_fork(nb_players, str(self.player.level), needed_player)
        if 1 > nb_fork > 0:
            nb_fork = 1
        nb_fork = floor(nb_fork)
        nb_fork -= self.player.connect_nbr + self.player.client_to_add
        self.player.client_to_add = 0
        return int(nb_fork)

    def analyse_fork(self: TBot) -> None:
        """Analyse if a fork is needed.

        Send a fork command if needed.
        """
        nb_fork: int = self.need_fork()

        if len(self.client.command.commands) + nb_fork >= 10 or self.player.is_forked:
            return
        if self.player.level == 8 and self.player.connect_nbr == 0:
            nb_fork = 1
        print(f"Forking {nb_fork} times")
        for fork in range(nb_fork):
            self.client.send_message("Fork", "Fork", True)
        self.player.players_answer = []
        self.player.connect_nbr_got = False
        if nb_fork > 0:
            self.player.is_forked = True

    def analyse_command(self: TBot) -> None:
        """Analyse the command to send."""
        if bool(self.player.my_answer):
            self.analyse_answer()
        if bool(self.player.my_confirmation):
            self.analyse_confirmation()
        if self.player.my_ending:
            self.analyse_ending()
        if bool(self.player.my_join):
            self.analyse_join()
        if self.player.connect_nbr_got:
            self.analyse_fork()

    def analyse_environment(self: TBot):
        """Analyse the environment of the player.

        This function permits to take the better decision for the player.
        """
        if self.player.analyzed is False:
            self.player.analyze(self.client)
        if self.player.handle_criticality(self.client):
            return
        if self.player.ate is False:
            self.player.eat(self.client)
        if self.player.moved is False:
            self.player.move(self.client)

    def elevate_strategies(self: TBot) -> bool:
        """Know if the player can elevate with his strategy."""
        if (self.player.strategy == "Materialist" or self.player.strategy == "Opportunist") and self.player.level != 1:
            return False
        if (
            self.player.strategy == "Thrifty"
            and self.player.level != 1
            and self.player.level != 6
            and self.player.level != 7
        ):
            return False
        return True

    def interact_with_players(self: TBot) -> bool:
        """Interact with other players.

        This function permits to interact with other players.
        It is useful to pursue a player, update my position and elevate.
        """
        if self.player.is_pursuing["Status"] == "True":
            self.player.pursue_message(self.client)
            return True
        if self.player.is_waiting and self.player.launch_update:
            self.update_waiting()
            sleep(float(self.client.command.time_unit["exec_duration"]) * len(self.client.command.commands))
        if self.player.inc_waiting is False and self.elevate_strategies():
            self.player.incantation_process(self.client, self.player.level)
            if self.player.is_waiting or self.player.inc_progress:
                return True
        return False

    def calculate_food(self: TBot) -> None:
        """Calculate the food needed to survive honourably"""
        x: int = self.client.x
        y: int = self.client.y
        eat_time: int = 126
        action_time: int = 7
        elevation_time: int = 300
        double_move: int = (min(x, y) - 1) * 4 * action_time
        single_move: int = abs(y - x) * action_time
        broadcast_action: int = max(x, y) * action_time
        total: int = double_move + single_move + broadcast_action + elevation_time
        self.player.food_needed = ceil(total / eat_time) + 15
        print(f"Food needed: {self.player.food_needed}")
