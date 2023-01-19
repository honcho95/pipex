#include "pipex.h"

void	child(char **av, char **env, int *fd)
{
	int		infile;

	infile = open(av[1], O_RDONLY, 0644);
	if (infile == -1)
		error("Error : Wasn't able to open the infile");
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	end_process(av[2], env);
}

void	parent(char **av, char **env, int *fd)
{
	int		outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == - 1)
		error("Error : Wasn't able to open the outfile");
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(outfile);
	end_process(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error("Error : Wasn't able to create the pipe");
        pid = fork();
		if (pid < 0)
			error("Error : Fork failed");
		if (pid == 0)
			child(av, env, fd);
		waitpid(pid, NULL, 0);
		parent(av, env, fd);
	}
	else
		ft_putstr_fd("Correct input : ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	return (0);
}
