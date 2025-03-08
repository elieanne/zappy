import pytest
from unittest.mock import patch

from ai.src.player.player import Player, TPlayer
from ai.src.player.criticality import get_movements_to_tiles, where_is_the_food, go_to_tile

from ai.src.command.command import Command, TCommand


class TestPlayer:
    # Test to get [1, 1] so the player move to the left
    def test_get_movements_to_tiles_left(self):
        assert get_movements_to_tiles(1) == [1, 1]

    # Test to get [1, 1] so the player move to the right
    def test_get_movements_to_tiles_right(self):
        assert get_movements_to_tiles(1) == [1, 1]

    # Test to get [-1, -1] so the player move nowhere
    def test_get_movements_to_tiles_none(self):
        assert get_movements_to_tiles(20) == [-1, -1]

    # Test to get the tile number that contains the nearest food (index 0)
    def test_where_is_the_food_on_my_place(self):
        last_look: list[list[str]] = [
            ["player", "linemate", "deraumere", "sibur", "mendiane", "food"],
            ["linemate"],
            ["thystame"],
            ["food"],
        ]
        assert where_is_the_food(last_look) == 0

    # Test to get the tile number that contains the nearest food (index 2)
    def test_where_is_the_food_forward(self):
        last_look: list[list[str]] = [
            ["player", "linemate", "deraumere", "sibur", "mendiane"],
            ["linemate"],
            ["thystame", "food"],
            ["food"],
        ]
        assert where_is_the_food(last_look) == 2

    # Test to get the tile number that contains the nearest food (index 3)
    def test_where_is_the_food_to_right(self):
        last_look: list[list[str]] = [
            ["player", "linemate", "deraumere", "sibur", "mendiane"],
            ["linemate"],
            ["thystame"],
            ["food"],
        ]
        assert where_is_the_food(last_look) == 3

    # Test to get the tile number that contains the nearest food (index None)
    def test_where_is_the_food_no_where(self):
        last_look: list[list[str]] = [
            ["player", "linemate", "deraumere", "sibur", "mendiane"],
            ["linemate"],
            ["thystame"],
            [],
        ]
        assert where_is_the_food(last_look) == 2

    # def test_go_to_forward_tile(self):
    #     client: TClient = Client(4242, "team1", "localhost")

    # def test_delete_broadcast_mine(self):
    #     player: TPlayer = Player(-1, "team1", "")
    #     player.my_broadcast.append("c1489bd9-94e7-4c34-a403-b91754504216")
    #     player.delete_broadcast("c1489bd9-94e7-4c34-a403-b91754504216", True)
    #     assert player.my_broadcast == []

    # Test stop wating function
    def test_stop_waiting(self):
        player: TPlayer = Player(-1, "team1", "")
        player.my_broadcast.append("c1489bd9-94e7-4c34-a403-b91754504216")
        player.nb_player_answer == 1
        player.broadcasted == True
        assert player.is_waiting == False
        assert player.my_broadcast == []
        assert player.nb_player_answer == 0
        assert player.broadcasted == False

    # Test broadcast timeout function if "Broadcast join" in commands
    def test_broadcast_timeout_join(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        command.commands = ["Broadcast join"]
        player.broadcast_timeout(command.commands, 1, "c1489bd9-94e7-4c34-a403-b91754504216")
        player.timer.cancel()

    # Test broadcast timeout function if nothing in commands
    def test_broadcast_timeout_none(self):
        command: TCommand = Command()
        player: TPlayer = Player(-1, "team1", "")
        player.broadcast_timeout(command.commands, 1, "c1489bd9-94e7-4c34-a403-b91754504216")
        assert player.my_confirmation == {}
        assert player.nb_player_answer == 0
        assert player.is_waiting == False
        assert player.my_ending == True
        assert player.broadcasted == False
