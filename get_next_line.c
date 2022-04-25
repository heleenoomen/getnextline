#include"get_next_line.h"

void	ft_init(t_struct *t)
{
	t->temp = NULL;
	t->tempnew = NULL;
	t->line = NULL;
	t->bytesread = 0;
	t->remtemp = NULL;
	t->remrem = NULL;
}

void	ft_error(t_struct *t, char *buffer)
{
	free(t->temp);
	free(buffer);
	t->temp = NULL;
	return ;
}

void	read_to_temp(t_struct *t, int fd)
{
	char		*buffer;
	size_t		lentmp;
	size_t		lentmp_new;

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		ft_error(t, buffer);
	t->bytesread = read(fd, buffer, BUFFER_SIZE);
	if (t->bytesread == -1)
		ft_error(t, buffer);
	lentmp = ft_strlen_gnl(t->temp);
	lentmp_new = lentmp + t->bytesread;
	t->tempnew = malloc(lentmp_new + 1);
	if (t->tempnew == NULL)
		ft_error(t, buffer);
	ft_strncat_gnl(t->tempnew, t->temp, buffer, lentmp_new);
	free(t->temp);
	free(buffer);
	t->temp = t->tempnew;
}

void	split_line(char *remainder, t_struct *t)
{
	size_t	lenrm;
	size_t	lentmp;
	size_t	linelen;
	size_t	remlenrm;
	size_t	remlentmp;

	lenrm = ft_strlen_newline(remainder);
	lentmp = ft_strlen_newline(t->temp);
	linelen = lenrm + lentmp;
	if (!linelen)
		return ;
	t->line = malloc(linelen + 1); 
	if (t->line == NULL)
		return ;
	ft_strncat_gnl(t->line, remainder, t->temp, linelen);
	remlenrm = ft_strlen_gnl(remainder) - lenrm;
	remlentmp = ft_strlen_gnl(t->temp) - lentmp;
	t->remtemp = t->temp + lentmp;
	t->remrem = remainder + lenrm;
	ft_strncat_gnl(remainder, t->remrem, t->remtemp, remlenrm + remlentmp);
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	t_struct	t;
	
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	ft_init(&t);
	if (ft_strchr_gnl(remainder, '\n'))
	{
		split_line(remainder, &t);
		return (t.line);
	}
	read_to_temp(&t, fd);
	while (t.temp != NULL && !ft_strchr_gnl(t.temp, '\n') && t.bytesread)
		read_to_temp(&t, fd);
	if (t.temp == NULL)
		return (NULL);
	split_line(remainder, &t);
	free(t.temp);
	return (t.line);
}

int main(void)
{
	FILE	*file;
	char	*line;
	int		fd;
	int		i;

	file = fopen("text.txt", "r");
	fd = fileno(file);
	i = 0;
	while(i < 10)
	{
		line = get_next_line(fd);
		printf("line = %s", line);
		i++;
	}
	free(line);
	fclose(file);
}
