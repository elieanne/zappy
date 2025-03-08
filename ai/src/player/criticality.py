from __future__ import annotations
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from ai.src.client.client import TClient


def get_movements_to_tiles(tile: int) -> list[int]:
    """Returns the number of movements x and y to go on the tile where is the nearest food.

    :param int tile: Number of the tile where is the nearest food.

    :return list[int]: x number of movements to do and y number of movements to do.
    """
    left_order = [[1, 5, 11], [-1, 4, 10], [-1, -1, 9]]
    right_order = [[3, 7, 13], [-1, 8, 14], [-1, -1, 15]]

    for i in range(3):
        for j in range(3):
            if left_order[i][j] == tile or right_order[i][j] == tile:
                return [i + 1, j + 1]
    return [-1, -1]


def where_is_the_food(last_look: list[list[str]]) -> int:
    """Returns the index of the tile where is the nearest food, depending on a specific order.

    :param list[list[str]] last_look: Variable "Look" from the last turn.

    :return int: the index of the tile where is the nearest food.
    """
    last_moves_order: list[list[int]] = [
        [0, 2, 6, 12],
        [1, 5, 11, 3, 7, 13],
        [4, 10, 8, 14],
        [9, 15],
    ]

    for list_elem in last_moves_order:
        for elem in list_elem:
            if elem >= len(last_look):
                continue
            if "food" in last_look[elem]:
                return elem
    return 2


def go_to_tile(client: TClient, tile: int) -> None:
    """Send the right requests to the server to move the player where is the nearest food.

    :param TClient client: Class Client (handle the connection with the server).
    :param int tile: the index of the tile where is the nearest food.
    """
    left_tiles = [1, 5, 11, 4, 10, 9]
    right_tiles = [3, 7, 13, 8, 14, 15]
    middle_tiles = [0, 2, 6, 12]

    if tile in left_tiles and len(client.command.commands) < 10:
        client.send_message("Left", "Left", True)
        movements = get_movements_to_tiles(tile)
        for i in range(movements[0]):
            if len(client.command.commands) >= 10:
                return
            client.send_message("Forward", "Forward", True)
        if len(client.command.commands) >= 10:
            return
        client.send_message("Right", "Right", True)
        for i in range(movements[1]):
            if len(client.command.commands) >= 10:
                return
            client.send_message("Forward", "Forward", True)
    elif tile in right_tiles and len(client.command.commands) < 10:
        client.send_message("Right", "Right", True)
        movements = get_movements_to_tiles(tile)
        for i in range(movements[0]):
            if len(client.command.commands) >= 10:
                return
            client.send_message("Forward", "Forward", True)
        if len(client.command.commands) >= 10:
            return
        client.send_message("Left", "Left", True)
        for i in range(movements[1]):
            if len(client.command.commands) >= 10:
                return
            client.send_message("Forward", "Forward", True)
    elif tile in middle_tiles and len(client.command.commands) < 10:
        nb_movements = middle_tiles.index(tile)
        for i in range(nb_movements):
            if len(client.command.commands) >= 10:
                return
            client.send_message("Forward", "Forward", True)
