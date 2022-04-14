/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:16:38 by otoufah           #+#    #+#             */
/*   Updated: 2022/04/13 17:03:59 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cmd_path(char *cmd, char **env)
{
	int		i;
	int		is_there;
	char	*path;
	char	*join;
	char	**envi;

	path = find_path(env);
	envi = ft_split(path, ':');
	i = 0;
	while (envi[i])
	{
		join = ft_strsjoin(envi[i], '/', cmd);
		is_there = access(join, X_OK);
		if (is_there == 0)
		{
			return (join);
		}
		else
			free(join);
		i++;
	}
	return (cmd);
}
