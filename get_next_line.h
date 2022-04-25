#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1	
# endif

typedef struct s_struct
{
	char	*temp;
	char	*tempnew;
	char	*line;
	size_t	bytesread;
	char	*remtemp;
	char	*remrem;
}			t_struct;

int		ft_strchr_gnl(const char *s, char c);
size_t	ft_strlen_gnl(const char *s);
//void	ft_strncpy_gnl(char *dst, const char *src, size_t n);
//void	*ft_calloc(size_t count, size_t size);
void	ft_init(t_struct *t);
void	read_to_temp(t_struct *t, int fd);
size_t	ft_strlen_newline(char *s);
void	split_line(char *remainder, t_struct *t);
void	ft_strncat_gnl(char *dst, const char *src1, const char *src2, size_t n);


#endif
