/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_to_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:12:29 by tfiguero          #+#    #+#             */
/*   Updated: 2023/07/27 20:18:17 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lib/push_swap.h"

void ft_stack_of_3(s_struct a)
{
	if (a.stacka[0] > a.stacka[1] && a.stacka[0] < a.stacka[2])
		sa(a.stacka);
	else if (a.stacka[0] > a.stacka[1] && a.stacka[1] > a.stacka[2])
	{
		sa(a.stacka);
		rra(a.stacka);
	}
	else if (a.stacka[0] > a.stacka[1] && a.stacka[0] > a.stacka[2])
		ra(a.stacka);
	else if (a.stacka[0] < a.stacka[1] && a.stacka[1] < a.stacka[2])
	{
		sa(a.stacka);
		ra(a.stacka);
	}
	else if(a.stacka[0] < a.stacka[1] && a.stacka[0] > a.stacka[2])
		rra(a.stacka);
}