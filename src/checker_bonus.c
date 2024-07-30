/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:53:54 by tfiguero          #+#    #+#             */
/*   Updated: 2024/07/30 23:49:34 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_double(t_struct *nums, int flag)
{
	if (flag == 0)
	{
		ra(nums, 0);
		rb(nums, 0);
	}
	else
	{
		rra(nums, 0);
		rrb(nums, 0);
	}
}

int	solved(t_struct *nums)
{
	int	x;
	int	y;

	x = 1;
	if (nums->lenb != 0 || nums->lena != nums->len)
		return (0);
	y = nums->stacka[0];
	while (x < nums->len)
	{
		if (y > nums->stacka[x])
			return (0);
		y = nums->stacka[x];
		x++;
	}
	return (1);
}

void	ft_moving(t_struct *nums, char *move)
{
	if (!ft_strcmp(move, "pa\n"))
		pa(nums, 0);
	else if (!ft_strcmp(move, "pb\n"))
		pb(nums, 0);
	else if (!ft_strcmp(move, "ss\n"))
		ss(nums, 0);
	else if (!ft_strcmp(move, "sb\n"))
		sb(nums, 0);
	else if (!ft_strcmp(move, "sa\n"))
		sa(nums, 0);
	else if (!ft_strcmp(move, "rra\n"))
		rra(nums, 0);
	else if (!ft_strcmp(move, "rrb\n"))
		rrb(nums, 0);
	else if (!ft_strcmp(move, "ra\n"))
		ra(nums, 0);
	else if (!ft_strcmp(move, "rb\n"))
		rb(nums, 0);
	else
	{
		ft_free_struct(nums);
		ft_error();
	}
}

void	ft_aux_main(t_struct *nums)
{
	char		*move;

	move = get_next_line(STDIN_FILENO);
	while (move)
	{
		if (!ft_strcmp(move, "rr\n"))
			ft_move_double(nums, 0);
		else if (!ft_strcmp(move, "rrr\n"))
			ft_move_double(nums, 1);
		else
			ft_moving(nums, move);
		free(move);
		move = get_next_line(STDIN_FILENO);
	}
	free(move);
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
	ft_aux_main(nums);
	if (solved(nums))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_struct(nums);
	return (0);
}
