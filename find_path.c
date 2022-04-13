#include "pipex.h"

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