#ifndef FT_MINITALK_F
#define FT_MINITALK_F
#include <signal.h>
#include <unistd.h>

int     ft_atoi(char *str);
void    ft_punbr(int num );
void	handle_signals(int signal,siginfo_t *info, void *ptr);
void    send_bit(int pid, char bit);
void    send_message(int pid, char *message);
void    ft_recive_sig_bonus(int signal);
int     ft_isdigit(int c);

#endif