/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:14:44 by denya             #+#    #+#             */
/*   Updated: 2019/04/08 11:14:54 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	addone_probel(char *s, int *y)
{
	while (s[*y] == ' ' || s[*y] == '\t' || s[*y] == '\n')
		(*y)++;
	return (FALSE);
}

static int	check_znak(char *s)
{
	if ((s[0]) && (s[0] == '-' || s[0] == '+'))
		if ((s[1]) && (s[1] == '-' || s[1] == '+'))
			return (TRUE);
	return (FALSE);
}

int			vslidate_str(char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == ' ' || buf[i] == '\t' || (buf[i] >= '0'
		&& buf[i] <= '9') || (buf[i] >= 'A' && buf[i] <= 'F') ||
		buf[i] == 'x' || buf[i] == ',' || (buf[i] >= 'a' && buf[i] <= 'f')
		|| buf[i] == '\n' || buf[i] == '-' || buf[i] == '+')
			i++;
		else
			return (3);
		i++;
	}
	return (0);
}

static int	func_hardaddone(char *buf, int *y, int *c_len_num)
{
	(*y)++;
	if (buf[(*y)++] != '0')
		return (3);
	if (buf[(*y)++] != 'x')
		return (3);
	while (buf[(*y)] && ((buf[(*y)] >= 'A' && buf[(*y)] <= 'F')
	|| (buf[(*y)] >= 'a' && buf[(*y)] <= 'f') ||
	(buf[(*y)] >= '0' && buf[(*y)] <= '9')))
	{
		(*c_len_num)++;
		(*y)++;
	}
	if ((*c_len_num) < 1 || (*c_len_num) > 7)
		return (3);
	return (0);
}

int			validate_hard(char *buf)
{
	int		y;
	int		c_len_num;

	y = 0;
	while (buf[y])
	{
		c_len_num = 0;
		if (buf[y] == ',')
		{
			if (func_hardaddone(buf, &y, &c_len_num) == 3)
				return (3);
		}
		else if (check_znak(&buf[y]))
			return (3);
		else if (addone_probel(buf, &y))
			return (3);
		else if ((buf[y] < '0' || buf[y] > '9') && (buf[y] != 32
		|| buf[y] != '\t' || buf[y] != '\n') && buf[y] != '\0')
			return (3);
		else
			y++;
	}
	if (buf[y - 1] == ' ')
		return (3);
	return (0);
}
