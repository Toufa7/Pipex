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


char	*cmd_path(char *av[], char **env)
{
	int i;
	char *path;
	char *join;
	char **envi;
	int is_there;

	path = find_path(env);
	envi = ft_split(path, ':');
	i = 0;
	while (envi[i])
	{
		join = ft_strsjoin(envi[i],"/", av[1]);
		is_there = access(join, X_OK);
		if (is_there == 0)
		{
			return (join);
		}
		i++;
	}
	return (NULL);
}

/* Creating a Child and start executing the command passed av[1] by the path return it befor */

void	run(char *av[], char **env)
{
	pid_t pid;
	int status;
	int ret;
	char *cmd = cmd_path(av, env);

	pid = fork();
	if (pid == 0)
	{
		printf("Well i'm a Child\n");
		printf("Executing %s\n",cmd);
        printf("-----------------------\n");
		ret = execve(cmd, &av[1], env);
		if (ret == -1)
		{
			perror("ERRRRORRRR");
		}
		printf("--------DONE--------\n");
		return ;
	}
	else
	{
		pid = waitpid(pid, &status, 0);

	}
	printf("Parent pid = %d\n",getpid());
    printf("Child pid = %d , Return status : %d\n", pid, WEXITSTATUS(status));

}

int	main(int ac, char *argv[], char **env)
{
	if (ac > 0)
	{
		run(argv, env);
		// printf("Ur Path -> %s\n",cmd_path(argv, env));
	}
}
