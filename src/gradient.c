/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 15:59:36 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/01 16:20:00 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	percent(int start, int end, int current)
{
	double		place;
	double		dist;

	place = current - start;
	dist = end - start;
	return ((dist == 0) ? 1.0 : (place / dist));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				grad(t_point matrix1, t_point matrix2, t_nor norma)
{
	int			red;
	int			green;
	int			blue;
	double		percentage;

	if (matrix1.color == matrix2.color)
		return (matrix1.color);
	if (value(matrix1.x, matrix2.x) > value(matrix1.y, matrix2.y))
		percentage = percent(matrix1.x, matrix2.x, norma.x);
	else
		percentage = percent(matrix1.y, matrix2.y, norma.y);
	red = get_light((matrix1.color >> 16) & 0xFF, (matrix2.color >> 16) & 0xFF,
	percentage);
	green = get_light((matrix1.color >> 8) & 0xFF, (matrix2.color >> 8) & 0xFF,
	percentage);
	blue = get_light(matrix1.color & 0xFF, matrix2.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
