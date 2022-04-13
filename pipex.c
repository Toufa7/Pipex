#include "pipex.h"

/* This funtion well return the directories to be searched to find a command */

char	*find_path(char **env)
{
	int i = 0;
	char *path;

	path = "PATH=";
	while (env[i])
	{
		if (ft_strstr(env[i], path))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

/* Splitting the path by : and check it the command passed is located to some of the paths then return it */


/* Creating a Child and start executing the command passed av[1] by the path return it befor */


void	first_cmd(char **env, char *av[], int fd1, int *pipe)
{
	char **spl;
	char *cmd;

	spl = ft_split(av[2], ' ');
	cmd = cmd_path(spl[0], env);
	
	dup2(fd1, 0);
	dup2(pipe[1], 1);
	close(fd1);
	close(pipe[0]);
	close(pipe[1]);
	execve(cmd, spl, env);
}


void	second_cmd(char **env, char *av[], int fd2, int *pipe)
{
	char **spl;
	char *cmd;

	spl = ft_split(av[3], ' ');
	cmd = cmd_path(spl[0], env);

	dup2(pipe[0], 0);
	dup2(fd2, 1);
	close(fd2);
	close(pipe[0]);
	close(pipe[1]);
	execve(cmd, spl, env);
}
 
 
void	run(char *av[], char **env)
{
	pid_t pid_1;
	pid_t pid_2;
	int fd[2];
    int fd1 = open(av[1], O_RDONLY);
	int fd2 = open(av[4], O_CREAT | O_RDWR, 0777);

	pipe(fd);
	pid_1 = fork();
	if (pid_1 == 0)
	{
		first_cmd(env, av, fd1, fd);
		exit(1);
	}

	pid_2 = fork();
	if (pid_2 == 0)
	{
		second_cmd(env, av, fd2, fd);
		exit(1);
    }

	close(fd[0]);
	close(fd[1]);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);
}	

int	main(int ac, char *argv[], char **env)
{
	if (ac > 0)
	{
		run(argv, env);
		// printf("Ur Path -> %s\n",cmd_path(argv, env));
	}
}


