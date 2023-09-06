/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:46:32 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/06 19:10:48 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	ft_atoi(const char	*str, t_struct *a)
{
	long long int	ret;
	int				sign;

	sign = 1;
	ret = 0;
	a->flag_error = 0;
	while (*str == 9 || *str == 10 || *str == 11
		|| *str == 12 || *str == 13 || *str == 32)
		str++;
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
		ret = (ret * 10) + *str - 48;
		str ++;
	}
	if (ret > (long long int)2147483647 || ret < (long long int)-2147483648)
		a->flag_error = 1;
	return (ret * sign);
}

int	ft_ini_nums(t_struct *ini, int len)
{
	ini->len = len - 1;
	ini->lena = len - 1;
	ini->lenb = 0;
	ini->stacka = (int *) malloc(sizeof(int) * (len - 1));
	if (!ini->stacka)
	{
		free(ini);
		return (0);
	}
	ini->stackb = (int *) malloc(sizeof(int) * (len - 1));
	if (!ini->stackb)
	{
		free(ini->stacka);
		free(ini);
		return (0);
	}
	ini->stackaux = (int *) malloc(sizeof(int) * (len - 1));
	if (!ini->stackaux)
	{
		free(ini->stacka);
		free(ini->stackb);
		free(ini);
		return (0);
	}
	return (1);
}

int	ft_is_num(char *x)
{
	int	i;

	i = 0;
	while (x[i])
	{
		if (*x >= '0' && *x <= '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_no_dups(int *src)
{
	int	x;
	int	y;

	x = 0;
	while (src[x])
	{
		y = x;
		while (y >= 0)
		{
			if (y != x && src[x] == src[y])
			{
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
		dest->stacka[x - 1] = ft_atoi(src[x], dest);
	 	if (dest->flag_error == 1)
		{
			free(dest->stacka);
			free(dest->stackb);
			free(dest->stackaux);
			free(dest);
			ft_error();
		}
		x++;
	}
	x = 0;
	while (dest->stacka[x])
	{
		x++;
	}

	
	return (1);
}

int	ft_valid_args(int argc, char **argv, t_struct *ehe)
{
	int	x;

	x = 1;
	while (x < argc)
	{
		if (ft_is_num(argv[x]) == 1)
			ft_error();
		x++;
	}
	if (ft_populate(argv, ehe) == 0)
		return (0);
	if (ft_no_dups(ehe->stacka) == 0)
		ft_error();

	return (1);
}

int	main(int argc, char **argv)
{
	t_struct	*nums;
	int	i = 0;

	if (argc == 1)
		return (0);
	nums = (t_struct *)malloc(sizeof(t_struct));
	if (!nums)
		return (0);
	if (ft_ini_nums(nums, argc) == 0)
	{
		free (nums);
		return (0);
	}
	
	if (ft_valid_args(argc, argv, nums) == 0)
	{
		free (nums);
		return (0);
	}
	 if (nums->len == 3)
	 	ft_stack_of_3(nums);
	while (i < nums->lena)
	{
		printf("%i ", nums->stacka[i]);
		i++;
	}
	
	
}
/* int	main()
{
	char	*x = "192839192838";
	int		y;

	printf("%i", y);
	return(0); 
} */