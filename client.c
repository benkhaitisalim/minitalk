/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:58:01 by bsalim            #+#    #+#             */
/*   Updated: 2025/02/07 13:18:29 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, char bit)
{
	if (bit == 0)
		kill (pid, SIGUSR1);
	else
		kill (pid, SIGUSR2);
	usleep (100);
}

void	send_message(int pid, char *message)
{
	int	j;

	while (*message)
	{
		j = 7;
		while (j >= 0)
		{
			send_bit(pid, (*message >> j) & 1);
			j--;
		}
		message++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		while (av[1][i])
		{
			if (!ft_isdigit(av[1][i]) || pid <= 0)
			{
				write (1, "eywwwa: PID Machy hwa hadak \n", 30);
				return (1);
			}
			i++;
		}
		send_message(pid, av[2]);
	}
	else
	{
		write (1, "eywwwa: nsiti chi arg \n", 24);
	}
}
