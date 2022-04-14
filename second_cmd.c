/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:40:50 by otoufah           #+#    #+#             */
/*   Updated: 2022/04/14 15:40:51 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_cmd(char **env, char *av[], int fd2, int *pipe)
{
	char	**spl;
	char	*cmd;

	spl = ft_split(av[3], ' ');
	cmd = cmd_path(spl[0], env);
	dup2(pipe[0], 0);
	dup2(fd2, 1);
	close(fd2);
	closing_fd(pipe);
	if (execve(cmd, spl, env) == -1)
	{
		perror(av[3]);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
