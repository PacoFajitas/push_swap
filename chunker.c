/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:59:59 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/13 22:28:27 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

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

void	closer_from_chunk(t_struct *aha, int li_chunk)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = aha->lena - 1;
	k = 1;
	while (i < aha->lena)
	{
		if(aha->stacka[i] < li_chunk)
			break;
		i++;
	}
	while (j >= 0)
	{
		if (aha->stacka[j] < li_chunk)
			break;
		k++;
		j--;
	}

	if(k < i)
		optimizacion_chunkero(aha, 1, k);
	else
		optimizacion_chunkero(aha, 0, i);
}
void	optimizacion_chunkero(t_struct *aha, int flag_rr, int cuant)
{
	if(flag_rr == 0)
	{
		while(cuant > 0)
		{
			ra(aha);
			cuant--;
		}
	}
	else
	{
		while (cuant > 0)
		{
			rra(aha);
			cuant--;
		}
	}
}

/* void	optimizacion_chunkero(t_struct *aha, int li_chunk)
{
	int j;
	int k;
	int	i;
	
	j = 0;
	i = aha->lena;
	k = -1;
	while (j < aha->lena)
	{
		if (aha->stacka[j] <= li_chunk && k == -1)
			k = j;
		j++;
	}
	j = -1;
	while (i > 0)
	{
		if (aha->stacka[i] <= li_chunk && j == -1)
			j = i;
		i--;
	}
	if_else_optimizacion_chunkero(aha, 0, j , k);
}
void	if_else_optimizacion_chunkero(t_struct *aha, int i, int j, int k)
{
	int	look_for;

	if (k == -1)
	{
		look_for = aha->stacka[j-1];
	}
	else if(aha->lena - j + 1 < k)
	{
		look_for = aha->stacka[j-1];
		i = 0;
	}
	else
	{
		look_for = aha->stacka[k];
		i = 1;
	}
	if(i == 1)
		while(aha->stacka[0] != look_for)
			ra(aha);
	else
		while(aha->stacka[0] != look_for)
			rra(aha);
} */
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
