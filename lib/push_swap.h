/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:14:33 by tfiguero          #+#    #+#             */
/*   Updated: 2024/07/30 23:50:18 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stacks_b
{
	int	*stacka;
	int	*stackb;
}				t_stacks_b;

typedef struct s_stacks
{
	int	*stacka;
	int	*stackb;
	int	*stackaux;
	int	len;
	int	lena;
	int	lenb;
	int	flag_error;
	int	memsolv;
}				t_struct;

void	ss(t_struct *stacka, int print);
void	sb(t_struct *stack, int print);
void	sa(t_struct *stack, int print);
void	rra(t_struct *a, int print);
void	rrb(t_struct *b, int print);
void	ra(t_struct *a, int print);
void	rb(t_struct *b, int print);
void	ft_error(void);
void	ft_swap(int *a, int *b);
void	ft_index(t_struct *aha);
void	ft_stack_of_3(t_struct *a);
void	ft_stack_of_4(t_struct *a, int j);
void	ft_stack_of_5(t_struct *a, int i, int j);
void	pa(t_struct *l, int print);
void	pb(t_struct *l, int print);
void	optimizacion_chunkero(t_struct *aha, int flag_rr, int cuant);
int		ft_valid_args(int argc, char **argv, t_struct *ehe);
int		ft_populate(char **src, t_struct *dest);
int		ft_no_dups(t_struct *src);
void	if_else_optimizacion_chunkero(t_struct *aha, int i, int j, int k);
void	ft_chunko(t_struct *aha, int chunk_c, int j);
void	closer_from_chunk(t_struct *aha, int li_chunk);
void	ft_index(t_struct *aha);
void	solve(t_struct *l);
void	ft_free_struct(t_struct *ehe);
void	is_done(t_struct *aha);
int		ft_atoi_ps(const char	*str, t_struct *a);
int		ft_ini_nums(t_struct *ini, int len);
int		ft_is_num(char *x);

#endif