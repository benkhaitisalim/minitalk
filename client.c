/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:58:01 by bsalim            #+#    #+#             */
/*   Updated: 2025/02/01 20:36:43 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

void send_bit(int pid, char bit)
{
    if (bit == 0)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    usleep(100); // Delay to ensure server processes the signal
}

void send_message(int pid, char *message)
{
    while (*message)
    {
        int j = 7;
        while (j >= 0)
        {
            send_bit(pid, (*message >> j) & 1);
            j--;
        }
        message++;
    }

    // Send null character '\0' to indicate end of message
    int i = 7;
    while (i >= 0)
    {
        send_bit(pid, ('\0' >> i) & 1);
        i--;
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        ft_printf("Usage: %s <PID> <Message>\n", av[0]);
        return 1;
    }

    int pid = ft_atoi(av[1]);
    if (pid <= 0)
    {
        ft_printf("Error: Invalid PID\n");
        return 1;
    }

    send_message(pid, av[2]);

    return 0;
}
