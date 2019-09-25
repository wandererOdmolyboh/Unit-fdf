/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:34:37 by dmolyboh          #+#    #+#             */
/*   Updated: 2018/11/14 23:25:33 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	a;
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		z = i;
		a = 0;
		if (needle[a] == haystack[i])
			while (needle[a] == haystack[i]
					&& (needle[a] != '\0' || haystack[i] != '\0'))
			{
				i++;
				a++;
			}
		i = z;
		if (needle[a] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
