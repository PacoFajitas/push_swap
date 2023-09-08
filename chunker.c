/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:59:59 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/08 17:29:07 by tfiguero         ###   ########.fr       */
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
				optimizacion_chunkero(aha, limit_chunk);//ra
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
