/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:14:33 by tfiguero          #+#    #+#             */
/*   Updated: 2023/08/30 15:41:00 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	t_stacks
{
	int *stacka;
	int *stackb;
	int	*stackaux;
	int	len;
	int	lena;
	int	lenb;
	int flag_error;
}				s_struct;

void	ss(int *stacka, int *stackb);
void	sb(int *stack);
void	sa(int *stack);
void	rra(int *a);
void	rrb(int *b);
void	ra(int *a);
void	rb(int *b);
#endif