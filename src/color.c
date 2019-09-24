/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:33:51 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/01 13:40:01 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	int	check_value(char str, int *color, int *power)
{
	if (str == 'A' || str == 'a')
		*color = *color + 10 * pow(16, (*power));
	else if (str == 'B' || str == 'b')
		*color = *color + 11 * pow(16, (*power));
	else if (str == 'C' || str == 'c')
		*color = *color + 12 * pow(16, (*power));
	else if (str == 'D' || str == 'd')
		*color = *color + 13 * pow(16, (*power));
	else if (str == 'E' || str == 'e')
		*color = *color + 14 * pow(16, (*power));
	else if (str == 'F' || str == 'f')
		*color = *color + 15 * pow(16, (*power));
	(*power)++;
	return (*color);
}

static	int	color_found(char *str)
{
	int		i;
	int		color;
	char	*s;
	int		power;

	s = NULL;
	power = 0;
	color = 0;
	i = 2;
	while (str[i] && i < 8)
		i++;
	while (i-- > 2)
	{
		if ((str[i] >= 'A' && str[i] <= 'F')
		|| (str[i] >= 'a' && str[i] <= 'f'))
			check_value(str[i], &color, &(power));
		else
		{
			s = ft_strsub(&str[i], 0, 1);
			color += ft_atoi(s) * pow(16, power++);
			free(s);
		}
	}
	return (color);
}

int			ft_comma(char *string)
{
	int		i;
	char	*leaks;

	leaks = NULL;
	i = 0;
	while (string[i] && (string[i] >= '0' && string[i] <= '9'))
		i++;
	if (string[i] != ',')
		return (16777215);
	else
	{
		leaks = ft_strsub(string + i, 1, 9);
		i = color_found(leaks);
		free(leaks);
		return (i);
	}
}
