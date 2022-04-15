/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:14:38 by otoufah           #+#    #+#             */
/*   Updated: 2022/04/15 02:14:39 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup2_error(const char *s)
{
	perror(s);
	exit (EXIT_FAILURE);
}

void	execve_error(char *av[], int n)
{
	perror(av[n]);
	exit (EXIT_FAILURE);
}

void	opening_error(char *av[], int n)
{
	perror(av[n]);
	exit (EXIT_FAILURE);
}

void	pipe_error(const char *s)
{
	perror(s);
	exit (EXIT_FAILURE);
}

void	forking_error(const char *s)
{
	perror(s);
	exit (EXIT_FAILURE);
}

void	closing_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}
