#include "pipex.h"

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

char	*get_path(char *cmd, char **env)
{
	char	**all_paths;
	char	*path;
	int		i;
	char	*slash;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	all_paths = ft_split(env[i] + 5, ':');
	i = 0;
	if(cmd[0] == '.')
	{
        if (access(cmd, F_OK | X_OK) == 0)
            return cmd;
    }
	while (all_paths[i])
	{
		slash = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(slash, cmd); 
		free(slash);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (all_paths[++i])
		free(all_paths[i]);
	free(all_paths);
	return (0);
}

void	end_process(char *av, char **env)
{
	char	**cmd;
	int 	i;
	char	*path;
	
	i = -1;
	cmd = ft_split(av, ' ');
	path = get_path(cmd[0], env);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error("Error ");
	}
	if (execve(path, cmd, env) == -1)
		error("Error ");
}
