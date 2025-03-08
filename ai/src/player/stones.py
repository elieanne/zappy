from __future__ import annotations
from typing import Dict, TYPE_CHECKING


if TYPE_CHECKING:
    from ai.src.player.player import TPlayer


def is_useful_stone(strategy: str, stone: str, total_stones: Dict[str, int], last_inventory: Dict[str, int]) -> bool:
    """Check if choose stone is useful for the player.

    :param str strategy: the player strategy.
    :param str stone: the stone to check.
    :param Dict[str, int] total_stones: the total stones for the player (features.py part).
    :param Dict[str, int] last_inventory: the last inventory of the player.

    :return bool: True if the stone is useful, False otherwise.
    """
    return strategy == "Materialist" or total_stones[stone] > last_inventory[stone]


def remove_total_stones(player: TPlayer) -> None:
    """Remove stones from total stones."""
    for key_object, value_object in player.incantation_levels[player.level - 2].items():
        if key_object == "player":
            continue
        player.total_stones[key_object] -= value_object
