from typing import Dict

player_levels: list[Dict[str, int]] = [
    {
        "player": 1,
        "linemate": 1,
        "deraumere": 0,
        "sibur": 0,
        "mendiane": 0,
        "phiras": 0,
        "thystame": 0,
    },
    {
        "player": 2,
        "linemate": 1,
        "deraumere": 1,
        "sibur": 1,
        "mendiane": 0,
        "phiras": 0,
        "thystame": 0,
    },
    {
        "player": 2,
        "linemate": 2,
        "deraumere": 0,
        "sibur": 1,
        "mendiane": 0,
        "phiras": 2,
        "thystame": 0,
    },
    {
        "player": 4,
        "linemate": 1,
        "deraumere": 1,
        "sibur": 2,
        "mendiane": 0,
        "phiras": 1,
        "thystame": 0,
    },
    {
        "player": 4,
        "linemate": 1,
        "deraumere": 2,
        "sibur": 1,
        "mendiane": 3,
        "phiras": 0,
        "thystame": 0,
    },
    {
        "player": 6,
        "linemate": 1,
        "deraumere": 2,
        "sibur": 3,
        "mendiane": 0,
        "phiras": 1,
        "thystame": 0,
    },
    {
        "player": 6,
        "linemate": 2,
        "deraumere": 2,
        "sibur": 2,
        "mendiane": 2,
        "phiras": 2,
        "thystame": 1,
    },
    {"player": 8},
]

player_movements: list[Dict[str, list[str]]] = [
    {"index": "0", "movements": ["Look"]},
    {"index": "1", "movements": ["Forward"]},
    {"index": "2", "movements": ["Left", "Forward", "Right", "Forward"]},
    {"index": "3", "movements": ["Left", "Forward"]},
    {"index": "4", "movements": ["Left", "Forward", "Left", "Forward"]},
    {"index": "5", "movements": ["Left", "Left", "Forward"]},
    {"index": "6", "movements": ["Right", "Forward", "Right", "Forward"]},
    {"index": "7", "movements": ["Right", "Forward"]},
    {"index": "8", "movements": ["Right", "Forward", "Left", "Forward"]},
]

nb_stones: Dict[str, int] = {"linemate": 9, "deraumere": 8, "sibur": 10, "mendiane": 5, "phiras": 6, "thystame": 1}

strategies_list: Dict[str, int] = {
    "Default": 50,
    "Eject": 3,
    "Materialist": 15,
    "Thrifty": 4,
    "Opportunist": 3,
    "Fool": 10,
    "Greedy": 15,
}
