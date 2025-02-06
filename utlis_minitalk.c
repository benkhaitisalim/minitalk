/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_minitalk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:16:35 by bsalim            #+#    #+#             */
/*   Updated: 2025/02/06 19:11:38 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"
#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;
    while (str[i] < 32)
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
        {
            sign *= -1;
            i++;
        }
        else  
            i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
void ft_putchar(int c)
{
    write(1,&c,1);
}
void ft_punbr(int num )
{
    if(num > 9)
    {
        ft_punbr(num / 10);
    }
    ft_putchar((num % 10 ) + '0');
}
int ft_isdigit(int c)
{
    if(c >= '0' && c <= '9')
    {
        return 1;
    }
    else {
     return 0;
    }
}