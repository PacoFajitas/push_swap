/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:59:59 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/06 15:32:44 by tfiguero         ###   ########.fr       */
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

int	ft_check_ordered(t_struct *aha)
{
	int	i;

	i = 0;
	while (i < aha->lena - 1)
	{
		if (aha->stacka[i] > aha->stacka[i + 1])
			return (1);
		i++;
	}
	return (0);
}
