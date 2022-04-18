/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:40:41 by otoufah           #+#    #+#             */
/*   Updated: 2022/04/15 02:06:26 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(char **env, char *av[], int fd1, int *pipe)
{
	char	**spl;
	char	*cmd;
	int		dup_1;
	int		dup_2;

	spl = ft_split(av[2], ' ');
	cmd = cmd_path(spl[0], env);
	dup_1 = dup2(fd1, STDIN_FILENO);
	if (dup_1 == -1)
		dup2_error("Failed to duplicate the oldfd\n");
	dup_2 = dup2(pipe[1], STDOUT_FILENO);
	if (dup_2 == -1)
		dup2_error("Failed to duplicate the oldfd\n");
	close(fd1);
	closing_fd(pipe);
	if (execve(cmd, spl, env) == -1)
		execve_error(av, 2);
	exit(0);
}
