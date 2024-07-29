/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:35:37 by tfiguero          #+#    #+#             */
/*   Updated: 2024/07/29 21:51:00 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *ehe, char *cmp)
{
	int	i;

	i = 0;
	while (ehe[i] && cmp[i])
	{
		if (ehe[i] != cmp[i])
			return (ehe[i] - cmp[i]);
		i++;
	}
	if ((ehe[i] && !cmp[i]) || (cmp[i] && !ehe[i]))
		return (ehe[i] - cmp[i]);
	return (0);
}