#include "pipex.h"

int	main(int argc, char	*argv[], char *envp[])
{
	if (argc != 5)

/*ft_split to get the command args*/

char	*get_cmd_path(char *cmd, char *envp[])
{
	char	*path_env;
	char	**paths;
	char	*cmd_path;
	char	*temp;
	int	i;

	path_env = NULL;
	i = 0;
	while(envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env = envp[i] + 5;
			break ;
		}
		i++;
	}
	paths = ft_split(path_env, ':');
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin

