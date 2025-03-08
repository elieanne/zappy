import pytest
from unittest.mock import patch

from ai.src.command.command import Command, TCommand, exec_msg_connect_nbr, exec_msg_inventory
from ai.src.command.exec_type import (
    exec_type_incantation,
    analyse_broadcast_type_response,
    exec_type_response,
    exec_type_confirmation,
    exec_type_update,
    exec_type_end,
    exec_type_join,
    exec_type_connection,
)
from ai.src.player.player import Player, TPlayer


class TestExecMsgConnectNbr:
    # Test exec_msg_connect_nbr, set to 1
    def test_exec_msg_connect_nbr(self):
        player: TPlayer = Player(0, "team1", "")
        assert player.connect_nbr == 0
        message: str = "1"
        assert exec_msg_connect_nbr(player, message) == True
        assert player.connect_nbr == 1

    # Test exec_msg_connect_nbr, set to 0
    def test_exec_msg_connect_nbr_2(self):
        player: TPlayer = Player(0, "team1", "")
        assert player.connect_nbr == 0
        message: str = "0"
        assert exec_msg_connect_nbr(player, message) == True
        assert player.connect_nbr == 0

    # Wrong args on exec_msg_connect_nbr
    def test_failed_exec_msg_connect_nbr(self):
        player: TPlayer = Player(1, "team1", "")
        assert player.connect_nbr == 1
        message: str = "test"
        assert exec_msg_connect_nbr(player, message) == False
        assert player.connect_nbr == 1


class TestExecMsgInventory:
    # Test exec_msg_inventory
    def test_exec_msg_inventory(self):
        player: TPlayer = Player(-1, "team1", "")
        assert player.last_inventory == {}
        message: str = "[ food 1, linemate 1, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0 ]"
        assert exec_msg_inventory(player, message) == True
        assert player.last_inventory == {
            "food": 1,
            "linemate": 1,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }

    # Test exec_msg_inventory 2
    def test_exec_msg_inventory_2(self):
        player: TPlayer = Player(-1, "team1", "")
        assert player.last_inventory == {}
        message: str = "[ food 15, linemate 2, deraumere 0, sibur 2, mendiane 0, phiras 2, thystame 0 ]"
        assert exec_msg_inventory(player, message) == True
        assert player.last_inventory == {
            "food": 15,
            "linemate": 2,
            "deraumere": 0,
            "sibur": 2,
            "mendiane": 0,
            "phiras": 2,
            "thystame": 0,
        }

    # Test if message not completed
    def test_half_exec_msg_inventory(self):
        player: TPlayer = Player(-1, "team1", "")
        assert player.last_inventory == {}
        message: str = "[ food 15, linemate 2, deraumere 0, sibur 2, mendiane 0, phiras 2, thystame 0"
        assert exec_msg_inventory(player, message) == False
        assert player.last_inventory == {}


