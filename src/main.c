/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:46:32 by tfiguero          #+#    #+#             */
/*   Updated: 2024/07/29 23:51:06 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
