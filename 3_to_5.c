/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_to_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:12:29 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/06 20:46:26 by tfiguero         ###   ########.fr       */
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

void ft_stack_of_4()