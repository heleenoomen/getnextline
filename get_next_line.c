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
	// {
	// 	free(t->temp);
	// 	t->temp == NULL;
	// 	return ;
	// }
	t->bytesread = read(fd, buffer, BUFFER_SIZE);
	if (t->bytesread == -1)
		ft_error(t, buffer);
	// {
	// 	free(t->temp);
	// 	t->temp == NULL;
	// 	return ;
	// }
	lentmp = ft_strlen_gnl(t->temp);
	lentmp_new = lentmp + t->bytesread;
	t->tempnew = malloc(lentmp_new + 1);
	if (t->tempnew == NULL)
		ft_error(t, buffer);
	// {
	// 	free(t->temp);
	// 	t->temp == NULL;
	// 	return ;
	// }
	ft_strncat_gnl(t->tempnew, t->temp, buffer, lentmp_new);
	free(t->temp);
	free(buffer);
	t->temp = t->tempnew;
}

size_t	ft_strlen_newline(char *s)
{
	size_t len;
	
	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}

void	split_line(char *remainder, t_struct *t)
{
	size_t	lenrm;
	size_t	lentmp;
	size_t	linelen;
	size_t	remlenrm;
	size_t	remlentmp;

	//printf("\nremainder = %s\n", remainder);
	lenrm = ft_strlen_newline(remainder);
	//printf("lenrem = %zu\n", lenrm);
	//printf("t->temp = %s\n", t->temp);
	lentmp = ft_strlen_newline(t->temp);
	//printf("lentmp = %zu\n", lentmp);
	linelen = lenrm + lentmp;
	//printf("linelen = %zu\n", linelen);
	if (!linelen)
		return ;
	t->line = malloc(linelen + 1); 
	if (t->line == NULL)
		return ;
	ft_strncat_gnl(t->line, remainder, t->temp, linelen);
	//ft_strncpy_gnl(t->line, remainder, lenrm);
	//ft_strncpy_gnl(t->line + lenrm, t->temp, lentmp);
	remlenrm = ft_strlen_gnl(remainder) - lenrm;
	//printf("remlenrm = %zu\n", remlenrm);
	remlentmp = ft_strlen_gnl(t->temp) - lentmp;
	//printf("remlentmp = %zu\n", remlentmp);
	//if (lenrm)
	//ft_strncat_gnl(remainder, remainder + lenrm, t->temp + lentmp, remlenrm + remlentmp);
	//ft_strncpy_gnl(remainder, remainder + lenrm, remlenrm);
	//if (lentmp)
	//ft_strncpy_gnl(remainder + remlenrm, t->temp + lentmp, remlentmp);
	//printf("remainder = %s\n", remainder);
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
