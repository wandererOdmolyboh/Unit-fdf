/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:11:51 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/03/15 13:16:51 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		shift_Y(t_fdf *fdf, int direct)
{
	int		y;
	int		x;
	double	shift;

	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	if (direct)
		shift = 2;
	else
		shift = -2;
	y = -1;
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x].check != 1)
		{
			fdf->matrix[y][x].d_y = fdf->matrix[y][x].d_y + shift;
			fdf->matrix[y][x].y = fdf->matrix[y][x].y + shift;
		}
	}
	orisovka(fdf);
	return (0);
}

int		shift_X(t_fdf *fdf, int direct)
{
	int		y;
	int		x;
	double	shift;

	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	if (direct)
		shift = 2;
	else
		shift = -2;
	y = -1;
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x].check != 1)
		{
			fdf->matrix[y][x].d_x = fdf->matrix[y][x].d_x + shift;
			fdf->matrix[y][x].x = fdf->matrix[y][x].x + shift;
		}
	}
	orisovka(fdf);
	return (0);
}
