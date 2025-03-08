/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** signal_handler.c
*/

#include "zappy_server.h"
#include <signal.h>

static bool sig_continue = true;

bool can_continue(void)
{
    return sig_continue;
}

void handle_signal(int sig, siginfo_t *si, void *unused)
{
    (void) sig;
    (void) unused;
    if (si->si_signo == SIGINT || si->si_signo == SIGQUIT)
        sig_continue = false;
}

void check_stdin(void)
{
    int c = 0;
    if (feof(stdin))
        sig_continue = false;
    c = getc(stdin);
    if (c == EOF)
        sig_continue = false;
    ungetc(c, stdin);
}

int get_signal(void)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = &handle_signal;
    sigaction(SIGQUIT, &sa, NULL);
    sigaction(SIGINT, &sa, NULL);
    return 1;
}
