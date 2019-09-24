/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 04:11:34 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/01 15:26:23 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double			value(double x1, double x2)
{
	int			rez;

	rez = x2 - x1;
	if (rez < 0)
		rez = -rez;
	return (rez);
}

static	void	line1(t_fdf *fdf, t_point matrix1, t_point matrix2, t_nor norma)
{
	norma.d = -norma.lengthx;
	while (norma.length--)
	{
		norma.color = grad(matrix1, matrix2, norma);
		if ((norma.x + norma.c) > 0 && (norma.x + norma.c) < V
		&& (norma.y + norma.d1) > 0 && (norma.y + norma.d1) < H)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, norma.x + norma.c,
		norma.y + norma.d1, norma.color);
		norma.x += norma.dx;
		norma.d += 2 * norma.lengthy;
		if (norma.d > 0)
		{
			norma.d -= 2 * norma.lengthx;
			norma.y += norma.dy;
		}
	}
}

static	void	line2(t_fdf *fdf, t_point matrix1, t_point matrix2, t_nor norma)
{
	norma.d = -norma.lengthy;
	while (norma.length--)
	{
		norma.color = grad(matrix1, matrix2, norma);
		if ((norma.x + norma.c) > 0 && (norma.x + norma.c) < V &&
		(norma.y + norma.d1) > 0 && (norma.y + norma.d1) < H)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (norma.x + norma.c),
		norma.y + norma.d1, norma.color);
		norma.y += norma.dy;
		norma.d += 2 * norma.lengthx;
		if (norma.d > 0)
		{
			norma.d -= 2 * norma.lengthy;
			norma.x += norma.dx;
		}
	}
}

void			line(t_fdf *fdf, t_point matrix1, t_point matrix2)
{
	t_nor		norma;

	norma.c = V / 4;
	norma.d1 = H / 4;
	norma.dx = (matrix2.x - matrix1.x >= 0 ? 1 : -1);
	norma.dy = (matrix2.y - matrix1.y >= 0 ? 1 : -1);
	norma.lengthx = value(matrix1.x, matrix2.x);
	norma.lengthy = value(matrix1.y, matrix2.y);
	norma.length = (norma.lengthx > norma.lengthy ? norma.lengthx :
	norma.lengthy) + 1;
	norma.x = matrix1.x;
	norma.y = matrix1.y;
	if (norma.lengthy <= norma.lengthx)
		line1(fdf, matrix1, matrix2, norma);
	else
		line2(fdf, matrix1, matrix2, norma);
}

void			orisovka(t_fdf *fdf)
{
	int			x;
	int			y;

	y = -1;
	if ((fdf->matrix[0][0].d_x + V / 4) > 0 && (fdf->matrix[0][0].d_x + V / 4)
	< V && (fdf->matrix[0][0].d_y + H / 4) > 0 && (fdf->matrix[0][0].d_y +
	H / 4) < H)
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->matrix[0][0].d_x + V / 4,
			fdf->matrix[0][0].d_y + H / 4, fdf->matrix[0][0].color);
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
	put_string(fdf);
}
