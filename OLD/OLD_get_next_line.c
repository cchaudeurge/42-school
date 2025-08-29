char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*buffer;

	if (fd < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	next_line = NULL;
	while (read(fd, buffer, BUFFER_SIZE) == BUFFER_SIZE)
	{

}

/* Adds the first n characters of a string (str) at the end of a malloced
string (current_line) by creating a new malloced string and frees the
current_line string) */
char	*add2current_line(char *current_line, char *str, size_t n)
{
	char	*sum_str;
	int		i;
	int		j;

	i = 0;
	sum_str = (char *)malloc(strlen(current_line) + n + 1);
	if (!sum_str)
		return (NULL);
	if (!current_line)
	{
		copynchars(sum_str, str, n);
		sum_str[n] = '\0';
		return (sum_str);
	}
	copynchars(sum_str, current_line, strlen(current_line));
	copynchars(sum_str + strlen(current_line), str, n);
	sum_str[strlen(current_line) + n] = '\0';
	free(current_line);
	return (sum_str);
}

void	copynchars(char *dest, char *src, size_t n)
{
		while (n--)
			*(dest++) = *(src++);
}

size_t	strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int

size_t	findNL(char *str, size_t n)
{
	
	if (!str || n == 0)
		return (0);
}