class TestCommand:
    # Pop command (pop first element)
    def test_pop_command(self):
        command: TCommand = Command()
        command.commands = ["Forward", "Left", "Right"]
        command.pop_command(0)
        assert command.commands == ["Left", "Right"]

    # Pop command (wrong index)
    def test_wrong_pop_command(self):
        command: TCommand = Command()
        command.commands = ["Forward", "Left", "Right"]
        command.pop_command(-1)
        assert command.commands == ["Forward", "Left", "Right"]

    # Pop command (pop first element)
    def test_wrong_pop_command_2(self):
        command: TCommand = Command()
        command.commands = ["Forward", "Left", "Right"]
        command.pop_command(3)
        assert command.commands == ["Forward", "Left", "Right"]

    # Pop empty command list
    def test_wrong_pop_command_2(self):
        command: TCommand = Command()
        command.pop_command(0)
        assert command.commands == []

    # Parse the message returned by "Look"
    def test_exec_msg_look(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "[ player linemate deraumere sibur mendiane, linemate, thystame, food ]"
        assert command.exec_msg_look(player, message) == True
        assert player.last_look == [
            ["player", "linemate", "deraumere", "sibur", "mendiane"],
            ["linemate"],
            ["thystame"],
            ["food"],
        ]

    # Failed to parse the message returned by "Look"
    def test_exec_msg_look_2(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "[ player linemate deraumere sibur mendiane, linemate, thystame, food"
        assert command.exec_msg_look(player, message) == False
        assert player.last_look == []

    # Parse the message returned by "Incantation"
    def test_exec_msg_incantation(self):
        command: TCommand = Command()
        command.commands = ["Incantation"]
        player: TPlayer = Player(-1, "team1", "")
        message: str = "Elevation underway"
        assert command.exec_msg_incantation(player, message, "Incantation") == True
        assert player.launch_update == True
        assert player.inc_underway == True
        assert player.inc_waiting == False
        assert player.is_waiting == False
        assert player.analyzed == False
        assert player.broadcasted == False
        assert player.send_inc == False
        assert command.commands == []

    # Parse the 2nd message returned by "Incantation"
    def test_exec_msg_incantation_2(self):
        command: TCommand = Command()
        command.commands = ["Incantation"]
        player: TPlayer = Player(-1, "team1", "")
        message: str = "Current level: 2"
        assert command.exec_msg_incantation(player, message, "Current level:") == True
        assert player.your_broadcast == ""
        assert player.level == int(message.split(" ")[2])
        assert player.inc_underway == False
        assert player.analyzed == False
        assert player.moved == True
        assert player.ate == True

    # Parse the 2nd message returned by "Incantation" with broadcast
    def test_exec_msg_incantation_3(self):
        command: TCommand = Command()
        command.commands = ["Incantation"]
        player: TPlayer = Player(-1, "team1", "")
        message: str = "Current level: 2"
        player.my_broadcast: list[str] = ["Broadcast 3d62496f-fd63-4868-b212-5c00243c7ae9 team1 2 Incantation"]
        assert command.exec_msg_incantation(player, message, "Current level:") == True
        assert player.your_broadcast == ""
        assert player.level == int(message.split(" ")[2])
        assert player.inc_underway == False
        assert player.analyzed == False
        assert player.moved == True
        assert player.ate == True

    # Parse the "ko" message during incantation
    def test_exec_msg_ko(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "ko"
        player.my_broadcast: list[str] = ["Broadcast 3d62496f-fd63-4868-b212-5c00243c7ae9 team1 2 Incantation"]
        player.inc_underway: bool = True
        assert command.exec_msg_ko(player, message) == True
        assert player.inc_underway == False
        assert player.is_waiting == False
        assert player.inc_waiting == False
        assert player.launch_update == True
        assert player.your_broadcast == ""
        assert player.send_inc == False

    # Parse the "ko" message before launching incantation
    def test_exec_msg_ko_2(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "Incantation"
        player.my_broadcast: list[str] = ["Broadcast 3d62496f-fd63-4868-b212-5c00243c7ae9 team1 2 Incantation"]
        player.inc_underway: bool = False
        assert command.exec_msg_ko(player, message) == True
        assert player.inc_underway == False
        assert player.is_waiting == False
        assert player.inc_waiting == False
        assert player.launch_update == True
        assert player.send_inc == False

    # Parse the "ko" message when broadcast
    def test_exec_msg_ko_3(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "Broadcast incantation"
        player.my_broadcast: list[str] = ["Broadcast 3d62496f-fd63-4868-b212-5c00243c7ae9 team1 2 Incantation"]
        player.inc_underway: bool = False
        assert command.exec_msg_ko(player, message) == True
        assert player.broadcasted == False
        # assert player.wait_response == False

    # Parse the "dead" message
    def test_exec_msg_dead(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "dead"
        assert command.exec_msg_dead(player, message) == False

    # Parse the "ok" message when broadcast update
    def test_exec_msg_ok_broadcast_update(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        command.commands = ["Broadcast ..."]
        message: str = "Broadcast update"
        assert command.exec_msg_ok(player, message) == True
        assert player.launch_update == True
        assert command.commands == []

    # Parse the "ok" message when broadcast incantation
    def test_exec_msg_ok_broadcast_incantation(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        player.my_broadcast: list[str] = ["Broadcast 3d62496f-fd63-4868-b212-5c00243c7ae9 team1 2 Incantation"]
        command.commands = ["Broadcast ..."]
        message: str = "Broadcast incantation"
        assert command.exec_msg_ok(player, message) == True
        assert player.send_inc == True
        assert command.commands == []

    # Parse the "ok" message when broadcast incantation with your broadcast
    def test_exec_msg_ok_broadcast_incantation_2(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        player.my_broadcast: list[str] = ["Broadcast 3d62496f-fd63-4868-b212-5c00243c7ae9 team1 2 Incantation"]
        player.your_broadcast = "Broadcast 3d62496f-fd63-4868-b212-5c00243c7ae9 team1 2 Incantation"
        command.commands = ["Broadcast ..."]
        message: str = "Broadcast incantation"
        assert command.exec_msg_ok(player, message) == True
        assert player.my_ending == True
        assert command.commands == []

    # Parse the "ok" message when Set an object
    def test_exec_msg_ok_set(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        player.last_look = [
            ["player", "linemate", "deraumere", "sibur", "mendiane"],
            ["linemate"],
            ["thystame"],
            ["food"],
        ]
        player.last_inventory = {
            "food": 0,
            "linemate": 1,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }
        command.commands = ["Set linemate 0"]
        message: str = "Set linemate 0"
        assert command.exec_msg_ok(player, message) == True
        assert player.last_inventory["linemate"] == 0
        assert command.commands == []

    # Parse the "ok" message when Take an object
    def test_exec_msg_ok_take(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        player.last_look = [
            ["player", "linemate", "deraumere", "sibur", "mendiane"],
            ["linemate"],
            ["thystame"],
            ["food"],
        ]
        player.last_inventory = {
            "food": 0,
            "linemate": 1,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }
        command.commands = ["Take linemate 0"]
        message: str = "Take linemate 0"
        assert command.exec_msg_ok(player, message) == True
        assert player.last_inventory["linemate"] == 2
        assert command.commands == []

    # Parse a message from same team get from a broadcast
    def test_exec_msg_message(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Incantation"
        assert command.exec_msg_message(player, message) == True
        assert player.my_answer == {"uuid": "c1489bd9-94e7-4c34-a403-b91754504216", "answer": "KO"}

    # Parse a message get from a broadcast
    def test_exec_msg_message_same_team(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team2 2 Incantation"
        assert command.exec_msg_message(player, message) == True
        assert player.broadcast_info == []

    # Test try_parse_response method (message command)
    def test_try_parse_response_message(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Incantation"
        assert command.try_parse_response(player, message, "") == True

    # Test try_parse_response method (Look command)
    def test_try_parse_response_look(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "[ player linemate deraumere sibur mendiane, linemate, thystame, food ]"
        assert command.try_parse_response(player, message, "Look") == True

    # Test try_parse_response method (Inventory command)
    def test_try_parse_response_inventory(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "[ food 15, linemate 2, deraumere 0, sibur 2, mendiane 0, phiras 2, thystame 0 ]"
        assert command.try_parse_response(player, message, "Inventory") == True

    # Test try_parse_response method (Connect_nbr command)
    def test_try_parse_response_connect_nbr(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "0"
        assert command.try_parse_response(player, message, "Connect_nbr") == True

    # Test try_parse_response method (Connect_nbr command)
    def test_try_parse_response_incantation(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "Elevation underway"
        assert command.try_parse_response(player, message, "") == True

    # Test try_parse_response method (wrong Connect_nbr parsing)
    def test_try_parse_response_connect_nbr_failed(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "0"
        assert command.try_parse_response(player, message, "Look") == False

    # Test to parse a Look command response divided in two messages
    def test_analyze_message(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        command.commands = ["Look"]
        message_list: list[str] = ["[ player linemate deraumere sibur mendiane,", " linemate, thystame, food ]"]
        command.analyze_message(player, message_list)
        assert player.last_look == [
            ["player", "linemate", "deraumere", "sibur", "mendiane"],
            ["linemate"],
            ["thystame"],
            ["food"],
        ]

    # Test to parse a divided message
    def test_analyze_message(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        command.commands = []
        message_list: list[str] = ["message 8, c1489bd9-94e7-4c34-a403-b91754504216 team2 2 Incantation"]
        command.analyze_message(player, message_list)
        assert player.broadcast_info == []


class TestExecType:
    # Test exec_type method (Incantation command)
    def test_exec_type_incantation(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        player.last_inventory = {
            "food": 20,
            "linemate": 1,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Incantation"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.level = 2
        exec_type_incantation(player)
        assert player.my_answer == {"uuid": "c1489bd9-94e7-4c34-a403-b91754504216", "answer": "OK"}
        assert player.your_broadcast == "c1489bd9-94e7-4c34-a403-b91754504216"

        # Test exec_type method (Incantation command) other case

    def test_exec_type_incantation_2(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        player.last_inventory = {
            "food": 20,
            "linemate": 1,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Incantation"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.level = 2
        player.send_inc = True
        player.my_broadcast.append("39695e1a-0af9-11ee-be56-0242ac120002")
        exec_type_incantation(player)
        assert player.my_join == {
            "your_uuid": "c1489bd9-94e7-4c34-a403-b91754504216",
            "my_uuid": "39695e1a-0af9-11ee-be56-0242ac120002",
        }

    # Test exec_type method (Incantation command) same team
    def test_exec_type_incantation_same_team(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Incantation"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        exec_type_incantation(player)
        assert player.my_answer == {"uuid": "c1489bd9-94e7-4c34-a403-b91754504216", "answer": "KO"}

    # Test exec_type method (Incantation command) other case
    def test_exec_type_incantation_differents_team(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team2 2 Incantation"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        exec_type_incantation(player)
        assert player.broadcast_info == []

    # Test analyse_broadcast_type_response method (Search type)
    def test_analyse_broadcast_type_response_search(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Search"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        assert analyse_broadcast_type_response(player, player.broadcast_info[-1]) == True

    # Test analyse_broadcast_type_response method (Incantation type)
    def test_analyse_broadcast_type_response_incantation(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        player.last_inventory = {
            "food": 20,
            "linemate": 1,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Incantation OK"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.level = 2
        player.nb_player_answer = 1
        player.is_waiting = False
        analyse_broadcast_type_response(player, player.broadcast_info[-1])
        assert player.my_confirmation == {"uuid": "c1489bd9-94e7-4c34-a403-b91754504216", "confirmation": "OK"}
        assert player.nb_player_answer == 0

    # Test analyse_broadcast_type_response method (Update type)
    def test_analyse_broadcast_type_response_update(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        player.last_inventory = {
            "food": 20,
            "linemate": 1,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Update"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.level = 2
        player.nb_player_answer = 1
        player.is_waiting = False
        assert analyse_broadcast_type_response(player, player.broadcast_info[-1]) == False

    # Test if message uuid is in my_broadcast list (it's not)
    def test_exec_type_response_it_is_not(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Response"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.my_broadcast.append("39695e1a-0af9-11ee-be56-0242ac120002")
        exec_type_response(player)
        assert player.broadcast_info == []

    # Test if message uuid is in my_broadcast list (it is)
    def test_exec_type_response_it_is(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        player.last_inventory = {
            "food": 20,
            "linemate": 1,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Incantation"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.my_broadcast.append("c1489bd9-94e7-4c34-a403-b91754504216")
        exec_type_response(player)
        assert player.broadcast_info != []

    # Test if the broadcast sender is in my "your_broadcast" variable
    def test_exec_type_confirmation_not(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Confirmation OK"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.your_broadcast = "39695e1a-0af9-11ee-be56-0242ac120002"
        exec_type_confirmation(player)
        assert player.broadcast_info == []

    # Test if the broadcast sender is in my "your_broadcast" variable (it is) but "ko"
    def test_exec_type_confirmation_it_is_and_ko(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Confirmation KO"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.your_broadcast = "c1489bd9-94e7-4c34-a403-b91754504216"
        exec_type_confirmation(player)
        assert player.inc_waiting == False
        assert player.broadcast_info == []
        assert player.your_broadcast == ""

    # Test if the broadcast sender is in my "your_broadcast" variable (it is) and "ok"
    def test_exec_type_confirmation_it_is_and_ok(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Confirmation OK"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.your_broadcast = "c1489bd9-94e7-4c34-a403-b91754504216"
        exec_type_confirmation(player)
        assert player.broadcast_info != []
        assert player.is_pursuing == {
            "Status": "True",
            "Ready": "False",
            "uuid": "c1489bd9-94e7-4c34-a403-b91754504216",
            "from_index": "8",
        }
        assert player.inc_waiting == False

    # Test if the broadcast sender is different from my "your_broadcast" variable
    def test_exec_type_update_different_uuid(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Update"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.your_broadcast = "39695e1a-0af9-11ee-be56-0242ac120002"
        exec_type_update(player)
        assert player.broadcast_info == []

    # Test if the broadcast sender is different from my "your_broadcast" variable
    def test_exec_type_update_same_uuid(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Update"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.your_broadcast = "c1489bd9-94e7-4c34-a403-b91754504216"
        exec_type_update(player)
        assert player.is_pursuing == {
            "Status": "False",
            "Ready": "True",
            "from_index": "8",
        }

    # Test if the broadcast sender is different from my "your_broadcast" variable
    def test_exec_type_end_different_uuid(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 End"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.your_broadcast = "39695e1a-0af9-11ee-be56-0242ac120002"
        exec_type_end(player)
        assert player.broadcast_info == []

    # Test if the broadcast sender is different from my "your_broadcast" variable
    def test_exec_type_end_same_uuid(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 End"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.your_broadcast = "c1489bd9-94e7-4c34-a403-b91754504216"
        exec_type_end(player)
        assert player.is_pursuing == {
            "Status": "False",
            "Ready": "False",
            "uuid": "",
            "from_index": "-1",
        }
        assert player.your_broadcast == ""
        assert player.analyzed == False
        assert player.moved == True
        assert player.ate == True

    # Test if current player has level 8
    def test_exec_type_end_last_level(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 End"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.your_broadcast = "c1489bd9-94e7-4c34-a403-b91754504216"
        player.level = 8
        exec_type_end(player)
        assert player.is_pursuing == {
            "Status": "False",
            "Ready": "False",
            "uuid": "",
            "from_index": "-1",
        }
        assert player.your_broadcast == ""
        assert player.analyzed == False
        assert player.moved == True
        assert player.ate == True
        assert player.is_finished == True

    # Test if the broadcast sender is different from my "your_broadcast" variable
    def test_exec_type_join_different_uuid(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Elevation"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.broadcast_info[-1]["option"] = "c1489bd9-94e7-4c34-a403-b91754504216"
        player.my_broadcast.append("39695e1a-0af9-11ee-be56-0242ac120002")
        exec_type_join(player)
        assert player.broadcast_info == []

    # Test if the broadcast sender is different from my "your_broadcast" variable
    def test_exec_type_join_same_uuid(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Elevation"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        player.broadcast_info[-1]["option"] = "c1489bd9-94e7-4c34-a403-b91754504216"
        player.my_broadcast.append("c1489bd9-94e7-4c34-a403-b91754504216")
        exec_type_join(player)
        assert player.my_ending == True
        assert player.my_answer == {"uuid": "c1489bd9-94e7-4c34-a403-b91754504216", "answer": "OK"}
        assert player.your_broadcast == "c1489bd9-94e7-4c34-a403-b91754504216"

    # Test if the broadcast sender is different from my "your_broadcast" variable
    def test_exec_type_join_no_uuid(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        message: str = "message 8, c1489bd9-94e7-4c34-a403-b91754504216 team1 2 Elevation"
        sub_message: list[str] = message.split(" ")
        player.add_broadcast(
            sub_message[1][0],
            sub_message[2:][0],
            sub_message[2:][1],
            sub_message[2:][2],
            sub_message[2:][3],
            " ".join(sub_message[6:]),
        )
        exec_type_join(player)

    # Test to add a "client_to_add" to the player
    def test_exec_type_connection(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        exec_type_connection(player)
        assert player.client_to_add == 1
