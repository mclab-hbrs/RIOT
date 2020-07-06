/*
 * Copyright (C) 2015 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Example application for demonstrating the RIOT network stack
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 * @}
 */

#include <stdio.h>
#include "shell.h"

extern int tcp6_cmd(int argc, char **argv);
extern void tcp6_init(void);

static const shell_command_t shell_commands[] = {
    { "tcp6-send", "Send a TCP nessage via IPv6.", tcp6_cmd},
    { NULL, NULL, NULL }
};


int main(void)
{
    puts("RIOT LWIP TCP/IPv6 example application");
    tcp6_init();

    /* start shell */
    puts("All up, running the shell now");
    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

    /* should be never reached */
    return 0;
}
