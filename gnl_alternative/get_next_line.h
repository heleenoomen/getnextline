#ifndef
# define GET_NEXT_LINE_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

# ifndef
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char	*buffer;
	size_t	bytes_read;
	size_t	len;
	s_list	*next;
}			t_list;

typedef struct s_struct
{
	t_list	*list;
	t_list	*last;
	size_t	complnds;
}			t_struct;
