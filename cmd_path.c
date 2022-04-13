#include "pipex.h"

char	*cmd_path(char *cmd, char **env)
{
	int i;
	char *path;
	char *join;
	char **envi;
	int is_there;

	path = find_path(env);
	envi = ft_split(path, ':');
	i = 0;
	while (envi[i])
	{
		join = ft_strsjoin(envi[i],'/', cmd);
		is_there = access(join, X_OK);
		if (is_there == 0)
		{
			printf("--> %s\n",join);
			return (join);
		}
		else
			free(join);
		i++;
	}
	return (NULL);
}