/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:40:41 by otoufah           #+#    #+#             */
/*   Updated: 2022/04/14 15:40:42 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(char **env, char *av[], int fd1, int *pipe)
{
	char	**spl;
	char	*cmd;

	spl = ft_split(av[2], ' ');
	cmd = cmd_path(spl[0], env);
	dup2(fd1, 0);
	dup2(pipe[1], 1);
	close(fd1);
	closing_fd(pipe);
	if (execve(cmd, spl, env) == -1)
	{
		perror(av[2]);
		exit(1);
	}
	exit(0);
}
