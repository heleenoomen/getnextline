/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:56:46 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/22 18:22:10 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	**ft_splitstatic(char *staticline, t_split *splitted)
{
	size_t	len;
	size_t	newstatlen;

	len = 0;
	while (staticline[len] != '\n' && staticline[len])
		len++;
	splitted->line = ft_calloc(len + 1, 1);
	if (splitted->line == NULL)
		return (NULL);
	ft_strlencpy(splitted->line, staticline, len);
	newstatlen = ft_strlen_gnl(staticline) - len - 1;
	splitted->newstatic = ft_calloc(newstatlen, 1);
	if (splitted->newstatic == NULL)
		return (NULL);
	ft_strlencpy(splitted->newstatic, staticline + len + 1, newstatlen);
	if (bytesread == 0)
		splitted->end = 1;
	return (splitted);
}

char	*ft_add_to_static(char *staticline, char *line, size_t bytesread)
{
	char	*newstatic;
	size_t	staticlen;
	size_t	i;

	if (staticline == NULL)
	{
		newstatic = ft_calloc(bytesread + 1, 1);
		if (newstatic == NULL)
			return (NULL);
		ft_strlencpy(newstatic, line, bytesread);
		return (newstatic);
	}
	staticlen = ft_strlen_gnl(staticline);
	newstatic = ft_calloc(staticlen + bytesread + 1, 1);
	if (newstatic == NULL)
		return (NULL);
	ft_strlencpy(newstatic, staticline, staticlen);
	ft_strlencpy(newstatic + staticlen, line, bytesread);
	free(staticline);
	return(newstatic);
}

char	*ft_readtostatic(int fd, char *staticline, char *line, t_split *splitted)
{
	size_t	bytesread;

	bytesread = read(fd, line, BUFFER_SIZE);
	if (bytesread == -1)
		return (NULL);
	if (bytesread == 0 && splitted->staticline)
		return (NULL);
	return (ft_add_to_static(staticline, line, bytesread));
}

char	*get_next_line(int fd)
{
	static char	*staticline;
	char		*line;
	t_split		splitted;

	line = malloc(BUFFER_SIZE);
	if (line == NULL)
		return (NULL);
	while (!ft_strchr(staticline, '\n'))
	{
		staticline = ft_readtostatic(fd, staticline, line);
		if (staticline == NULL)
		{
			free (line);
			return (NULL);
		}
	}
	free (line);
	printf("staticline = %s\n", staticline);
	splitted = malloc(sizeof(char *) * 3);
	if (splitted == NULL)
		return NULL;
	ft_splitstatic(staticline, &splitted);
	staticline = splitted.newstatic;
	return (splitted.line);
}

int main(void)
{
	FILE	*file;
	int		fd;
	
	file = fopen("test.txt", "r");
	fd = fileno(file);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}