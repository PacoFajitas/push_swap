/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:22:13 by tfiguero          #+#    #+#             */
/*   Updated: 2024/07/30 19:10:33 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_done(t_struct *aha)
{
	int	i;
	int	j;

	i = 1;
	j = aha->stacka[0];
	while (i < aha->lena)
	{
		if (j > aha->stacka[i])
			return ;
		j = aha->stacka[i];
		i++;
	}
	ft_free_struct(aha);
	exit (0);
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
		if (aha->stacka[i] < li_chunk)
			break ;
		i++;
	}
	while (j >= 0)
	{
		if (aha->stacka[j] < li_chunk)
			break ;
		k++;
		j--;
	}
	if (k < i)
		optimizacion_chunkero(aha, 1, k);
	else
		optimizacion_chunkero(aha, 0, i);
}

void	optimizacion_chunkero(t_struct *aha, int flag_rr, int cuant)
{
	if (flag_rr == 0)
	{
		while (cuant > 0)
		{
			ra(aha, 1);
			cuant--;
		}
	}
	else
	{
		while (cuant > 0)
		{
			rra(aha, 1);
			cuant--;
		}
	}
}

int	ft_ini_nums(t_struct *ini, int len)
{
	ini->len = len - 1;
	ini->lena = len - 1;
	ini->lenb = 0;
	ini->stacka = (int *) malloc(sizeof(int) * (len - 1));
	if (!ini->stacka)
	{
		free(ini);
		return (0);
	}
	ini->stackb = (int *) malloc(sizeof(int) * (len - 1));
	if (!ini->stackb)
	{
		free(ini->stacka);
		free(ini);
		return (0);
	}
	ini->stackaux = (int *) malloc(sizeof(int) * (len - 1));
	if (!ini->stackaux)
	{
		free(ini->stacka);
		free(ini->stackb);
		free(ini);
		return (0);
	}
	return (1);
}

int	ft_is_num(char *x)
{
	int	i;

	if (x[0] == '\0')
		return (1);
	i = 0;
	if ((x[0] == '-' || x[0] == '+') && x[1])
		i = 1;
	while (x[i] && (x[i] > '0' && x[i] < '9'))
		i++;
	if (x[i] && (x[i] < '0' || x[i] > '9'))
		return (1);
	return (0);
}
