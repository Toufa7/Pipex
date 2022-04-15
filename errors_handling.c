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
