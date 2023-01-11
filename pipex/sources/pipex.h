#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

char	*get_path(char *cmd, char **env);
void	end_process(char *av, char **env);
void	error(char *str);

#endif
