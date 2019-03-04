/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:46:01 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/03/04 18:50:27 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		scaleS(t_fdf *fdf)// отдельныи функции
{
	int y;
    int x;

    printf ("S == sc1 == %f || sc2 == %f\n", fdf->scaling, fdf->scaling);
    if (fdf->scaling < 0.8)
        return (0);
    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (fdf->matrix[y][++x].check != 1)
        {
			fdf->matrix[y][x].d_x = fdf->matrix[y][x].d_x * fdf->scaling1;
			fdf->matrix[y][x].d_y = fdf->matrix[y][x].d_y * fdf->scaling1;
			fdf->matrix[y][x].d_z = fdf->matrix[y][x].d_z * fdf->scaling1;
			fdf->matrix[y][x].x = fdf->matrix[y][x].x * fdf->scaling1;
			fdf->matrix[y][x].y = fdf->matrix[y][x].y * fdf->scaling1;
			fdf->matrix[y][x].z = fdf->matrix[y][x].z * fdf->scaling1;
        }
    }
    fdf->scaling -= SCALE;

	orisovka(fdf);
	return (0);
}

int		scaleB(t_fdf *fdf)// отдельныи функции
{
	int y;
    int x;
    
     printf ("B == sc1 == %f || sc2 == %f\n", fdf->scaling, fdf->scaling);
    if (fdf->scaling > 1.2)
        return (0);
    
    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (fdf->matrix[y][++x].check != 1)
        {
			fdf->matrix[y][x].d_x = fdf->matrix[y][x].d_x * fdf->scaling2;
			fdf->matrix[y][x].d_y = fdf->matrix[y][x].d_y * fdf->scaling2;
			fdf->matrix[y][x].d_z = fdf->matrix[y][x].d_z * fdf->scaling2;
			fdf->matrix[y][x].x = fdf->matrix[y][x].x * fdf->scaling2;
			fdf->matrix[y][x].y = fdf->matrix[y][x].y * fdf->scaling2;
			fdf->matrix[y][x].z = fdf->matrix[y][x].z * fdf->scaling2;
        }
    }
     fdf->scaling += SCALE;
	orisovka(fdf);
	return (0);
}