/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:53:54 by tfiguero          #+#    #+#             */
/*   Updated: 2024/07/29 23:43:03 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solved(t_struct *nums)
{
	int	x;
	int	y;
	
	x = 1;
	if(nums->lenb != 0 || nums->lena != nums->len)
		return (0);
	y = nums->stacka[0];
	while(x < nums->len)
	{
		if (y > nums->stacka[x])
			return(0);
		y = nums->stacka[x];
		x++;
	}
	return (1);
}

void	ft_moving(t_struct *nums, char *move)
{
	if (!ft_strcmp(move, "pa\n"))
		pa(nums);
	else if (!ft_strcmp(move, "pb\n"))
		pb(nums);
	else if(!ft_strcmp(move, "ss\n"))
		ss(nums);
	else if(!ft_strcmp(move, "sb\n"))
		sb(nums);
	else if(!ft_strcmp(move, "sa\n"))
		sa(nums);
	else if(!ft_strcmp(move, "rra\n"))
		rra(nums);
	else if(!ft_strcmp(move, "rrb\n"))
		rrb(nums);
	else if(!ft_strcmp(move, "ra\n"))
		ra(nums);
	else if(!ft_strcmp(move, "rb\n"))
		rb(nums);
	else
	{
		ft_free_struct(nums);
		ft_error();
	}
}

int	main(int argc, char **argv)
{
	char		*move;
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
	move = get_next_line(STDIN_FILENO);
	while (move)
	{
		ft_moving(nums, move);
		move = get_next_line(STDIN_FILENO);
	}
	if(solved(nums))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_struct(nums);
	return(0);	
}