/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:58:39 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/03/15 13:14:36 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		rotate_Y(t_fdf *fdf, int direct)
{
	int	y;
	int	x;

	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	y = -1;
	if (direct)
		fdf->anglY += ANGLE;
	else
		fdf->anglY -= ANGLE;
	if (fdf->anglZ > 360 || fdf->anglZ < -360)
		fdf->anglZ = (double)((int)fdf->anglZ % 360);
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x].check != 1)
		{
			fdf->matrix[y][x].x = (fdf->matrix[y][x].d_x * cos(fdf->anglY)
			+ fdf->matrix[y][x].d_z * sin(fdf->anglY));
			fdf->matrix[y][x].z = (fdf->matrix[y][x].d_z * cos(fdf->anglY)
			- fdf->matrix[y][x].d_x * sin(fdf->anglY));
		}
	}
	orisovka(fdf);
	return (0);
}

int		rotate_X(t_fdf *fdf, int direct)
{
	int	y;
	int	x;

	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	y = -1;
	if (direct)
		fdf->anglX += ANGLE;
	else
		fdf->anglX -= ANGLE;
	if (fdf->anglZ > 360 || fdf->anglZ < -360)
		fdf->anglZ = (double)((int)fdf->anglZ % 360);
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x].check != 1)
		{
			fdf->matrix[y][x].y = (fdf->matrix[y][x].d_y * cos(fdf->anglX) - fdf->matrix[y][x].d_z * sin(fdf->anglX));
			fdf->matrix[y][x].z = (fdf->matrix[y][x].d_z * cos(fdf->anglX) + fdf->matrix[y][x].d_y * sin(fdf->anglX));
		}
	}
	orisovka(fdf);
	return (0);
}

int		rotate_dop(t_fdf *fdf)
{
	int y;
	int x;

	fdf->anglX -= ANGLE;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	y = -1;
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x].check != 1)
		{
			fdf->matrix[y][x].y = ((19 * fdf->scaling) / 2) +
			fdf->scaling * fdf->matrix[y][x].d_y - ((11 * fdf->scaling) / 2) *
			cos(fdf->anglX) + fdf->scaling * fdf->matrix[y][x].d_z
			* sin(fdf->anglX);
		}
	}
	orisovka(fdf);
	return (0);
}
