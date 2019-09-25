/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:58:39 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/08 11:13:36 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		rotate_x(t_fdf *fdf, int direct)
{
	int	y;
	int	x;

	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	y = -1;
	fdf->angly += direct ? ANGLE : -ANGLE;
	if (fdf->angly > 360 || fdf->angly < -360)
		fdf->angly = (double)((int)fdf->angly % 360);
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x].check != 1)
		{
			fdf->matrix[y][x].x = (fdf->matrix[y][x].d_x * cos(fdf->angly)
			+ fdf->matrix[y][x].d_z * sin(fdf->angly));
			fdf->matrix[y][x].z = (fdf->matrix[y][x].d_z * cos(fdf->angly)
			- fdf->matrix[y][x].d_x * sin(fdf->angly));
		}
	}
	orisovka(fdf);
	return (0);
}

int		rotate_y(t_fdf *fdf, int direct)
{
	int	y;
	int	x;

	y = -1;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->anglx += direct ? ANGLE : -ANGLE;
	if (fdf->anglx > 360 || fdf->anglx < -360)
		fdf->anglx = (double)((int)fdf->anglx % 360);
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x].check != 1)
		{
			fdf->matrix[y][x].y = (fdf->matrix[y][x].d_y * cos(fdf->anglx) -
			fdf->matrix[y][x].d_z * sin(fdf->anglx));
			fdf->matrix[y][x].z = (fdf->matrix[y][x].d_z * cos(fdf->anglx) +
			fdf->matrix[y][x].d_y * sin(fdf->anglx));
		}
	}
	orisovka(fdf);
	return (0);
}

int		rotate_dop(t_fdf *fdf)
{
	int y;
	int x;

	fdf->anglx -= ANGLE;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	y = -1;
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x].check != 1)
		{
			fdf->matrix[y][x].y = ((19 * fdf->scaling) / 2) +
			fdf->scaling * fdf->matrix[y][x].d_y - ((11 * fdf->scaling) / 2) *
			cos(fdf->anglx) + fdf->scaling * fdf->matrix[y][x].d_z
			* sin(fdf->anglx);
		}
	}
	orisovka(fdf);
	return (0);
}
