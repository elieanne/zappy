from typing import Dict
from ai.src.player.player import TPlayer


def exec_type_incantation(player: TPlayer) -> None:
    """Do an action depending on the broadcast (type incantation).

    If the player has no broadcast and is ready for an incantation, he will answer OK.
    If the player has a broadcast and is ready for an incantation, he will ask the player to join him.
    If the player has no broadcast and is not ready for an incantation and in the same team, he will answer KO.

    :param TPlayer player: the player.
    """
    if (
        str(player.level) == player.broadcast_info[-1]["level"]
        and player.last_inventory["food"] >= player.food_needed
        and player.is_pursuing["Status"] == "False"
        and len(player.your_broadcast) == 0
        and player.inc_underway is False
        and player.send_inc is False
    ):
        player.my_answer = {"uuid": player.broadcast_info[-1]["uuid"], "answer": "OK"}
        player.your_broadcast = player.broadcast_info[-1]["uuid"]
    elif (
        str(player.level) == player.broadcast_info[-1]["level"]
        and player.last_inventory["food"] >= player.food_needed
        and player.is_pursuing["Status"] == "False"
        and len(player.your_broadcast) == 0
        and len(player.my_broadcast) > 0
        and player.inc_underway is False
        and player.nb_player_answer + 1 < player.incantation_levels[player.level - 1]["player"]
    ):
        player.my_join = {
            "your_uuid": player.broadcast_info[-1]["uuid"],
            "my_uuid": player.my_broadcast[0],
        }
    elif (
        player.team_name == player.broadcast_info[-1]["team"]
        and player.level <= int(player.broadcast_info[-1]["level"])
    ) or str(player.level) == player.broadcast_info[-1]["level"]:
        player.my_answer = {"uuid": player.broadcast_info[-1]["uuid"], "answer": "KO"}
    else:
        player.delete_broadcast(player.broadcast_info[-1]["uuid"], False)


def analyse_broadcast_type_response(player: TPlayer, broadcast: Dict[str, str]) -> bool:
    """Analyse broadcast response type.

    Analyse the response of another player to my broadcast.
    Count the number of player who answer OK and if it's enough, the player will send a confirmation.

    :param TPlayer player: the player.
    :param Dict[str, str] broadcast: the broadcast to analyse.
    """
    if broadcast["type"] == "Incantation":
        player.players_answer.append(
            {"team_name": player.team_name, "level": str(player.level), "answer": broadcast["option"]}
        )
        if player.broadcast_info[-1]["option"] != "OK":
            return True
        player.nb_player_answer += 1
        if (
            player.nb_player_answer + 1 >= player.incantation_levels[player.level - 1]["player"]
            and bool(player.my_confirmation) is False
            and player.is_waiting is False
            and player.last_inventory["food"] >= player.food_needed
        ):
            player.timer.cancel()
            player.my_confirmation = {"uuid": broadcast["uuid"], "confirmation": "OK"}
            player.nb_player_answer = 0
        return True
    return False


def exec_type_response(player: TPlayer) -> None:
    """Do an action depending on the broadcast (type response).

    Verify if the broadcast is in the list of my broadcast.

    :param TPlayer player: the player.
    """
    print("Response TYPE")
    if player.broadcast_info[-1]["uuid"] in player.my_broadcast:
        for broadcast in player.broadcast_info:
            if broadcast["uuid"] == player.broadcast_info[-1]["uuid"]:
                if analyse_broadcast_type_response(player, broadcast):
                    return
    else:
        player.delete_broadcast(player.broadcast_info[-1]["uuid"], False)


def exec_type_confirmation(player: TPlayer) -> None:
    """Do an action depending on the broadcast (type confirmation).

    Analyse the confirmation of another player to a broadcast.
    If the confirmation is KO, the player will delete the broadcast.
    If the confirmation is OK, the player will set the is_pursuing variable to True (so he will pursue the incantation).

    :param TPlayer player: the player.
    """
    print("Confirmation TYPE")
    if player.broadcast_info[-1]["uuid"] != player.your_broadcast:
        player.delete_broadcast(player.broadcast_info[-1]["uuid"], False)
        return
    if player.broadcast_info[-1]["option"] == "KO":
        player.inc_waiting = False
        player.delete_broadcast(player.broadcast_info[-1]["uuid"], False)
        player.your_broadcast = ""
        return
    player.is_pursuing = {
        "Status": "True",
        "Ready": "False",
        "uuid": player.broadcast_info[-1]["uuid"],
        "from_index": player.broadcast_info[-1]["from_index"],
    }
    player.inc_waiting = False


def exec_type_update(player: TPlayer) -> None:
    """Do an action depending on the broadcast (type update).

    Receive an update from another player to permit me to know in which direction I have to go.

    :param TPlayer player: the player.
    """
    print("Update TYPE")
    if player.broadcast_info[-1]["uuid"] != player.your_broadcast:
        player.delete_broadcast(player.broadcast_info[-1]["uuid"], False)
        return
    player.is_pursuing.update(from_index=player.broadcast_info[-1]["from_index"])
    player.is_pursuing.update(Ready="True")


def exec_type_end(player: TPlayer) -> None:
    """Do an action depending on the broadcast (type end).

    Receive an end from another player to permit me to know that the broadcast is finished.

    :param TPlayer player: the player.
    """
    print("End TYPE")
    if player.broadcast_info[-1]["uuid"] != player.your_broadcast:
        player.delete_broadcast(player.broadcast_info[-1]["uuid"], False)
        return
    player.is_pursuing.update(Status="False")
    player.is_pursuing.update(Ready="False")
    player.is_pursuing.update(uuid="")
    player.is_pursuing.update(from_index="-1")
    player.your_broadcast = ""
    player.analyzed = False
    player.moved = True
    player.ate = True
    if player.level >= 8:
        player.is_finished = True


def exec_type_join(player: TPlayer) -> None:
    """Do an action depending on the broadcast (type confirmation).

    Know if I join another broadcast.

    :param TPlayer player: the player.
    """
    broadcast_uuid: str = ""
    try:
        broadcast_uuid: str = player.my_broadcast[0]
    except IndexError:
        return
    if player.broadcast_info[-1]["option"] != broadcast_uuid:
        player.delete_broadcast(player.broadcast_info[-1]["uuid"], False)
        return
    print(f"I join {player.broadcast_info[-1]}")
    player.my_ending = True
    player.my_answer = {"uuid": player.broadcast_info[-1]["uuid"], "answer": "OK"}
    player.timer.cancel()
    player.your_broadcast = player.broadcast_info[-1]["uuid"]


def exec_type_connection(player: TPlayer) -> None:
    """Do an action depending on the broadcast (type connection).

    If the broadcast is a connection, increment the number of possible connection.

    :param TPlayer player: the player.
    """
    print("Connection TYPE")
    player.client_to_add += 1
