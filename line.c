/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 04:11:34 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/03/15 13:21:28 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			value(double x1, double x2)
{
	int	rez;

	rez = x2 - x1;
	if (rez < 0)
		rez = -rez;
	return (rez);
}

static	void	line1(t_fdf *fdf, t_nor norma)
{
	norma.d = -norma.lengthX;
	while (norma.length--)
	{
		norma.color_next += norma.color;
		if ((norma.x + norma.c) > 0 && (norma.x + norma.c) < V
		&& (norma.y + norma.d1) > 0 && (norma.y + norma.d1) < H)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, norma.x + norma.c,
		norma.y + norma.d1, norma.color_next);
		norma.x += norma.dx;
		norma.d += 2 * norma.lengthY;
		if (norma.d > 0)
		{
			norma.d -= 2 * norma.lengthX;
			norma.y += norma.dy;
		}
	}
}

static	void	line2(t_fdf *fdf, t_nor norma)
{
	norma.d = -norma.lengthY;
	while (norma.length--)
	{
		norma.color_next += norma.color;
		if ((norma.x + norma.c) > 0 && (norma.x + norma.c) < V &&
		(norma.y + norma.d1) > 0 && (norma.y + norma.d1) < H)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (norma.x + norma.c),
		norma.y + norma.d1, norma.color_next);
		norma.y += norma.dy;
		norma.d += 2 * norma.lengthX;
		if (norma.d > 0)
		{
			norma.d -= 2 * norma.lengthY;
			norma.x += norma.dx;
		}
	}
}

void			line(t_fdf *fdf, t_point matrix1, t_point matrix2)
{
	t_nor		norma;
	int			step;

	step = sqrt(pow(value(matrix1.x, matrix2.x), 2) + pow(value(matrix1.y,
	matrix2.y), 2));
	norma.color = matrix2.color - matrix1.color;
	norma.c = V / 4;
	norma.d1 = H / 4;
	norma.dx = (matrix2.x - matrix1.x >= 0 ? 1 : -1);
	norma.dy = (matrix2.y - matrix1.y >= 0 ? 1 : -1);
	norma.lengthX = value(matrix1.x, matrix2.x);
	norma.lengthY = value(matrix1.y, matrix2.y);
	norma.length = (norma.lengthX > norma.lengthY ? norma.lengthX :
	norma.lengthY) + 1;
	norma.x = matrix1.x;
	norma.y = matrix1.y;
	norma.color_next = matrix1.color;
	norma.color = step == 0 ? norma.color : (int)(norma.color / step);
	if (norma.lengthY <= norma.lengthX)
		line1(fdf, norma);
	else
		line2(fdf, norma);
}

void			orisovka(t_fdf *fdf)
{
	int			x;
	int			y;

	y = -1;
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x + 1].check != 1)
			line(fdf, fdf->matrix[y][x], fdf->matrix[y][x + 1]);
	}
	y = 0;
	x = -1;
	while (fdf->matrix[y][++x].check != 1)
	{
		y = -1;
		while (fdf->matrix[++y + 1])
			line(fdf, fdf->matrix[y + 1][x], fdf->matrix[y][x]);
	}
}
