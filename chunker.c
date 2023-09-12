/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:59:59 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/09 12:05:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	ft_chunko(t_struct *aha, int chunk_c)
{
	int	limit_chunk;
	int	i;
	int	j;

	limit_chunk = aha->len / chunk_c;
	j = limit_chunk;
	limit_chunk += aha->len % chunk_c;
	while (chunk_c > 0)
	{
		i = 0;
		while (i < limit_chunk && aha->lena > 0)
		{
			if (aha->stacka[i] <= limit_chunk)
			{
				pb(aha);
				if (aha->stackb[0] <= limit_chunk - (j / 2) && aha->lenb > 1)
					rb(aha);
				i++;
			}
			else
				ra(aha);
		}
		chunk_c--;
		limit_chunk += j;
	}
}

void	optimizacion_chunkero(t_struct *aha, int li_chunk)
{
	int j;
	int k;
	int	i;
	
	j = 0;
	i = aha->lena;
	while (j < aha->len)
	{
		if (aha->stacka[j] <= li_chunk)
			k = j;
		j++;
	}
	while (i > 0)
	{
		if (aha->stacka[i] <= li_chunk)
			j = i;
		i--;
	}
	if_else_optimizacion_chunkero(aha, i, j , k);
}
void	if_else_optimizacion_chunkero(t_struct *aha, int i, int j, int k)
{
	int	look_for;

	if(aha->lena - j + 1 < k)
	{
		look_for = j;
		i = 0;
	}
	else
	{
		look_for = k;
		i = 1;
	}
	printf("%i",look_for);
	look_for = aha->stacka[look_for];
	
	if(i == 1)
		while(aha->stacka[0] != look_for)
			ra(aha);
	else
		while(aha->stacka[0] != look_for)
			rra(aha);
	exit(0);
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
	int	aux;
	int	aux_exit;

	aux = l->len;
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
