/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:00:03 by otoufah           #+#    #+#             */
/*   Updated: 2022/04/13 17:04:33 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strsjoin(char const *s1, char s2, char const *s3)
{
	char	*join;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0 || s3 == 0)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s3) + 2));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		join[j++] = s1[i++];
	if (s2 != '\0')
		join[j++] = s2;
	i = 0;
	while (s3[i] != '\0')
		join[j++] = s3[i++];
	join[j] = '\0';
	return (join);
}
