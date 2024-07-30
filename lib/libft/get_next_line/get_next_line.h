/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:43:40 by tfiguero          #+#    #+#             */
/*   Updated: 2024/07/30 19:02:40 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin_l(char *ret, char *s2);
char	*ft_strchr_l(const char *s, int c);
char	*ft_substr_l(char *s, unsigned int start, size_t len);
size_t	ft_strlen_l(char *s);
char	*ft_clean_buffer(char *data);
char	*ft_fill_data(char *data, int fd, int flag);
char	*ft_free(char **buffer);

#endif