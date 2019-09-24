/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_proe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:01:21 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/08 11:11:58 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		proection_ox(t_fdf *fdf)
{
	int		y;
	int		x;

	deafult_state(fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	y = -1;
	fdf->angly = ANGLE * 10;
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
}

void		proection_oy(t_fdf *fdf)
{
	int		y;
	int		x;

	deafult_state(fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	y = -1;
	fdf->anglx = ANGLE * 10;
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
}
