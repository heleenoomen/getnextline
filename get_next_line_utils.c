#include"get_next_line.h"

int		ft_strchr_gnl(const char *s, char c)
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

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
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

void	ft_strncat_gnl(char *dst, const char *src1, const char *src2, size_t n)
{
	size_t	i;
	size_t	j;

	if (src1 == NULL)
		src1 = "";
	if (src2 == NULL)
		src2 = "";
	i = 0;
	while (i < n && src1[i])
	{
		dst[i] = src1[i];
		i++;
	}
	j = 0;
	while ((i + j) < n && src2[j])
	{
		dst[i + j] = src2[j];
		j++;
	}
	dst[i + j] = '\0';
}
