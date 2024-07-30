/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:01:42 by tfiguero          #+#    #+#             */
/*   Updated: 2024/07/30 18:17:53 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_struct(t_struct *ehe)
{
	free(ehe->stacka);
	free(ehe->stackb);
	free(ehe->stackaux);
	free(ehe);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}
