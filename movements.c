/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:10:31 by tfiguero          #+#    #+#             */
/*   Updated: 2023/07/27 20:18:20 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lib/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/* void pa(int *stacka, int *stackb)
{
	
} */
void	rra(int *a)
{
	int i;

	i = 0;
	while(a[i])
	{
		ft_swap(a, a + i);
		i++;
	}
}
void	rrb(int *b)
{
	int i;

	i = 0;
	while(b[i])
	{
		ft_swap(b, b + i);
		i++;
	}
}
void	ra(int *a)
{
	int	i;
	
	i = 1;
	while(a[i])
	{
		ft_swap(a+i-1,a+i);
		i++;
	}
}
void	rb(int *b)
{
	int	i;
	
	i = 1;
	while(b[i])
	{
		ft_swap(b+i-1,b+i);
		i++;
	}
}

void sa(int *stack)
{
	ft_swap(&stack[0], &stack[1]);
}
void sb(int *stack)
{
	ft_swap(&stack[0], &stack[1]);
}
void ss (int *stacka, int *stackb)
{
	ft_swap(&stacka[0], &stacka[1]);
	ft_swap(&stackb[0], &stackb[1]);
}

/* void ra(s_struct *a)
{
	ft_swap(a->stacka[0]);
} */

int	main(void)
{
	int *a;
	
	a = malloc(sizeof(int) * 4);
  	*(a + 3) = 4;
  	*(a + 2) = 3;
  	*(a + 1) = 2;
  	*a = 1;
  	
	while (*a)
	{
		printf("%i", *a);
		a++;
	}
	printf("\n");
	a = a - 4;
	ra(a);
	while (*a) 
	{
		printf("%i", *a);
		a++;
	}
	
	
} 