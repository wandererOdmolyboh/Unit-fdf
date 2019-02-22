/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 04:11:34 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/02/22 13:43:13 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double value(double x1, double x2)
{
	int rez;
	rez = x2 - x1;
	if (rez < 0)
		rez = -rez;
	return (rez);
}

static void line(void *mlx_ptr, void *win_ptr, double x1, double y1, double x2, double y2, int color1, int color2)
{
	///структуры!
    double dx;
    double dy;
    double lengthX;
    double lengthY;
    double length;
	double x;
	double y;
	double d;
    double c, d1;//
    int color;

    color = color2 - color1;

	c = H/4 + 19/2; 
	d1 = V/4 + 12/2;

	dx = (x2 - x1 >= 0 ? 1 : -1);
	dy = (y2 - y1 >= 0 ? 1 : -1);
	lengthX = value(x1, x2);
	lengthY = value(y1, y2);
	length = (lengthX > lengthY ? lengthX : lengthY) + 1;
    if (length == 1)
        mlx_pixel_put(mlx_ptr, win_ptr,  x1,   y1, 0x111000);
    x = x1;
    y = y1;

    color = color / length;
	//функция
	if (lengthY <= lengthX)
    {
        d = -lengthX;
        while(length--)
        {
            color1 += color;
             mlx_pixel_put(mlx_ptr, win_ptr,  x + c,   y + d1, color1);
            x += dx;
            d += 2 * lengthY;
            if (d > 0)
            {
                d -= 2 * lengthX;
                y += dy;
            }
        }
    }
    else
    {
        d = - lengthY;
        while(length--)
        {
            color1 += color;
             mlx_pixel_put(mlx_ptr, win_ptr,  x + c,   y + d1, color1);
            y += dy;
            d += 2 * lengthX;
            if (d > 0)
            {
                d -= 2 * lengthY;
                x += dx;
            }
        }
    }
}

void orisovka(t_fdf *fdf)
{
	int x;
	int y;

	y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 18)
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y][x + 1].x, fdf->matrix[y][x + 1].y, fdf->matrix[y][x].color, fdf->matrix[y][x + 1].color);
    }  
    x = -1;
    while (++x < 19)
    {
        y = -1;
        while (fdf->matrix[++y + 1])
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y + 1][x].x, fdf->matrix[y + 1][x].y, fdf->matrix[y][x].color, fdf->matrix[y + 1][x].color);
	}
}