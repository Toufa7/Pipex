/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:59:39 by otoufah           #+#    #+#             */
/*   Updated: 2022/04/13 17:00:26 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		a;
	size_t		b;
	char		*hay;

	hay = (char *)haystack;
	if (needle[0] == 0)
		return (hay);
	a = 0;
	while (hay[a])
	{
		b = 0;
		while (hay[a + b] == needle[b])
		{
			if (needle[b + 1] == 0)
				return (&hay[a]);
			b++;
		}
		a++;
	}
	return (NULL);
}
