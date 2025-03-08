from ai.src.bot.bot import TBot


def move_bot(bot: TBot) -> None:
    """Main algorithm of the player.

    Args:
        bot (TBot): Bot Class
    """
    if bot.player.level == 8 and bot.player.timer.is_alive() is False and bot.player.is_forked is False:
        print("Set timer for the fork...")
        bot.client.send_message("Fork", "Fork", True)
        bot.player.is_forked = True
    bot.analyse_command()
    if bot.player.level < 8:
        if bot.interact_with_players():
            return
    bot.analyse_environment()
