from select import select
from ai.src.bot.move import move_bot
from ai.src.bot.bot import TBot
from ai.src.client.client import TClient


def send_connection(client: TClient) -> None:
    """Send a broadcast to the server to say that the player is connected.

    :param TClient client: Class Client.
    """
    client.send_message("Broadcast 0 " + client.name + " 1 " + "Connection", "Broadcast connection", True)


def launch_connection(bot: TBot) -> int:
    """Main loop.

    Handle send and receive messages.

    :param TBot bot: Class Bot.

    :return int: 0 if the player is dead.
    """
    sockets = [bot.client.socket]
    parsed_message: list[str] = []

    while True:
        read_sockets, write_sockets, exception_sockets = select(sockets, sockets, [])
        for sock in read_sockets:
            if sock is sockets[0]:
                parsed_message = bot.client.receive_message()
                if "dead" in parsed_message:
                    print(f"You are dead!")
                    bot.player.timer.cancel()
                    return 0
                else:
                    bot.client.command.analyze_message(bot.player, parsed_message)
        if not bot.client.connected["Connected"]:
            continue
        elif bot.client.connected["Connected"] and bot.client.connected["Food"]:
            bot.client.connected["Food"] = False
            bot.calculate_food()
            send_connection(bot.client)
        for sock in write_sockets:
            if sock is sockets[0]:
                move_bot(bot)
