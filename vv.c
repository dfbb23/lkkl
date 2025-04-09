void ft_free(char *buff, char *new){

	write(2, "Error\n Error read read_line\n", 28);
    if(buff)
	    free(buff);
    if(new)
        free(new);
	exit(1);

}

char	*read_line(int fd, char *new,char *buff)
{
	char	*temp;
	ssize_t	n;
	while (1)
	{
		n = read(fd, buff,1);
		if (n == -1)
            ft_free(4,buff);
		if (n == 0)
			break ;
		buff[n] = '\0';
		if (!new)
			new = ft_strdup(buff);
            if(!new)
                error_line(4,buff);
		else
		{
			temp = ft_strjoin(new, buff);
            free(new);
            if(!temp)
                error_line(4,buff);
			new = temp;
		}
	}
	return (free(buff), new);
}
