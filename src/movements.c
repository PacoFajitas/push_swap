/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:10:31 by tfiguero          #+#    #+#             */
/*   Updated: 2024/07/30 19:12:00 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	rra(t_struct *a, int print)
{
	int	i;

	i = 0;
	while (i < a->lena)
	{
		ft_swap(&a->stacka[0], &a->stacka[i]);
		i++;
	}
	if (print == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_struct *b, int print)
{
	int	i;

	i = 0;
	while (i < b->lenb)
	{
		ft_swap(&b->stackb[0], &b->stackb[i]);
		i++;
	}
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	ra(t_struct *a, int print)
{
	int	i;

	i = 1;
	while (i < a->lena)
	{
		ft_swap(&a->stacka[i - 1], &a->stacka[i]);
		i++;
	}
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_struct *b, int print)
{
	int	i;

	i = 1;
	while (i < b->lenb)
	{
		ft_swap(&b->stackb[i - 1], &b->stackb[i]);
		i++;
	}
	if (print == 1)
		write(1, "rb\n", 3);
}
