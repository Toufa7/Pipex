/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:17:01 by otoufah           #+#    #+#             */
/*   Updated: 2022/04/13 16:58:14 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

struct s_fildescriptor
{
	int	_1;
	int	_2;
}	fd;

struct s_processes_ids
{
	pid_t	_1;
	pid_t	_2;
}	pid;

char	*cmd_path(char *cmd, char **env);
char	*find_path(char **env);
char	*ft_strsjoin(char const *s1, char s2, char const *s3);
char	*ft_strstr(const char *haystack, const char *needle);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
