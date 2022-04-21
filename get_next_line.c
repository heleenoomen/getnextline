/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:56:46 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/21 18:26:19 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static int	timesread;
	char		*newline;
	char		*returnstr;

	newline = malloc(BUFFER_SIZE + 1, 1);
	if (newline == NULL)
		return (NULL);
	while (!ft_strchr(static_line, '\n') && read(fd, newline, BUFFER_SIZE) == BUFFER_SIZE)
	{

	}

}