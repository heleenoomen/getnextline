#ifndef LL_H
# define LL_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*buffer;
	size_t			bytes_read;
	size_t			nodes_in_lst;
	struct s_list	*next;
}					t_list;

size_t	ft_strlen_newline(char *s, size_t size);
int		ft_strchr_gnl(const char *s, char c);
size_t	ft_strncpy_gnl(char *dst, const char *src, size_t n);
void	ft_lstadd_back_gnl(t_list **lst, t_list *node);
void	ft_lstclear_gnl(t_list **lst);
t_list	*make_node(int fd, t_list *node);
void	make_structs(int fd, t_list *lst, t_node *node);
void	split_structs(char *staticline, char *line, t_list *lst, t_list *node);
void	split_static(staticline, line);

#endif

