# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

t_list	*make_node(int fd, t_list *node)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
		return (NULL);
	newnode->buffer == malloc(BUFFER_SIZE);
	if (node->buffer == NULL)
	{
		free (newnode);
		return (NULL);
	}
	node->bytesread = read(fd, node->buffer, BUFFER_SIZE);
	if (node->bytes_read = -1)
	{
		ft_lstclear_gnl(newnode);
		return (NULL);
	}
	if (node == NULL)
		newnode->nodes_in_lst = 0;
	else
		newnode->nodes_in_lst = node->nodes_in_lst;
	newnode->next == NULL;
	return (newnode);
}

void	make_structs(int fd, t_list *lst, t_node *node)
{
	node = make_node(fd, node);
	while (node != NULL && node->bytesread == BUFFER_SIZE 
		&& !ft_strchr_gnl(node->buffer, '\n'))
		{
			ft_lstadd_back_gnl(&lst, node);
			node->nodes_in_lst++;
			node = makenode(fd, node);
		}
}

void	split_structs(char *staticline, char *line, t_list *lst, t_list *node)
{
	size_t	statlen;
	size_t	add_to_line;
	size_t	new_statlen;
	char	*ptr;
	t_list	*tmp;

	statlen = ft_strlen_newline(staticline, BUFFER_SIZE + 1);
	add_to_line = ft_strlen_newline(node->buffer, node->bytes_read);
	line = malloc(statlen + (node->nodes_in_lst * BUFFER_SIZE) + add_to_line 1);
	if (line == NULL)
		return ;
	ptr = line;
	tmp = lst;
	ptr += ft_strncpy_gnl(line, staticline, statlen);
	while (tmp != NULL)
	{
		ptr += ft_strncpy_gnl(ptr, tmp->buffer, BUFFER_SIZE);
		tmp = tmp->next;
	}
	ft_strncpy_gnl(ptr, node->buffer, add_to_line);
	new_statlen = node->bytes_read - add_to_line;
	free(staticline);
	staticline = malloc(new_statlen + 1);
	ft_strncpy_gnl(staticline, node->buffer, new_statlen);
}

void	split_static(staticline, line)
{
	size_t	statlen;
	size_t	newstatlen;
	size_t	add_to_line;
	char	*newstatic;

	add_to_line = ft_strlen_newline(staticline);
	line = malloc(add_to_line + 1);
	if (line == NULL)
		return ;
	ft_strncpy_gnl(line, staticline, add_to_line);
	statlen = 0;
	while (staticline[statlen])
		statlen++;
	newstatlen = statlen - add_to_line;
	newstatic = malloc(newstatlen + 1);
	ft_strncpy_gnl(newstatic, staticline + add_to_line, newstatlen);
	free(staticline);
	staticline = newstatic;
}

char *get_next_line(int fd)
{
	static char	*staticline;
	char		*line;
	t_list		*lst;
	t_list		*node;

	line = NULL;
	node = NULL;
	lst = NULL;
	if (ft_strchr_gnl(staticline, '\n'))
		split_static(staticline, line);
	else
	{
		make_structs(fd, lst, node);
		if (node != NULL)
			split_structs(staticline, line, lst, node);
	}
	if (staticline == NULL)
	{
		free(line);
		line = NULL;
	}
	ft_lstclear_gnl(node);
	ft_lstclear_gnl(lst);
	return (line);
}