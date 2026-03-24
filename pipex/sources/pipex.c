#include "pipex.h"

int	main(int argc, char	*argv[], char *envp[])
{
	if (argc != 5)

}

void	pipex(int argc, char *argv[], char *envp[])
{

/*ft_split to get the command args*/

char	*get_cmd_path(char *cmd, char *envp[])
{
	char	**paths;
	char	*cmd_path;
	int	i;

	i = 0;
	while(envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(envp + 5, ':');
	if (!paths)
		//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
		clean_exit;
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin_sep(paths[i], cmd, "/");
		if (!cmd_path)
		//XXXXXXXXXXXXXXXX
		//free(paths);
			clean exit
		if (access(cmd_path, X_OK) == 0)
		{
			ft_free_str_array(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free_str_array(paths);
	return (NULL);
}


