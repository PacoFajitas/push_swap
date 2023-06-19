/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:46:32 by tfiguero          #+#    #+#             */
/*   Updated: 2023/06/19 16:49:19 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void ft_view_stacks(s_struct *ehe)
{
	int	x;

	x = 0;
	
	while (x < ehe.len)
	{
		printf("%i | %i\n", ehe.stacka[x], ehe.stackb[x]);
	}
	printf("-------\na | b");
}

int	ft_atoi(const char	*str)
{
	int	ret;
	int	sign;

	sign = 1;
	ret = 0;
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
	return (ret * sign);
}

int	ft_ini_nums(s_struct *ini, int len)
{
	int i;

	ini->len = len;
	ini->stacka = (int*) malloc(sizeof(int) * len);
	if (!ini->stacka)
		return (0);
	ini->stackb = (int*) malloc(sizeof(int) * len);
	if (!ini->stackb)
	{
		free (ini->stacka);
		return (0);
	}
	i = 0;
	while (i<len)
	{
		ini->stacka[i] = '\0';
		ini->stackb[i] = '\0';
		i++;
	}
	return (1);
}

int	ft_is_num(char *x)
{
	while(*x)
	{
		if(x >= '0' || x <= '9')
			return(1);
	x++;
	}
	return(0);
}

int	ft_no_dups(int *src)
{
	int	x;
	int	y;

	x = 0;
	while(src[x])
	{
		y = x;
		while (y >= 0)
		{
			if (src[x] == src[y])
				return(0);
			y--;
		}
		x++;
	}
	return (1);
}

int	ft_populate(char **src, int *dest)
{
	int	x;
	
	x = 1;
	while(*src[x])
	{
		dest = ft_atoi(src[x]);
		if(!dest)
			return(0);
		dest++;
		x++;
	}
	return(1);
}

int	ft_valid_args(int argc, char **argv, int *ehe)
{
	int	x;

	x = 1;
	while (x < argc)
	{
		if (ft_is_num(argv[x]) == 0)
			return (0);
	}
	if (ft_populate(argv, ehe) == 0)
		return (0);
	if (ft_no_dups(ehe) == 0)
		return (0);
	return (1);
}
int	main(int argc, char **argv)
{
	s_struct *nums;

	if (argc == 1)
		return(0);
	nums = (s_struct *)malloc(sizeof(s_struct));
	if (ft_ini_nums(nums, argc) == 0)
		return(0);
	if (ft_valid_args(argc, argv, nums->stacka) == 0)
		return (0);
}

int	main(void)
{
	s_struct *test;

	test->len =
}