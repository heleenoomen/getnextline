#include"get_next_line.h"

t_list	*ft_lstnew_gnl(int fd, t_struct *t)
{
	t_list	*node;
	size_t	bytesread;
	size_t	i;

	t->last = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	t->last->buffer = malloc(BUFFER_SIZE);
	if (node->buffer == NULL)
		return (NULL);
	t->last->bytesread = read(fd, node->buffer, BUFFER_SIZE);
	if (node->bytes_read == -1)
		return (NULL);
	t->last->len = 0;
	while (len < BUFFER_SIZE && node->buffer[node->len] != '\n')
		node->len++;
	t->last->next = NULL;
	return (node);
}

void	makeline(char *staticline, t_stuct *t)
{
	size_t	staticlen;
	char	*ptr;

	staticlen = ft_strlen_gnl(staticline);
	t->line = ft_calloc(staticlen + (t->completenodes * BUFFER_SIZE) + t->last->len + 1, 1);
	if (t->line == NULL)
		return ;
	ft_strlcpy_gnl(t->line, staticline, staticlen);
	ptr = t->line + staticlen;
	while (t->list != NULL)
	{
		ft_strlcpy_gnl(ptr, t->list->buffer, BUFFER_SIZE);
		t->list = t->list->next;
		ptr += BUFFER_SIZE;
	}
	ft_strlcpy_gnl(ptr, t->last->buffer, t->last->len);
}

char	*update_static(char *staticline, t_struct *t)
{
	size_t	newstaticlen;

	if (staticline != NULL)
		free(staticline);
	newstaticlen = BUFFER_SIZE - last->len, 1
	staticline = ft_calloc(BUFFER_SIZE - last->len, 1);
	ft_strlcpy_gnl(staticline, last->buffer + last->len + 1, newstaticlen);
	return (staticline);
}

void	ft_lstclear_gnl(t_list **list)
{
	if ((*list)->next == NULL)
	{
		free((*lst)->buffer);
		free(*lst);
		return ;
	}
	ft_lstclear_gnl(&((*lst)->next));
	free((*lst)->buffer);
	free(*lst);
	*lst = NULL;
}

void	read_to_list(int fd, t_struct *t)
{
	while (t->last == NULL || (t->last->len == BUFFER_SIZE && t->last->bytes_read))
	{
		t->last = ft_lstnew_gnl(fd, completenodes);
		if (t->last == NULL)
			return ;
		if (t->last->len == BUFFER_SIZE)
		{
			ft_lstadd_back(&(t->list), &(t->last));
			t->completenodes++;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*staticline;
	char		*line;
	t_struct	t;

	t.list = NULL;
	t.last = NULL;
	t.completenodes = 0;
	read_to_list(fd, &t);
	if (t.last == NULL)
		return (NULL);
	if (!t.last->bytes_read)
	{
		line = staticline;
		staticline = NULL;
		return(line);
	}
	make_line(staticline, &t);
	staticline = update_static(t.last);
	ft_lstadd_back(&t.list, t.last);
	ft_lstclear_gnl(&t.list);
	return (t.line);
}