/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_flow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:40:33 by otoufah           #+#    #+#             */
/*   Updated: 2022/04/14 15:40:34 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	error(char *av[], int n)
{
	perror(av[n]);
	exit (EXIT_FAILURE);
}

void	pipe_error(const char *s)
{
	perror(s);
	exit (EXIT_FAILURE);
}

void	data_flow(char *av[], char **env)
{
	int		fildes[2];

	pipe(fildes);
	if (pipe(fildes) == -1)
		pipe_error("Pipe Failed");
	pid._1 = fork();
	if (pid._1 == 0)
	{
		fd._1 = open(av[1], O_RDONLY, 0777);
		if (fd._1 == -1)
			error(av, 1);
		first_cmd(env, av, fd._1, fildes);
	}
	pid._2 = fork();
	if (pid._2 == 0)
	{
		fd._2 = open(av[4], O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0777);
		if (fd._2 == -1)
			error(av, 4);
		second_cmd(env, av, fd._2, fildes);
	}
	closing_fd(fildes);
	waitpid(pid._1, NULL, 0);
	waitpid(pid._2, NULL, 0);
}
