/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:08:20 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/01 13:25:06 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	initial(t_fdf *fdf, double scaling, int x, int y)
{
	fdf->matrix[y][x].d_x = fdf->matrix[y][x].d_x * scaling;
	fdf->matrix[y][x].d_y = fdf->matrix[y][x].d_y * scaling;
	fdf->matrix[y][x].d_z = fdf->matrix[y][x].d_z * scaling;
	fdf->matrix[y][x].x = fdf->matrix[y][x].x * scaling;
	fdf->matrix[y][x].y = fdf->matrix[y][x].y * scaling;
	fdf->matrix[y][x].z = fdf->matrix[y][x].z * scaling;
}

int				scales(t_fdf *fdf)
{
	int			y;
	int			x;
	double		scaling1;

	if (fdf->scaling < 0.8)
		return (0);
	scaling1 = 0.5;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	y = -1;
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x].check != 1)
			initial(fdf, scaling1, x, y);
	}
	fdf->scaling -= SCALE;
	orisovka(fdf);
	return (0);
}

int				scaleb(t_fdf *fdf)
{
	int			y;
	int			x;
	double		scaling2;

	if (fdf->scaling > 1.2)
		return (0);
	scaling2 = 2;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	y = -1;
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x].check != 1)
			initial(fdf, scaling2, x, y);
	}
	fdf->scaling += SCALE;
	orisovka(fdf);
	return (0);
}
