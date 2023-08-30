/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:46:32 by tfiguero          #+#    #+#             */
/*   Updated: 2023/08/30 15:45:07 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	ft_atoi(const char	*str, s_struct *a)
{
	long long int	ret;
	int	sign;

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
	if(ret > (long long int)2147483647 || ret < (long long int)2147483647)
		a->flag_error = 1;
	return (ret * sign);
}

int	ft_ini_nums(s_struct *ini, int len)
{
	ini->len = len - 1;
	ini->lena = len - 1;
	ini->lenb = 0;
	ini->stacka = (int*) malloc(sizeof(int) * (len));
	if (!ini->stacka)
	{
		free(ini);
		return (0);
	}
	ini->stackb = (int*) malloc(sizeof(int) * (len));
	if (!ini->stackb)
	{
		free(ini->stacka);
		free(ini);
		return (0);
	}
	ini->stackaux = (int*) malloc(sizeof(int) * len);
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
	while(*x)
	{
		if(*x >= '0' || *x <= '9')
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

int	ft_populate(char **src, s_struct *dest)
{
	int	x;
	
	x = 1;
	while(*src[x])
	{
		*dest->stacka = ft_atoi(src[x], dest);
		if(!dest)
			return(0);
		dest++;
		x++;
	}
	return(1);
}

int	ft_valid_args(int argc, char **argv, s_struct *ehe)
{
	int	x;

	x = 1;
	while (x < argc)
	{
		if (ft_is_num(argv[x]) == 0)
			return (0);
		x++;
	}
	if (ft_populate(argv, ehe) == 0)
		return (0);
	if (ft_no_dups(ehe) == 0)
		return (0);
	return (1);
}
/* int	main(int argc, char **argv)
{
	s_struct *nums;

	if (argc == 1)
		return(0);
	printf("ok");
	nums = (s_struct *)malloc(sizeof(s_struct));
	if(!nums)
		return(0);
	if (ft_ini_nums(nums, argc) == 0)
	{
		free (nums);
		return (0);
	}
	printf("ok2");
	if (ft_valid_args(argc, argv, nums->stacka) == 0)
	{
		free (nums);
		return (0);
	}
} */
/* int	main()
{
	char	*x = "192839192838";
	int		y;

	printf("%i", y);
	return(0); 
} */