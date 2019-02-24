/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:21:55 by wanderer          #+#    #+#             */
/*   Updated: 2019/02/24 18:27:16 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		rotate_Y(t_fdf *fdf, int direct)
{
	int y;
    int x;

    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
     if (direct)
        fdf->anglY += ANGLE;
    else
        fdf->anglY -=ANGLE;
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {
			fdf->matrix[y][x].x = (fdf->matrix[y][x].d_x * cos(fdf->anglY) + fdf->matrix[y][x].d_z * sin(fdf->anglY));
			fdf->matrix[y][x].z = (fdf->matrix[y][x].d_z * cos(fdf->anglY) - fdf->matrix[y][x].d_x * sin(fdf->anglY));				
        }
    }
	orisovka(fdf);
	return (0);
}

int		rotate_X(t_fdf *fdf, int direct)
{
	int y;
    int x;

    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
     if (direct)
        fdf->anglX += ANGLE;
    else
        fdf->anglX -=ANGLE;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {
            fdf->matrix[y][x].y = (fdf->matrix[y][x].d_y  * cos(fdf->anglX) - fdf->matrix[y][x].d_z  * sin(fdf->anglX));
            fdf->matrix[y][x].z = (fdf->matrix[y][x].d_z  * cos(fdf->anglX) + fdf->matrix[y][x].d_y  * sin(fdf->anglX));
        }
    }
	orisovka(fdf);
	return (0);
}

int     rotate_Z(t_fdf *fdf, int direct)
{
    int y;
    int x;

    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    if (direct)
        fdf->anglZ += ANGLE;
    else
        fdf->anglZ -=ANGLE;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {

            fdf->matrix[y][x].x = fdf->matrix[y][x].x * cos(fdf->anglZ) +
            fdf->matrix[y][x].y * sin(fdf->anglZ);
            fdf->matrix[y][x].y = fdf->matrix[y][x].x * sin(fdf->anglZ) +
            fdf->matrix[y][x].y * cos(fdf->anglZ);
        }
    }
    orisovka(fdf);
    return (0);
}

int		rotate_dop(t_fdf *fdf)
{
	int y;
    int x;
    fdf->anglX -=ANGLE;
     mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {
			fdf->matrix[y][x].y = ((19 * fdf->scaling) / 2) +
            fdf->scaling * fdf->matrix[y][x].d_y - ((11 * fdf->scaling) / 2) *
            cos(fdf->anglX) + fdf->scaling *  fdf->matrix[y][x].d_z *
            sin(fdf->anglX);
        }
    }
	orisovka(fdf);
	return (0);
}
