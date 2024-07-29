/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:56:04 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/23 17:45:05 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isalpha(int in)
{
	int	ret;

	ret = 0;
	if ((in >= 'A' && in <= 'Z') || (in >= 'a' && in <= 'z'))
	{
		ret = 1;
	}
	return (ret);
}