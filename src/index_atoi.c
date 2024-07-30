/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:26:46 by tfiguero          #+#    #+#             */
/*   Updated: 2024/07/30 18:18:07 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_atoi_ps(const char	*str, t_struct *a)
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

int	ft_valid_args(int argc, char **argv, t_struct *ehe)
{
	int	x;

	x = 1;
	while (x < argc)
	{
		if (ft_is_num(argv[x]) == 1)
			return (0);
		x++;
	}
	if (ft_populate(argv, ehe) == 0)
		return (0);
	if (ft_no_dups(ehe) == 0)
		return (0);
	return (1);
}

int	ft_no_dups(t_struct *src)
{
	int	x;
	int	y;

	x = 0;
	while (x < src->len)
	{
		y = x;
		while (y >= 0)
		{
			if (y != x && src->stackaux[x] == src->stackaux[y])
			{
				ft_free_struct(src);
				ft_error();
			}
			y--;
		}
		x++;
	}
	return (1);
}

int	ft_populate(char **src, t_struct *dest)
{
	int	x;

	x = 1;
	while (src[x])
	{
		dest->stackaux[x - 1] = ft_atoi_ps(src[x], dest);
		if (dest->flag_error == 1)
		{
			ft_free_struct(dest);
			ft_error();
		}
		x++;
	}
	return (1);
}
