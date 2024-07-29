/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:59:59 by tfiguero          #+#    #+#             */
/*   Updated: 2024/07/29 21:50:49 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_chunko(t_struct *aha, int chunk_c, int j)
{
	int	limit_chunk;
	int	i;

	limit_chunk = (aha->len / chunk_c) + (aha->len % chunk_c);
	j = limit_chunk;
	i = 1;
	while (chunk_c > 0)
	{
		while (i < limit_chunk && aha->lena > 0)
		{
			closer_from_chunk(aha, limit_chunk);
			pb(aha);
			if (aha->lenb > 1 && aha->stackb[0] <= limit_chunk - (j / 2))
				rb(aha);
			i++;
		}
		chunk_c--;
		limit_chunk += j;
	}
}

static int	aux_rr(t_struct *l, int aux_exit, int i)
{
	while (i > 0 && aux_exit == 0)
	{
		if (l->stackb[0] == l->lenb - 1 && l->memsolv == 0)
		{
			pa(l);
			i--;
			l->memsolv = 1;
			if (l->stackb[0] == l->lenb + 1)
				aux_exit = 1;
		}
		if (aux_exit == 0)
			rb(l);
		i--;
	}
	return (aux_exit);
}

static int	aux_rrr(t_struct *l, int aux_exit, int i)
{
	i = l->lenb - i;
	while (i > 0 && aux_exit == 0)
	{
		if (l->stackb[0] == l->lenb - 1 && l->memsolv == 0)
		{
			pa(l);
			i--;
			l->memsolv = 1;
			rrb(l);
			if (l->stackb[0] == l->lenb + 1)
				aux_exit = 1;
		}
		if (aux_exit == 0)
			rrb(l);
		i--;
	}
	return (aux_exit);
}

void	solve(t_struct *l)
{
	int	i;
	int	aux_exit;

	aux_exit = 0;
	l->memsolv = 0;
	while (l->lenb > 0)
	{
		i = 0;
		while (l->stackb[i] != l->lenb && i < l->lenb)
			i++;
		if (i <= (l->lenb / 2))
			aux_exit = aux_rr(l, aux_exit, i);
		else if (i > (l->lenb / 2))
			aux_rrr(l, aux_exit, i);
		pa(l);
		if (l->memsolv == 1)
		{
			if (l->stacka[0] - 1 == l->stacka[1])
				sa(l);
			l->memsolv = 0;
			aux_exit = 0;
		}
	}
}
