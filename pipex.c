/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:16:52 by otoufah           #+#    #+#             */
/*   Updated: 2022/04/13 17:01:39 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closing(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	first_cmd(char **env, char *av[], int fd1, int *pipe)
{
	char	**spl;
	char	*cmd;

	spl = ft_split(av[2], ' ');
	cmd = cmd_path(spl[0], env);
	dup2(fd1, 0);
	dup2(pipe[1], 1);
	close(fd1);
	closing(pipe);
	execve(cmd, spl, env);
	exit(0);
}

void	second_cmd(char **env, char *av[], int fd2, int *pipe)
{
	char	**spl;
	char	*cmd;

	spl = ft_split(av[3], ' ');
	cmd = cmd_path(spl[0], env);
	dup2(pipe[0], 0);
	dup2(fd2, 1);
	close(fd2);
	closing(pipe);
	execve(cmd, spl, env);
	exit(0);
}

void	data_flow(char *av[], char **env)
{
	int		fildes[2];

	pipe(fildes);
	if (pipe(fildes) == -1)
	{
		perror("Error\n");
	}
	pid._1 = fork();
	if (pid._1 == 0)
	{
		fd._1 = open(av[1], O_RDONLY);
		first_cmd(env, av, fd._1, fildes);
	}
	pid._2 = fork();
	if (pid._2 == 0)
	{
		fd._2 = open(av[4], O_CREAT | O_RDWR, 0777);
		second_cmd(env, av, fd._2, fildes);
	}
	closing(fildes);
	waitpid(pid._1, NULL, 0);
	waitpid(pid._2, NULL, 0);
}	

int	main(int ac, char *argv[], char **env)
{
	if (ac > 0)
	{
		data_flow(argv, env);
	}
}
