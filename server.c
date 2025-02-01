/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:11:22 by bsalim            #+#    #+#             */
/*   Updated: 2025/02/01 20:35:31 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signals(int signal)
{
	static unsigned char	character = 0;
	static int				bit_pos = 0;

	if (signal == SIGUSR1)
		character &= ~(1 << (7 - bit_pos)); 
	else if (signal == SIGUSR2)
		character |= (1 << (7 - bit_pos));  

	bit_pos++;

	if (bit_pos == 8) 
	{
		write(1, &character, 1);
		if (character == '\0') 
			write(1, "\n", 1);
		character = 0;
		bit_pos = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);

	signal(SIGUSR1, handle_signals);
	signal(SIGUSR2, handle_signals);

	while (1)
		pause(); 
}
