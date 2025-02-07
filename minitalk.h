/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:38:06 by bsalim            #+#    #+#             */
/*   Updated: 2025/02/07 13:20:50 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

int		ft_atoi(char *str);
void	ft_punbr(int num );
void	handle_signals(int signal, siginfo_t *info, void *ptr);
void	send_bit(int pid, char bit);
void	send_message(int pid, char *message);
int		ft_isdigit(int c);
void	ft_check_bit(int signal, int bit_pos, unsigned char character);

#endif