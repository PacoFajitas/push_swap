/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_to_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:12:29 by tfiguero          #+#    #+#             */
/*   Updated: 2024/07/30 19:10:21 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_of_3(t_struct *a)
{
	if (a->len == 2)
	{
		if (a->stacka[0] > a->stacka[1])
			sa(a, 1);
	}
	else if (a->stacka[0] > a->stacka[1] && a->stacka[0] < a->stacka[2])
		sa(a, 1);
	else if (a->stacka[0] > a->stacka[1] && a->stacka[1] > a->stacka[2])
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (a->stacka[0] > a->stacka[1] && a->stacka[0] > a->stacka[2])
		ra(a, 1);
	else if (a->stacka[0] < a->stacka[1] && a->stacka[0] > a->stacka[2])
		rra(a, 1);
	else if (a->stacka[0] < a->stacka[1] && a->stacka[1] > a->stacka[2])
	{
		rra(a, 1);
		sa(a, 1);
	}
}

void	ft_stack_of_4(t_struct *a, int j)
{
	int	i;

	i = 0;
	while (i < a->lena)
	{
		if (a->stacka[i] < a->stacka[j])
			j = i;
		i++;
	}
	if (j == 3)
		rra(a, 1);
	else if (j == 2)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (j == 1)
		ra(a, 1);
	pb(a, 1);
	ft_stack_of_3(a);
	pa(a, 1);
}

void	ft_stack_of_5(t_struct *a, int i, int j)
{
	while (i < a->lena)
	{
		if (a->stacka[i] < a->stacka[j])
			j = i;
		i++;
	}
	if (j == 4)
		rra(a, 1);
	if (j == 3)
	{
		rra(a, 1);
		rra(a, 1);
	}
	if (j == 1)
		ra(a, 1);
	if (j == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	pb(a, 1);
	ft_stack_of_4(a, 0);
	pa(a, 1);
}
