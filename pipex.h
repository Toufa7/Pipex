#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_list
{
	int		fd;
	pid_t   pid;
}	cmd;


char	*cmd_path(char *cmd, char **env);
char	*find_path(char **env);
char	*ft_strsjoin(char const *s1, char s2, char const *s3);
char	*ft_strstr(const char *haystack, const char *needle);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif