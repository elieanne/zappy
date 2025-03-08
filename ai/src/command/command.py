from typing import TypeVar, Dict, TYPE_CHECKING
from time import time
from threading import Timer
from ai.src.player.player import TPlayer
from ai.src.player.stones import remove_total_stones
from ai.src.command.exec_type import (
    exec_type_incantation,
    exec_type_response,
    exec_type_confirmation,
    exec_type_update,
    exec_type_end,
    exec_type_join,
    exec_type_connection,
)

if TYPE_CHECKING:
    from ai.src.player.player import TPlayer

TCommand = TypeVar("TCommand", bound="Command")


def exec_msg_connect_nbr(player: TPlayer, message: str) -> bool:
    """Parse the server's response for the command "Connect_nbr\n".

    :param TPlayer player: the player who received the message.
    :param str message: the message received from the server.

    :return bool: True if the parsing is a success, False otherwise.

    :raises ValueError: if there is a problem with the parsing.
    """
    try:
        player.connect_nbr = int(message)
        if player.level == 8:
            player.connect_nbr_got = True
    except ValueError:
        return False
    return True


def exec_msg_inventory(player: TPlayer, message: str) -> bool:
    """Parse the server's response for the command "Inventory\n".

    :param TPlayer player: the player who received the message.
    :param str message: the message received from the server.

    :return bool: True if the parsing is a success, False otherwise.

    :raises ValueError: if there is a problem with the parsing.
    """
    player.last_inventory = {}
    try:
        if not message[-1] == "]":
            return False
        message = message[:-2]
        message = message[2:]
        for item in message.split(","):
            splitted_message = item.split(" ")
            splitted_message = list(filter(lambda unit: len(unit) > 0, splitted_message))
            player.last_inventory[splitted_message[0]] = int(splitted_message[1])
        print(player.last_inventory)
    except ValueError:
        return False
    return True


