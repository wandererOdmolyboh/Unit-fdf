/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:11:51 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/04 09:56:49 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			addone_shifty(t_fdf *fdf, int direct, double *shift)
{
	if (direct)
	{
		if (fdf->matrix[0][0].d_y + H / 4 > H &&
		fdf->matrix[0][0].y + H / 4 > H)
			return (FALSE);
		(*shift) = 2;
	}
	else
	{
		if (fdf->matrix[0][0].d_y + H / 4 < 0 &&
		fdf->matrix[0][0].y + H / 4 < 0)
			return (FALSE);
		(*shift) = -2;
	}
	return (TRUE);
}

int			addone_shiftx(t_fdf *fdf, int direct, double *shift)
{
	if (direct)
	{
		if (fdf->matrix[0][0].d_x + V / 4 > V
		&& fdf->matrix[0][0].x + V / 4 > V)
			return (FALSE);
		(*shift) = 2;
	}
	else
	{
		if (fdf->matrix[0][0].d_x + V / 4 < 0
		&& fdf->matrix[0][0].x + V / 4 < 0)
			return (FALSE);
		(*shift) = -2;
	}
	return (TRUE);
}

int			shift_y(t_fdf *fdf, int direct)
{
	int		y;
	int		x;
	double	shift;

	if (addone_shifty(fdf, direct, &shift) == FALSE)
		return (FALSE);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
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

int			shift_x(t_fdf *fdf, int direct)
{
	int		y;
	int		x;
	double	shift;

	if (addone_shiftx(fdf, direct, &shift) == FALSE)
		return (FALSE);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
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

void		deafult_state(t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->anglx = 0;
	fdf->angly = 0;
	fdf->scaling = 1;
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x].check != 1)
		{
			fdf->matrix[y][x].y = fdf->scaling * fdf->matrix[y][x].d_y;
			fdf->matrix[y][x].x = fdf->scaling * fdf->matrix[y][x].d_x;
			fdf->matrix[y][x].z = fdf->scaling * fdf->matrix[y][x].d_z;
		}
	}
	orisovka(fdf);
}
