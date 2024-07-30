/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:57:09 by tfiguero          #+#    #+#             */
/*   Updated: 2024/07/30 23:48:49 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_struct *stack, int print)
{
	if (!&stack->stacka[1])
		return ;
	ft_swap(&stack->stacka[0], &stack->stacka[1]);
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_struct *stack, int print)
{
	if (!&stack->stackb[1])
		return ;
	ft_swap(&stack->stackb[0], &stack->stackb[1]);
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ss(t_struct *stacka, int print)
{
	if (!&stacka->stacka[1] || !&stacka->stackb[1])
		return ;
	ft_swap(&stacka->stacka[0], &stacka->stacka[1]);
	ft_swap(&stacka->stackb[0], &stacka->stackb[1]);
	if (print == 1)
		write(1, "ss\n", 3);
}

void	pa(t_struct *l, int print)
{
	int	i;

	if (l->lenb == 0)
		return ;
	i = l->lena;
	l->lena = l->lena + 1;
	l->lenb = l->lenb - 1;
	while (i > 0)
	{
		ft_swap(&l->stacka[i], &l->stacka[i - 1]);
		i--;
	}
	l->stacka[0] = l->stackb[0];
	i = 0;
	while (i < l->lenb)
	{
		l->stackb[i] = l->stackb[i + 1];
		i++;
	}
	if (print == 1)
		write(1, "pa\n", 3);
}

void	pb(t_struct *l, int print)
{
	int	i;

	if (l->lena == 0)
		return ;
	i = l->lenb;
	l->lenb = l->lenb + 1;
	l->lena = l->lena - 1;
	while (i > 0)
	{
		ft_swap(&l->stackb[i], &l->stackb[i - 1]);
		i--;
	}
	l->stackb[0] = l->stacka[0];
	i = 0;
	while (i < l->lena)
	{
		l->stacka[i] = l->stacka[i + 1];
		i++;
	}
	if (print == 1)
		write(1, "pb\n", 3);
}