class Command:
    """Command class.

    Contains each command response parsing.
    And a command management system.

    Attributes:
        commands (list[str]): list of commands that the player has to send to the server.
        message_fptr (Dict[str, callable]): dictionary of functions to parse the basic server's response ("ko", "ok", "dead").
        type_fptr (Dict[str, callable]): dictionary of functions to parse broadcast protocol ("Incantation", "Response", "Confirmation", "Update", "End", "Join").
        message_saved (str): the message saved from the server. (if the message is not complete)
        start_time (float): Time to measure the execution time of a command. (start)
        end_time (float): Time to measure the execution time of a command. (end)
        time_unit (Dict[str, str]): Time to measure the execution time of a command. (end - start)

    """

    def __init__(self: TCommand):
        """Init Command Class."""
        self.commands: list[str] = []
        self.message_fptr: Dict[str, callable] = {
            "dead": self.exec_msg_dead,
            "ko": self.exec_msg_ko,
            "ok": self.exec_msg_ok,
        }
        self.type_fptr: Dict[str, callable] = {
            "Incantation": exec_type_incantation,
            "Response": exec_type_response,
            "Confirmation": exec_type_confirmation,
            "Update": exec_type_update,
            "End": exec_type_end,
            "Join": exec_type_join,
        }
        self.message_saved: str = ""
        self.start_time: float = 0.0
        self.end_time: float = 0.0
        self.time_unit: Dict[str, str] = {"exec_duration": "0.0", "Ready": "False"}

    def pop_command(self: TCommand, position: int) -> None:
        """Pop a command from the list of commands.

        Verify if the position is correct and then pop the command.

        :param int position: the position of the command to pop.
        """
        if position < 0 or position >= len(self.commands) or len(self.commands) <= 0:
            return
        self.commands.pop(position)

    def exec_msg_look(self: TCommand, player: TPlayer, message: str) -> bool:
        """Parse the server's response for the command "Look\n".

        :param TPlayer player: the player who received the message.
        :param str message: the message received from the server.

        :return bool: True if the parsing is a success, False otherwise.

        :raises ValueError: if there is a problem with the parsing.
        """
        player.last_look = []
        try:
            if not message[-1] == "]":
                return False
            message = message[:-2]
            message = message[2:]
            for item in message.split(","):
                temp_list = []
                for el in item.split(" "):
                    if len(el) > 0:
                        temp_list.append(el)
                player.last_look.append(temp_list)
            if self.time_unit["Ready"] == "True":
                old_duration: float = float(self.time_unit["exec_duration"])
                duration: float = time() - self.start_time
                self.time_unit["exec_duration"] = str(duration)
                print(f"Execution time of the command: {self.time_unit['exec_duration']}")
                self.time_unit["Ready"] = "False"
                if (old_duration / 2 > duration or duration > old_duration * 2) and old_duration != 0.0:
                    print(f"Difference between unit time")
                    if player.timer.is_alive():
                        player.timer.cancel()
                        player.timer = Timer(
                            float(self.time_unit["exec_duration"])
                            * player.incantation_levels[player.level - 1]["player"]
                            * 20,
                            player.broadcast_timeout,
                            (self.commands, float(self.time_unit["exec_duration"]), player.my_broadcast[0]),
                        )
        except ValueError:
            return False
        return True

    def exec_msg_incantation(self: TCommand, player: TPlayer, message: str, command: str) -> bool:
        """Parse the server's response for the command "Incantation\n".

        :param TPlayer player: the player who received the message.
        :param str message: the message received from the server.
        :param str command: the command to execute.

        :return bool: True if the parsing is a success, False otherwise.

        :raises ValueError: if there is a problem with the parsing.
        """
        if message == "Elevation underway":
            player.is_pursuing.update(Ready="False")
            player.is_pursuing.update(Status="False")
            player.launch_update = True
            player.inc_underway = True
            player.inc_waiting = False
            player.is_waiting = False
            player.analyzed = False
            player.broadcasted = False
            player.send_inc = False
            if command == "Incantation":
                self.pop_command(0)
        elif "Current level:" in message:
            try:
                player.level = int(message.split(" ")[2])
                player.eject_some_dudes = False
                player.your_broadcast = ""
                player.inc_underway = False
                player.analyzed = False
                player.moved = True
                player.ate = True
                remove_total_stones(player)
                if len(player.my_broadcast) > 0:
                    player.my_ending = True
            except ValueError:
                raise Exception("Incantation failed")
        else:
            return False
        return True

    def exec_msg_ko(self: TCommand, player: TPlayer, command: str) -> bool:
        """Parse the server's response when receive "ko".

        Configure the player's attributes depending on the command.
        Pop the command and return True.

        :param TPlayer player: the player who received the message.
        :param str command: the command to execute.

        :return bool: True.
        """
        player.analyzed = False
        player.moved = True
        player.ate = True
        if command == "Incantation":
            player.inc_underway = False
            player.is_waiting = False
            player.inc_waiting = False
            player.launch_update = True
            player.send_inc = False
            if len(player.my_broadcast) > 0:
                player.my_ending = True
        elif player.inc_underway:
            player.inc_underway = False
            player.is_waiting = False
            player.inc_waiting = False
            player.launch_update = True
            player.your_broadcast = ""
            player.send_inc = False
            if len(player.my_broadcast) > 0:
                player.my_ending = True
            return True
        elif command == "Broadcast incantation":
            player.timer.cancel()
            player.broadcasted = False
            player.delete_broadcast(player.my_broadcast[0], True)
        self.pop_command(0)
        return True

    def exec_msg_dead(self: TCommand, _player: TPlayer, _command: str) -> bool:
        """Parse the server's response when receive "dead".

        :param TPlayer _player: the player who received the message. (not used)
        :param str _command: the command to execute. (not used)

        :return bool: False.
        """
        self.pop_command(0)
        return False

    def exec_msg_ok(self: TCommand, player: TPlayer, command: str) -> bool:
        """Parse the server's response when receive "ok".

        Configure the player's attributes depending on the command.
        Pop the command and return True.

        :param TPlayer player: the player who received the message.
        :param str command: the command to execute.

        :return bool: True.
        """
        if "Broadcast update" == command:
            player.launch_update = True
        elif "Broadcast end" == command:
            if player.level >= 8:
                player.is_finished = True
            player.analyzed = False
            player.moved = True
            player.ate = True
        elif "Broadcast incantation" == command:
            if player.your_broadcast == "":
                print(f"Broadcast incantation with {player.my_broadcast[0]}")
                player.timer = Timer(
                    float(self.time_unit["exec_duration"]) * player.incantation_levels[player.level - 1]["player"] * 20,
                    player.broadcast_timeout,
                    (self.commands, float(self.time_unit["exec_duration"]), player.my_broadcast[0]),
                )
                player.timer.start()
                player.send_inc = True
            else:
                player.my_ending = True
        elif "Fork" == command and self.commands.count("Fork") == 1 and player.level != 8:
            player.is_forked = False
        elif "Set " in command:
            splitted_message: list[str] = command.split(" ")
            player.last_inventory[splitted_message[1]] -= 1
            player.last_look[int(splitted_message[2])].append(splitted_message[1])
        elif "Take " in command:
            splitted_message: list[str] = command.split(" ")
            player.last_inventory[splitted_message[1]] += 1
            try:
                player.last_look[int(splitted_message[2])].remove(splitted_message[1])
            except ValueError:
                pass
        self.pop_command(0)
        return True

    def exec_msg_message(self: TCommand, player: TPlayer, message: str) -> bool:
        """Parse the server's response when receive a message from broadcast.

        Add broadcast message to the broadcasted list and execute an action depending on the broadcast type.

        :param TPlayer player: the player who received the message.
        :param str message: the message received from the server.

        :return bool: True.

        :raises ValueError: if there is a problem with the parsing.
        """
        try:
            if player.is_finished:
                return True
            sub_message: list[str] = message.split(" ")
            player.add_broadcast(
                sub_message[1][0],
                sub_message[2:][0],
                sub_message[2:][1],
                sub_message[2:][2],
                sub_message[2:][3],
                " ".join(sub_message[6:]),
            )
            if sub_message[2:][3] == "Connection":
                if "Connect_nbr" not in self.commands:
                    exec_type_connection(player)
                return True
            self.type_fptr[sub_message[2:][3]](player)
        except IndexError:
            raise Exception("Parsing broadcast failed")
        return True

    def try_parse_response(self: TCommand, player: TPlayer, message: str, command: str) -> bool:
        """Try to parse the server's response.

        Test to parse response for commands:
            - Look
            - Inventory
            - Connect_nbr
            - Incantation
            - Broadcast
            - Eject

        :param TPlayer player: the player who received the message.
        :param str message: the message received from the server.
        :param str command: the command to execute.

        :return bool: True if the message was parsed, False otherwise.
        """
        return_value: bool = False

        if "message" in message:
            return self.exec_msg_message(player, message)
        if "eject:" in message:
            return True
        if self.exec_msg_incantation(player, message, command):
            return True
        if command == "Look" and return_value is False:
            return_value = self.exec_msg_look(player, message)
        elif command == "Inventory" and return_value is False:
            return_value = exec_msg_inventory(player, message)
        elif command == "Connect_nbr" and return_value is False:
            return_value = exec_msg_connect_nbr(player, message)
        if return_value is False:
            return False
        self.pop_command(0)
        return True

    def analyze_message(self: TCommand, player: TPlayer, parsed_message: list[str]) -> None:
        """Analyze the server's response.

        These functions allow the player to merge two messages if the server
        send two messages not completed.

        :param TPlayer player: the player who received the message.
        :param list[str] parsed_message: the message received from the server.
        """
        print(f"List command: {self.commands}")
        command: str = ""
        for message in parsed_message:
            if self.message_saved != "":
                message = self.message_saved + message
                self.message_saved = ""
            print("----MESSAGE----")
            try:
                command = self.commands[0]
                print(self.commands[0])
            except IndexError:
                command = "Broadcast"
            print("-->" + message)
            print("---------------")
            if len(message) == 0:
                raise Exception("Connection with server lost")
            try:
                self.message_fptr[message](player, command)
            except KeyError:
                if not self.try_parse_response(player, message, command):
                    self.message_saved += message
