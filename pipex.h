#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char	*ft_strsjoin(char const *s1, char const *s2, char const *s3);
char	*ft_strstr(const char *haystack, const char *needle);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif