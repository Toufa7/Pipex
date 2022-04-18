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

void	data_flow(char *av[], char **env)
{
	int		fildes[2];

	pipe(fildes);
	if (pipe(fildes) == -1)
		pipe_error("Pipe Failed");
	pid._1 = fork();
	if (pid._1 < 0)
		forking_error("No child process is created");
	if (pid._1 == 0)
	{
		fd._1 = open(av[1], O_RDONLY, 0777);
		if (fd._1 == -1)
			opening_error(av, 1);
		first_cmd(env, av, fd._1, fildes);
	}
	pid._2 = fork();
	if (pid._2 < 0)
		forking_error("No child process is created");
	if (pid._2 == 0)
	{
		second_cmd(env, av, fd._2, fildes);
	}
	closing_fd(fildes);
	if (waitpid(pid._1, NULL, 0) == -1)
		waitpid_error("Waitpid error");
	if (waitpid(pid._2, NULL, 0) == -1)
		waitpid_error("Waitpid error");
}
