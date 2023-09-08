/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:26:46 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/08 16:45:02 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	ft_index(t_struct *aha)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < aha->len)
	{
		j = 0;
		k = 1;
		while (j < aha->len)
		{
			if(aha->stackaux[i] > aha->stackaux[j])
				k++;
			j++;
		}
		aha->stacka[i] = k;
		i++;
	}
}