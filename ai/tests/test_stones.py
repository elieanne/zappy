import pytest
from unittest.mock import patch

from ai.src.player.stones import is_useful_stone
from ai.src.player.player import Player, TPlayer


class TestStones:
    def test_is_useful_stone_materialist(self):
        player: TPlayer = Player(-1, "team1", "")
        player.strategy = "Materialist"
        player.last_inventory = {
            "food": 1,
            "linemate": 1,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }
        player.last_look = [
            ["player", "linemate", "deraumere", "sibur", "mendiane"],
            ["linemate"],
            ["thystame"],
            ["food"],
        ]
        assert (
            is_useful_stone(player.strategy, player.last_look[0][1], player.total_stones, player.last_inventory) == True
        )

    def test_is_useful_stone_no_materialist(self):
        player: TPlayer = Player(-1, "team1", "")
        player.strategy = "Default"
        player.last_inventory = {
            "food": 1,
            "linemate": 10,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }
        player.last_look = [
            ["player", "linemate", "deraumere", "sibur", "mendiane"],
            ["linemate"],
            ["thystame"],
            ["food"],
        ]
        assert (
            is_useful_stone(player.strategy, player.last_look[0][1], player.total_stones, player.last_inventory)
            == False
        )
