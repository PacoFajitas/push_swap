/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:59:59 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/07 22:00:26 by tfiguero         ###   ########.fr       */
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
				ra(aha);
		}
		chunk_c--;
		limit_chunk += j;
	}
}

void	optimizacon_chunkero(t_struct *aha, int li_chunk)
{
	int j;
	int k;
	
	j = 0;
	while (j < aha->len)
	{
		if (aha->stacka[j] <= li_chunk)
			k = j;
		j++;
	}
	while (i > 0)
	{
		if (aha->stacka[i] <= li_chunk)
		{
		}
	}
	//Comparar i con len-J para ver cual esta mas cerca de la posicion 0 y entonces decidir si hago rra o ra
	//En el caso de que esten a la misma distancia mirar cual esta mas cerca del stackb[0]
	if(k <= aha->lena / 2)
		while(aha->stacka[0] != i)
			ra(aha);
	else
		while(aha->stacka[0] != i)
			rra(aha);
}
