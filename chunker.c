/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:59:59 by tfiguero          #+#    #+#             */
/*   Updated: 2023/08/31 17:08:15 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	ft_chunko(t_struct *aha, int chunk_c)
{
	//if el numero que voy a pasar pertenece a la misma mitad del chunk 
	//que el primero de stack b y el ultimo numero de stackb no, hay que 
	//hacer un rrr antes de hacer pb para optimizar la division de chunks.
	//Hacer funcion que revise si los numeros restantes en el stack a estan ya ordenados
	//para empezar a pasar los numeros del stack b sin pasos innecesarios.
}

int	ft_check_ordered(t_struct *aha)
{
	int	i;

	i = 0;
	while (i < aha->lena - 1)
	{
		if (aha->stacka[i] > aha->stacka[i+1])
			return (1);
		i++;
	}
	return(0);	
}