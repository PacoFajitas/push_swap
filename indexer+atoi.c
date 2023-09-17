/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer+atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:26:46 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/15 01:45:50 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	ft_index(t_struct *aha)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < aha->len)
	{
		j = 0;
		k = 1;
		while (j < aha->len)
		{
			if (aha->stackaux[i] > aha->stackaux[j])
				k++;
			else if (i != j && aha->stackaux[i] == aha->stackaux[j])
			{
				ft_free_struct(aha);
				ft_error();
			}
			j++;
		}
		aha->stacka[i] = k;
		i++;
	}
}

int	ft_atoi(const char	*str, t_struct *a)
{
	long long int	ret;
	int				sign;

	sign = 1;
	ret = 0;
	a->flag_error = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -sign;
		}
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = (ret * 10) + *str - '0';
		str ++;
	}
	if ((ret * sign) > (long long int)2147483647
		|| (ret * sign) < (long long int)-2147483648)
		a->flag_error = 1;
	return (ret * sign);
}
