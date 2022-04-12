#include "../pipex.h"

char	*ft_strsjoin(char const *s1, char const *s2, char const *s3)
{
	char	*join;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0 || s3 == 0)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		join[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		join[j++] = s2[i++];
	}
	i = 0;
	while (s3[i] != '\0')
	{
		join[j++] = s3[i++];
	}
	join[j] = '\0';
	return (join);
}