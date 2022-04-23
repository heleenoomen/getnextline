void    ft_init(t_struct *t, char *staticline)
{
    t->oldstatic = staticline;
    t->oldstaticlen = ft_strlen_gnl(t->newstatic);
    t->newstatic = NULL;
    t->newstaticlen = 0;
    t->line = NULL;
    t->linelen = 0;
    t->buffer = NULL;
    t->bytesread = 0;
}

void    read_to_static(int fd, t_struct *t)
{
    t->buffer = malloc(BUFFER_SIZE);
    if (t->buffer == NULL)
        return ;
    t->bytesread = read(t->fd, t->buffer, BUFFER_SIZE);
    if (t->bytesread == -1)
        return ;
    if (t->bytesread == 0 && !t->oldstatic[0])
        return ;
    t->newstatic = ft_calloc(t->oldstaticlen + bytesread + 1, 1);
    if (t->newstatic == NULL)
        return ;
    ft_strlcpy_gnl(t->newstatic, t->oldstatic, t->oldstaticlen);
    ft_strlcpy_gnl(t->newstatic + t->oldstaticlen, t->buffer, t->bytesread);
    free(t->buffer);
}

void    split_static(t_struct *t)
{
    while (t->oldstatic[t->linelen] && t->oldstatic[t->linelen] != '\n')
        t->linelen++;
    t->newstaticlen = t->oldstaticlen - t->linelen - 1;
    t->newstatic = ft_calloc(t->newstaticlen + 1, 1);
    if (t->newstatic == NULL)
        return ;
    t->line = ft_calloc(t->linelen + 1, 1);
    if (t->line == NULL)
    {
        free(t->newstatic);
        t->newstatic == NULL;
        return ;
    }
    ft_strlcpy_gnl(t->line, t->oldstatic, t->linelen);
    ft_strlcpy_gnl(t->newstatic, t->oldstatic + t->linelen + 1, t->newstaticlen);
}

char    *get_next_line(int fd)
{
    static char *staticline;
    t_struct    t;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    ft_init(staticline, &t);
    while (ft_strchr(staticline, '\n'))
        read_to_static(fd, &t);
    staticline = t->newstatic;
    if (staticline == NULL)
        return (NULL);
    ft_init(staticline, &t);
    splitstatic(&t);
    staticline = t->newstatic;
    if (t->oldstatic != NULL)
        free(t->oldstatic);
    return (t->line);
}
