/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_minitalk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:16:35 by bsalim            #+#    #+#             */
/*   Updated: 2025/02/01 20:35:15 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

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