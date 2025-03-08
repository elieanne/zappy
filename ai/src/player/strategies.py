from typing import Dict
from random import choices
from ai.src.player.features import strategies_list
from ai.src.utils.files import open_file


def choose_strategy(strategies: Dict[str, int], my_strategies: Dict[str, int]) -> str:
    """Randomize a strategy from strategies list.

    :param Dict[str, int] strategies: the strategies list.
    :param Dict[str, int] my_strategies: the strategies list from conf file.

    :return str: the chosen strategy.
    """
    if bool(my_strategies) is False:
        return choices([strats for strats in strategies.keys()], weights=[strat for strat in strategies.values()])[0]
    return choices([strats for strats in my_strategies.keys()], weights=[strat for strat in my_strategies.values()])[0]


def parse_conf_strategy(file: str) -> str:
    """Parse the conf file to get the strategy.

    :param str file: the conf file.
    """
    conf: str = open_file(file)
    strategies: Dict[str, int] = strategies_list
    my_strategies: Dict[str, int] = {}

    if conf == "":
        return "Default"
    for elem in conf.split("\n"):
        try:
            strategy: list[str] = elem.split(" ")
            if len(strategy) != 2 or strategy[1] != "True":
                continue
            my_strategies[strategy[0]] = strategies[strategy[0]]
        except KeyError:
            continue
    print(f"My strategies: {my_strategies}")
    return choose_strategy(strategies, my_strategies)
