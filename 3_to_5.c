/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_to_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:12:29 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/07 16:27:05 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lib/push_swap.h"

void ft_stack_of_3(t_struct *a)
{
	if (a->stacka[0] > a->stacka[1] && a->stacka[0] < a->stacka[2])
		sa(a);
	else if (a->stacka[0] > a->stacka[1] && a->stacka[1] > a->stacka[2])
	{
		sa(a);
		rra(a);
	}
	else if (a->stacka[0] > a->stacka[1] && a->stacka[0] > a->stacka[2])
		ra(a);
	else if (a->stacka[0] < a->stacka[1] && a->stacka[1] < a->stacka[2])
	{
		sa(a);
		ra(a);
	}
	else if(a->stacka[0] < a->stacka[1] && a->stacka[0] > a->stacka[2])
		rra(a);
}

void ft_stack_of_4(t_struct *a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < a->lena)
	{
		if(a->stacka[i] < a->stacka[j])
			j = i;
		i++;
	}
	if(j == 3)
		rra(a);
	else if(j == 2)
	{
		rra(a);
		rra(a);
	}
	else if(j == 1)
		ra(a);
	pb(a);
	ft_stack_of_3(a);
	pa(a);
}
void	ft_stack_of_5(t_struct *a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < a->lena)
	{
		if(a->stacka[i] < a->stacka[j])
			j = i;
		i++;
	}
	if(j == 4)
		rra(a);
	else if(j == 3)
	{
		rra(a);
		rra(a);
	}
	else if(j == 2)
	{
		rra(a);
		rra(a);
		rra(a);	
	}
	else if(j == 1)
		ra(a);
}
