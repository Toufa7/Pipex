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
	int		duplicate_1;
	int		duplicate_2;

	spl = ft_split(av[3], ' ');
	cmd = cmd_path(spl[0], env);
	duplicate_1 = dup2(fd2, STDOUT_FILENO);
	if (duplicate_1 == -1)
		dup2_error("Failed to duplicate the oldfd\n");
	duplicate_2 = dup2(pipe[0], STDIN_FILENO);
	if (duplicate_2 == -1)
		dup2_error("Failed to duplicate the oldfd\n");
	close(fd2);
	closing_fd(pipe);
	if (execve(cmd, spl, env) == -1)
		execve_error(av, 3);
	exit(EXIT_SUCCESS);
}
