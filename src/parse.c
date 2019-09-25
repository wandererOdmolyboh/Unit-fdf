/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 00:34:27 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/01 14:48:16 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		addone_parse(int *y, int *x, int *i)
{
	(*y) = 0;
	(*x) = 0;
	(*i) = 0;
}

static void		help_parser(t_point *matrix, char *string, int *x, int *i)
{
	while (string[(*i)] == '\n')
		(*i)++;
	matrix[(*x)].check = 1;
	(*x) = 0;
}

static void		help_parse(t_point *matrix, char *string, int *y, int *x)
{
	matrix[(*x)].d_x = (*x) * SIZE;
	matrix[(*x)].d_y = (*y) * SIZE;
	matrix[(*x)].d_z = ft_atoi(string) * SIZE;
	matrix[(*x)].color = ft_comma(string);
	matrix[(*x)].check = 0;
	(*x)++;
}

int				func_parse_stroke(t_fdf *fdf, char *string)
{
	int			i;
	int			y;
	int			x;

	addone_parse(&y, &x, &i);
	while (string[i])
	{
		while (string[i] == ' ' || string[i] == '\t')
			i++;
		if (string[i] && string[i] == '\n')
		{
			help_parser(fdf->matrix[y], string, &x, &i);
			y++;
		}
		if (string[i] && ((string[i] >= '0' && string[i] <= '9') ||
		string[i] == '-' || string[i] == '+'))
			help_parse(fdf->matrix[y], &string[i++], &y, &x);
		while (string[i] && ((string[i] >= '0' && string[i] <= '9') ||
		(string[i] >= 'a' && string[i] <= 'f') ||
		string[i] == ',' || string[i] == 'x' || (string[i] >=
		'A' && string[i] <= 'F')))
			i++;
	}
	window(fdf);
	return (0);
}
