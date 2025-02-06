/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:11:22 by bsalim            #+#    #+#             */
/*   Updated: 2025/02/06 22:32:09 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signals(int signal, siginfo_t *info, void *ptr)
{
	static unsigned char	character;
	static int				bit_pos;
	static int				valid_pid;

	valid_pid = 0;
	bit_pos = 0;
	character = 0;
	(void)ptr;
	if (!valid_pid)
		valid_pid = info->si_pid;
	if (info->si_pid != valid_pid)
	{
		valid_pid = info->si_pid;
		bit_pos = 0;
	}
	if (signal == SIGUSR1)
		character &= ~(1 << (7 - bit_pos));
	else if (signal == SIGUSR2)
		character |= (1 << (7 - bit_pos));
	bit_pos++;
	if (bit_pos == 8) 
		write(1, &character, 1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_signals;
	pid = getpid();
	ft_punbr (pid);
	write (1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause(); 
}
