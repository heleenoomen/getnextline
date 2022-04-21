/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:36:01 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/21 18:32:54 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>



void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	bytes;
	size_t	i;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	bytes = count * size;
	ptr = malloc(bytes);
	if (ptr == NULL)
		return ptr;
	i = 0;
	while (i < bytes)
		ptr[bytes] = '\0';
	return ((void *) ptr);
}
