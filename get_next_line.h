#ifndef
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

typedef struct s_struct
{
    char    *newstatic;
    char    *line;
    size_t  bytes_read;
}           t_struct;


#endif