/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:46:32 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/15 01:45:35 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	ft_no_dups(t_struct *src)
{
	int	x;
	int	y;

	x = 0;
	while (src->stackaux[x])
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
		dest->stackaux[x - 1] = ft_atoi(src[x], dest);
		if (dest->flag_error == 1)
		{
			ft_free_struct(dest);
			ft_error();
		}
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
			return (0);
		x++;
	}
	if (ft_populate(argv, ehe) == 0)
		return (0);
	if (ft_no_dups(ehe) == 0)
		return (0);
	return (1);
}

void	ft_if_else_pusap(t_struct *nums)
{
	ft_index(nums);
	is_done(nums);
	if (nums->len == 3 || nums->len == 2)
		ft_stack_of_3(nums);
	if (nums->len == 4)
		ft_stack_of_4(nums, 0);
	if (nums->len == 5)
		ft_stack_of_5(nums, 0, 0);
	if (nums->len <= 20 && nums->len > 5)
	{
		ft_chunko(nums, 2, 0);
		solve(nums);
	}
	if (nums->len > 20 && nums->len <= 150)
	{
		ft_chunko(nums, 4, 0);
		solve(nums);
	}
	if (nums->len > 150)
	{
		ft_chunko(nums, 9, 0);
		solve(nums);
	}
}

int	main(int argc, char **argv)
{
	t_struct	*nums;

	if (argc == 1)
		return (0);
	nums = (t_struct *)malloc(sizeof(t_struct));
	if (!nums)
		return (0);
	if (ft_ini_nums(nums, argc) == 0)
		ft_error();
	if (ft_valid_args(argc, argv, nums) == 0)
	{
		ft_free_struct(nums);
		ft_error();
	}
	ft_if_else_pusap(nums);
	ft_free_struct(nums);
	return (0);
}
