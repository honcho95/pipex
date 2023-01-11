#include "pipex.h"

/* Function that will look for the path line inside the environment, will
 split and test each command path and then return the right one. */
char	*get_path(char *cmd, char **env)
{
	char	**all_paths;
	char	*path;
	int		i;
	char	*path_slash;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0) // find "PATH" 
		i++;
	all_paths = ft_split(env[i] + 5, ':'); // +5 is to start after "PATH:"
	i = 0;
	while (all_paths[i])
	{
		path_slash = ft_strjoin(all_paths[i], "/"); // ass slash for proper path
		path = ft_strjoin(path_slash, cmd); // add the command
		free(path_slash);
		if (access(path, F_OK) == 0) // verify if it exists
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


/* Function that take the command and send it to find_path
 before executing it. */
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
		perror("Error");
        exit(1);
	}
	if (execve(path, cmd, env) == -1)
    {
		perror("Error");
        exit(1);
    }
}
