/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:14:33 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/08 16:53:46 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stacks
{
	int	*stacka;
	int	*stackb;
	int	*stackaux;
	int	len;
	int	lena;
	int	lenb;
	int	flag_error;
}				t_struct;

void	ss(t_struct *stacka);
void	sb(t_struct *stack);
void	sa(t_struct *stack);
void	rra(t_struct *a);
void	rrb(t_struct *b);
void	ra(t_struct *a);
void	rb(t_struct *b);
void	ft_error(void);
void	ft_swap(int *a, int *b);
void	ft_index(t_struct *aha);
void	ft_stack_of_3(t_struct *a);
void	ft_stack_of_4(t_struct *a, int j);
void	ft_stack_of_5(t_struct *a, int	i, 	int	j);
void	pa(t_struct *l);
void	pb(t_struct *l);
void	optimizacion_chunkero(t_struct *aha, int li_chunk);
void	if_else_optimizacion_chunkero(t_struct *aha, int i, int j, int k);
void	ft_chunko(t_struct *aha, int chunk_c);
void	ft_index(t_struct *aha);
#endif