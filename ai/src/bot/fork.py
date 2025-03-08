from typing import Dict


def add_player(key: str, nb: int, nb_players: Dict[str, int]) -> None:
    """Add a player to the nb_players dict.

    :param key: the key of the player.
    :param nb: the number of player to add.
    :param nb_players: the nb_players dict.
    """
    nb_players[key] += nb


def update_players(nb_players: Dict[str, int], my_level: str) -> None:
    """Update the nb_players dict with good number of players.

    :param nb_players: the nb_players dict.
    :param my_level: the level of the player.
    """
    for key, value in nb_players.items():
        if key == "Ready":
            continue
        if key == "1" and value == 1:
            add_player("1", -1, nb_players)
            add_player("2", 1, nb_players)
        elif key == "2" and value == 2:
            add_player("2", -2, nb_players)
            add_player("4", 2, nb_players)
        elif key == "3" and value == 2:
            add_player("3", -2, nb_players)
            add_player("4", -2, nb_players)
        elif key == "4" and value == 4:
            add_player("4", -4, nb_players)
            add_player("6", 4, nb_players)
        elif key == "5" and value == 4:
            add_player("5", -4, nb_players)
            add_player("6", 4, nb_players)
        elif key == "6" and value == 6:
            add_player("6", -6, nb_players)
            add_player("8", 6, nb_players)
    add_player("Ready", int(nb_players[my_level]), nb_players)
    add_player(str(my_level), -int(nb_players[my_level]), nb_players)


def calculate_nb_fork(nb_players: Dict[str, int], my_level: str, needed_player: int) -> float:
    """Calculate the number of fork needed to level up.

    :param nb_players: The nb_players dict.
    :param my_level: The level of the player.
    :param needed_player: The number of player needed to level up.

    :return: The number of fork needed to level up.
    """
    player_weight: Dict[str, int] = {"1": 1, "2": 1, "3": 2, "4": 2, "5": 4, "6": 4, "7": 8, "8": 8}
    nb_fork: int = player_weight[my_level] * (needed_player - nb_players["Ready"])
    for key, value in nb_players.items():
        if key == "Ready":
            continue
        nb_fork -= value * player_weight[key]
    return nb_fork / 2
