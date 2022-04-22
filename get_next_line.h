/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:00:07 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/22 18:16:20 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

typedef struct s_split
{
	char	*line;
	char	*newstatic;
	int		end;
}			t_split;

char	*get_next_line(int fd);
char	*ft_readtostatic(int fd, char *staticline, char *line);
char	*ft_add_to_static(char *staticline, char *line, size_t bytesread);
char	**ft_splitstatic(char *staticline, char **splitted);
size_t	ft_strlen_gnl(const char *s);
void	ft_strlencpy(char *dst, const char *src, size_t dstlen);
char	*ft_strchr(char const *s, int c);
void	*ft_calloc(size_t count, size_t size);

#endif