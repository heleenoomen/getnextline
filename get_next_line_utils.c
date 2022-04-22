/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:36:01 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/22 16:48:16 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_strlencpy(char *dst, const char *src, size_t dstlen)
{
	size_t	i;

	i = 0;
	while (src[i] && i < dstlen)
	{
		dst[i] = src[i];
		i++;
	}
}


char	*ft_strchr(char const *s, int c)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = (char *) s;
	while (*ptr)
	{
		if ((unsigned char) *ptr == (unsigned char) c)
			return (ptr);
		ptr++;
	}
	if (c == '\0')
		return (ptr);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	bytes;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	bytes = count * size;
	ptr = malloc(bytes);
	if (ptr == NULL)
		return ptr;
	while (bytes)
	{
		ptr[bytes] = '\0';
		bytes--;
	}
	return ((void *) ptr);
}
