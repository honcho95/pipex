#include "pipex.h"

/* Child process that run inside a fork, take the filein, put the output inside
 a pipe and then close with the exec function */
void	child(char **av, char **env, int *fd)
{
	int		infile;

	infile = open(av[1], O_RDONLY, 0644); //0777 grants all permissions IF file is created by the call of the open function
	if (infile == -1) // open failed
		error("Error : Wasn't able to open the infile");
	dup2(fd[1], STDOUT_FILENO); // fd[1] becomes our stdout (write to fd[1] the output of cmd1) 1 = STDOUT
	dup2(infile, STDIN_FILENO); // infile becomes stdin
	close(fd[0]);
	end_process(av[2], env);
}

/* Parent process that take the data from the pipe, change the output for the
 fileout and also close with the exec function */
void	parent(char **av, char **env, int *fd)
{
	int		outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644); // 0_CREAT = create the file if it doesnt exist, 0_TRUNC erases whatever it contains if it does exist
	if (outfile == - 1)
		error("Error : Wasn't able to open the outfile");
	dup2(fd[0], STDIN_FILENO); // fd[0] becomes stdin (fd[0] reads from fd[1] the output of cmd1) 0 = STDIN
	dup2(outfile, STDOUT_FILENO); // outfile becomes stdout (write to outfile the output of cmd2)
	close(fd[1]);
	end_process(av[3], env);
}

/* Main function that run the child and parent process or display an error
 message if arguments are wrong */
int	main(int ac, char **av, char **env)
{
	int		fd[2]; //two file descriptors (write and read)
	pid_t	pid; //process ID

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error("Error : Wasn't able to create the pipe");
        pid = fork();
		if (pid < 0) //creation of child process unsuccessful
			error("Error : Fork failed");
		if (pid == 0) // newly created child process
			child(av, env, fd);
		waitpid(pid, NULL, 0);
		parent(av, env, fd);
	}
	else
		ft_putstr_fd("Correct input : ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	return (0);
}
