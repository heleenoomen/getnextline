#include"get_next_line.h"

//counts chars in a string of size n until 0 terminator or newline
//includes newline in len
//counts up to size chars total
size_t	ft_strlen_newline(char *s, size_t size)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (i < size && s[i] && s[i] != '\n')
		len++;
	if (i < size && s[i] == '\n')
		len++;
	return (len);
}

int	ft_strchr_gnl(const char *s, char c)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}

//copies max n bytes to dst and adds \0
//returns number of bytes copied
size_t	ft_strncpy_gnl(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (dst == NULL)
		return (0);
	if (src == NULL)
		src = "";
	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

//adds new node to end of list
void	ft_lstadd_back_gnl(t_list **lst, t_list *node)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = node;
		return;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

void	ft_lstclear_gnl(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	*lst = NULL;
	if (tmp->next == NULL)
	{
		free(tmp->buffer);
		free(tmp);
		return ;
	}
	ft_lstclear_gnl(&(tmp->next));
	free(tmp->buffer);
	free(tmp);
}
