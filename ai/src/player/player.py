from __future__ import annotations
from typing import TypeVar, Dict, TYPE_CHECKING
from uuid import uuid4
from threading import Timer
from time import time
from random import randint
from ai.src.player.features import player_levels, player_movements, nb_stones
from ai.src.player.strategies import parse_conf_strategy
from ai.src.player.criticality import where_is_the_food, go_to_tile
from ai.src.player.stones import is_useful_stone

if TYPE_CHECKING:
    from ai.src.client.client import TClient

TPlayer = TypeVar("TPlayer", bound="Player")


class Player:
    """Player class.

    Contains methods to:
        - eat.
        - move.
        - do the incantation process.
        - broadcast.

    This class represent the Player in-game. It contains all information about the player
    and the main algorithm to play the game.

    Attributes:
        timer (Timer): Timer to send a request to the server.
        food_needed (int): number of food needed to survive.
        analyzed (bool): True if the player has analyzed the map.
        moved (bool): True if the player has moved.
        ate (bool): True if the player has eaten.
        broadcasted (bool): True if the player has broadcasted.
        level (int): the level of the player.
        last_look (list[list[str]]): the last look of the player.
        last_inventory (Dict[str, int]): the last inventory of the player.
        inc_underway (bool): True if the player is doing an incantation.
        broadcast_info (list[Dict[str, str]]): list of broadcast information.
        my_broadcast (list[str]): list of broadcast messages.
        send_inc (bool): True if the player has sent an incantation request.
        your_broadcast (str): the broadcast message of the player.
        is_waiting (bool): True if the player is waiting for a broadcast.
        inc_waiting (bool): True if the player is waiting for an incantation (2).
        inc_progress (bool): True if the player is in incantation process.
        is_dropping (bool): -
        is_got (bool): -
        is_pursuing (Dict[str, str]):
        is_critical (bool): True if the player is in critical mode.
        is_finished (bool): True if the player has finished the game.
        is_forked (bool): True if the player has forked.
        launch_update (bool): -
        connect_nbr (int): Number that determines if another player can connect to the server.
        client_to_add (int): Number of client to add.
        team_name (str): The team name of the player.
        my_answer (Dict[str, str]): The answer of the player.
        nb_player_answer (int): Number of player that answered to the broadcast.
        my_confirmation (Dict[str, str]): The confirmation of the player.
        my_ending (bool): -
        my_join (Dict[str, str]): The join of the player.
        my_connect_nbr (bool): -
        players_answer (list[Dict[str, str]]): List of players' answers to the broadcast.
        stones_copy (Dict[str, int]): -
        connect_nbr_got (bool): -
        strategy (str): The strategy of the player.
        eject_some_dudes (bool): True if the player can eject some others players.
        movements (list[Dict[str, list[str]]]): Movements depending on the received broadcast.
        total_stones (Dict[str, int]): Max stones for the player.
        incantation_levels (list[Dict[str, int]]): List of requirements for each level.
    """

    def __init__(self: TPlayer, connect_nbr: int, team_name: str, conf: str):
        """Init Player Class.

        :param int connect_nbr: Number that determines if another player can connect to the server.
        :param str team_name: The team name of the player.
        :param str conf: The configuration file for the player.
        """
        self.timer: Timer = Timer(0, lambda: None)
        self.food_needed: int = 0
        self.analyzed: bool = False
        self.moved: bool = True
        self.ate: bool = True
        self.broadcasted: bool = False
        self.level: int = 1
        self.last_look: list[list[str]] = []
        self.last_inventory: Dict[str, int] = {}
        self.inc_underway: bool = False
        self.broadcast_info: list[Dict[str, str]] = []
        self.my_broadcast: list[str] = []
        self.send_inc: bool = False
        self.your_broadcast: str = ""
        self.is_waiting: bool = False
        self.inc_waiting: bool = False
        self.inc_progress: bool = False
        self.is_dropping: bool = True
        self.is_got: bool = True
        self.is_pursuing: Dict[str, str] = {"Status": "False", "Ready": "False"}
        self.is_critical: bool = False
        self.is_finished: bool = False
        self.is_forked: bool = False
        self.launch_update: bool = True
        self.connect_nbr: int = connect_nbr
        self.client_to_add: int = 0
        self.team_name: str = team_name
        self.my_answer: Dict[str, str] = {}
        self.nb_player_answer: int = 0
        self.my_confirmation: Dict[str, str] = {}
        self.my_ending: bool = False
        self.my_join: Dict[str, str] = {}
        self.my_connect_nbr: bool = False
        self.players_answer: list[Dict[str, str]] = []
        self.stones_copy: Dict[str, int] = {}
        self.connect_nbr_got: bool = False
        self.strategy: str = parse_conf_strategy(conf)
        print(f"Strategy: {self.strategy}")
        self.eject_some_dudes: bool = False
        self.movements: list[Dict[str, list[str]]] = player_movements
        self.total_stones: Dict[str, int] = nb_stones
        self.incantation_levels: list[Dict[str, int]] = player_levels

    def delete_broadcast(self: TPlayer, uuid: str, is_mine: bool) -> None:
        """Delete a broadcast.

        If the broadcast is a player's broadcast, it will be removed from the
        player's broadcast list. If it is a broadcast from another player, it
        will be removed from the broadcast info list.

        :param str uuid: The uuid of the broadcast to delete.
        :param bool is_mine: True if the broadcast is a player's broadcast.
        """
        if is_mine:
            self.my_broadcast.remove(uuid)
        self.broadcast_info = [x for x in self.broadcast_info if not x["uuid"] == uuid]

    def add_broadcast(
        self: TPlayer,
        index: str,
        uuid: str,
        team: str,
        level: str,
        type: str,
        option: str,
    ) -> None:
        """Add a broadcast to list.

        :param str index: The index of the broadcast.
        :param str uuid: The uuid of the broadcast.
        :param str team: The team of the broadcast.
        :param str level: The level of the broadcast.
        :param str type: The type of the broadcast.
        :param str option: The option of the broadcast.
        """
        self.broadcast_info.append(
            {
                "from_index": index,
                "uuid": uuid,
                "team": team,
                "level": level,
                "type": type,
                "option": option,
            }
        )

    def fork_timeout(self: TPlayer) -> None:
        """Set the fork timeout.

        Set the fork timeout to True.
        """

    def pursue_message(self: TPlayer, client: TClient) -> None:
        """Pursue a broadcast.

        Follow a broadcast until the player is on the same index as the sender.
        If the strategy of the player is "eject", the player will eject the
        sender and every player that is on the same index as the sender.

        :param TClient client: The client to send messages.
        """
        if (
            int(self.is_pursuing["from_index"]) == 0
            or self.is_pursuing["Ready"] == "False"
            or len(client.command.commands) > 0
        ):
            if int(self.is_pursuing["from_index"]) == 0 and self.strategy == "Eject" and self.eject_some_dudes is False:
                print(self.my_confirmation)
                client.send_message("Eject", "Eject", True)
                self.eject_some_dudes = True
            return
        for move in self.movements[int(self.is_pursuing["from_index"])]["movements"]:
            if len(client.command.commands) >= 10:
                break
            client.send_message(move, move, True)
        print(f"Commands pursue = {client.command.commands}")
        self.is_pursuing.update(Ready="False")

    def analyze(self: TPlayer, client: TClient) -> None:
        """Analyze the map.

        Analyze the map by sending "Look" and "Inventory" commands. If the
        player is on a critical level, the player will not analyze the map.

        :param TClient client: The client to send messages.
        """
        if (
            len(client.command.commands) >= 9
            or "Look" in client.command.commands
            or "Inventory" in client.command.commands
            or "Incantation" in client.command.commands
            or self.is_critical
        ):
            return
        print("====ANALYZE====")
        client.send_message("Look", "Look", True)
        if (
            len(client.command.commands) == 1
            and client.command.time_unit["Ready"] == "False"
            and self.inc_underway is False
        ):
            client.command.time_unit["Ready"] = "True"
            client.command.start_time = time()
        client.send_message("Inventory", "Inventory", True)
        self.analyzed = True
        self.ate = False
        print("===============")

    def move(self: TPlayer, client: TClient) -> None:
        """Move the player.

        Move the player according to the strategy of the player.

        :param TClient client: The client to send messages.
        """
        if (
            len(self.last_look) == 0
            or "Incantation" in client.command.commands
            or "Forward" in client.command.commands
            or "Look" in client.command.commands
        ):
            return
        for element in client.command.commands:
            if "Take" in element:
                return
        if self.is_pursuing["Status"] == "True":
            self.analyzed = False
            self.moved = True
            return
        if self.strategy == "Fool" and randint(0, 2) == 0:
            while len(client.command.commands) < 10:
                client.send_message("Right", "Right", True)
                self.analyzed = False
                self.moved = True
        elif len(client.command.commands) < 8 and client.line == 0:
            print("====MOVE====")
            client.send_message("Right", "Right", True)
            client.send_message("Forward", "Forward", True)
            client.send_message("Left", "Left", True)
            client.line = client.y
            self.analyzed = False
            self.moved = True
            print("============")
        elif len(client.command.commands) < 10 and client.line != 0:
            print("====MOVE====")
            client.send_message("Forward", "Forward", True)
            client.line -= 1
            self.analyzed = False
            self.moved = True
            print("============")

    def eat(self: TPlayer, client: TClient) -> None:
        """Eat food.

        Take the food of player's tile first and then if the number of requests
        is not reached, take the stones of the player's tile.

        :param TClient client: The client to send messages.
        """
        index: int = 0

        if len(self.last_look) == 0 or len(client.command.commands) > 0:
            return
        if self.is_pursuing["Status"] == "True":
            self.analyzed = False
            return
        print("====EAT====")
        while len(client.command.commands) < 10 and index < len(self.last_look[0]):
            if "food" == self.last_look[0][index]:
                client.send_message("Take food", "Take food 0", True)
            index += 1
        index = -1
        while len(client.command.commands) < 10 and index + 1 < len(self.last_look[0]) and self.is_finished is False:
            index += 1
            if (self.strategy == "Opportunist" and self.level != 1) or (
                self.strategy == "Greedy" and randint(0, 1) == 0
            ):
                break
            elif self.strategy == "Opportunist" and self.last_look[0][index] != "linemate":
                continue
            if (
                self.last_look[0][index] == "player"
                or self.last_look[0][index] == "food"
                or is_useful_stone(self.strategy, self.last_look[0][index], self.total_stones, self.last_inventory)
                is False
            ):
                continue
            client.send_message(
                "Take " + self.last_look[0][index],
                "Take " + self.last_look[0][index] + " 0",
                True,
            )
        self.moved = False
        self.ate = True
        print("===========")

    def get_all(self: TPlayer, client: TClient) -> bool:
        """Get all the objects of the player's tile.

        This allows the player to clean its tile so that it can evolve.

        :param TClient client: The client to send messages.

        :return bool: True if the player is not moving from its tile, False otherwise.
        """
        temp_look: list[str] = self.last_look[0].copy()

        if "Forward" in client.command.commands:
            return False
        for element in temp_look:
            if element == "player":
                continue
            if len(client.command.commands) == 10:
                return False
            print("-->Take " + element)
            client.send_message("Take " + element, "Take " + element + " 0", True)
        self.is_got = False
        return True

    def drop_stones(self: TPlayer, client: TClient, current_level: int) -> None:
        """Drop stones.

        Drop stones according to the incantation levels.

        :param TClient client: The client to send messages.
        :param int current_level: The current level of the player.
        """
        temp_copy: Dict[str, int] = {}

        if bool(self.stones_copy) is False:
            self.stones_copy = self.incantation_levels[current_level - 1].copy()
        temp_copy = self.stones_copy.copy()
        for stone in temp_copy:
            if stone == "player":
                del self.stones_copy[stone]
                continue
            for i in range(temp_copy[stone]):
                if len(client.command.commands) >= 10:
                    return
                client.send_message("Set " + stone, "Set " + stone + " 0", True)
                self.stones_copy[stone] -= 1
            if self.stones_copy[stone] == 0:
                del self.stones_copy[stone]
        if bool(self.stones_copy) is False:
            self.is_dropping = False

    def broadcast_timeout(self: TPlayer, commands: list[str], exec_duration: float, uuid: str) -> None:
        """Broadcast timeout.

        This function is called when the player is waiting for a broadcast
        confirmation but the timeout is reached.

        :param list[str] commands: The commands to send.
        :param float exec_duration: The execution duration of the incantation.
        :param str uuid: The uuid of the sender.
        """
        if "Broadcast join" in commands:
            self.timer = Timer(
                exec_duration * self.incantation_levels[self.level - 1]["player"] * commands.index("Broadcast join"),
                self.broadcast_timeout,
                (commands, exec_duration, uuid),
            )
            self.timer.start()
            print(f"Add time to {uuid}")
            return
        self.my_confirmation = {}
        self.nb_player_answer = 0
        self.is_waiting = False
        self.my_ending = True
        self.broadcasted = False
        self.connect_nbr_got = True

    def is_ready_for_incantation(self: TPlayer, client: TClient, current_level: int) -> bool:
        """Check if the player is ready for an incantation.

        This function checks if the player has all the necessary conditions to
        evolve.

        :param TClient client: The client to send messages.
        :param int current_level: The current level of the player.

        :return bool: True if the player is ready for an incantation, False otherwise.
        """
        if len(client.command.commands) >= 9:
            return False
        if (
            self.broadcasted
            and self.last_look[0].count("player") >= self.incantation_levels[current_level - 1]["player"]
            and self.is_waiting
        ):
            self.inc_progress = True
            self.broadcasted = False
            return True
        all_stones = self.last_inventory.copy()
        del all_stones["food"]
        for stone in self.incantation_levels[current_level - 1]:
            try:
                if stone == "player":
                    continue
                if int(all_stones[stone]) < self.incantation_levels[current_level - 1][stone]:
                    return False
            except KeyError:
                return False
        if self.level == 1:
            self.inc_progress = True
            return True
        if (
            self.broadcasted
            or len(self.my_broadcast) > 0
            or "Inventory" in client.command.commands
            or client.command.time_unit["exec_duration"] == "0.0"
        ):
            return False
        if self.last_inventory["food"] < self.food_needed or self.is_waiting:
            return False
        new_id: str = str(uuid4())
        iterator: int = 0
        while iterator < len(self.broadcast_info):
            if self.broadcast_info[iterator]["uuid"] == new_id:
                new_id = str(uuid4())
                iterator = -1
            iterator += 1
        self.ask_connect_nbr(client)
        client.send_message(
            "Broadcast " + new_id + " " + client.name + " " + str(current_level) + " Incantation",
            "Broadcast incantation",
            True,
        )
        self.add_broadcast("0", new_id, client.name, str(current_level), "Incantation", "")
        print("Broadcast " + new_id + " " + client.name + " " + str(current_level) + " Incantation")
        self.my_broadcast.append(new_id)
        self.broadcasted = True
        return False

    def ask_connect_nbr(self: TPlayer, client: TClient) -> None:
        """Ask connect_nbr.

        This function asks the server if there is available connection slots.

        :param TClient client: The client to send messages.
        """
        if len(client.command.commands) >= 10:
            return
        client.send_message("Connect_nbr", "Connect_nbr", True)
        self.my_connect_nbr = False

    def incantation_process(self: TPlayer, client: TClient, current_level: int) -> None:
        """Incantation process.

        Handle all the incantation process.

        :param TClient client: The client to send messages.
        :param int current_level: The current level of the player.
        """
        if (
            len(self.last_inventory) == 0
            or len(self.last_look) == 0
            or "Incantation" in client.command.commands
            or self.your_broadcast != ""
        ):
            return
        if self.last_inventory["food"] <= 3:
            return
        if self.inc_underway is False and (self.inc_progress or self.is_ready_for_incantation(client, current_level)):
            if self.is_got is True:
                self.get_all(client)
            if self.is_dropping is True and self.is_got is False:
                self.drop_stones(client, current_level)
            if len(client.command.commands) >= 9 or self.is_dropping is True:
                return
            print("Incantation process")
            client.send_message("Incantation", "Incantation", True)
            self.analyzed = True
            self.ate = True
            self.moved = True
            self.inc_progress = False
            self.is_dropping = True
            self.is_got = True
            print(client.command.commands)

    def handle_criticality(self: TPlayer, client: TClient) -> bool:
        """Handle criticality.

        This function handles the food criticality of the player and move him where food is the nearest.

        :param TClient client: The client to send messages.

        :return bool: True if the player is handling a criticality, False otherwise.
        """
        try:
            food_quantity: int = self.last_inventory["food"]
        except KeyError:
            food_quantity = 10
        if food_quantity <= self.food_needed and len(client.command.commands) < 10:
            self.is_critical = True
            if len(client.command.commands) > 0:
                return True
            print("----------HANDLE CRITICALITY----------")
            nearest_food: int = where_is_the_food(self.last_look)
            index: int = 0
            if nearest_food == 0:
                while self.last_look[nearest_food].count("food") > index and len(client.command.commands) < 10:
                    client.send_message("Take food", "Take food 0", True)
                    index += 1
            else:
                go_to_tile(client, nearest_food)
                while self.last_look[nearest_food].count("food") > index and len(client.command.commands) < 10:
                    client.send_message("Take food", "Take food " + str(nearest_food), True)
                    index += 1
            self.is_critical = False
            self.analyzed = False
            self.ate = True
            print("--------------------------------------")
            return True
        self.is_critical = False
        return False
