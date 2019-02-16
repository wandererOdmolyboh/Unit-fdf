/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   she_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:56:33 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/02/08 02:26:10 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <mlx.h>
#include <stdlib.h>

int func_parse_stroke (t_fdf *fdf, char *string);
char *ft_comma(char *string)
{
	int i;

	i = 0;

	while(string[i] && (string[i] >= '0' && string[i] <= '9' ))
		i++;
	if (string[i] != ',')
		return (ft_strdup("0xFFFFFF"));
	else
		return (ft_strdup(string + i + 1)); 
}


int vslidate_str(char *buf)
{
    int i;

    i = 0;
    while(buf[i])
    {
        if (buf[i] == ' ' || buf[i] == '\t' || (buf[i] >= '0' && buf[i] <= '9')
        || (buf[i] >= 'A' && buf[i] <= 'F')
        || buf[i] == 'x' || buf[i] == ',' || buf[i] == '\n')
            i++;
        else
            return(-1);
        i++;
    }
    return (0);
}

int validate_hard(char *buf)
{
    int y;
    int c_len_num;

    y = 0;
    while(buf[y])
    {
        c_len_num = 0;
        if (buf[y] == 'x')
        {
            if (buf[y] && buf[y - 1]!= '0' && buf[y - 2]!= ',')
                return (3);
            while(buf[y] && ((buf[y]>= 'A' && buf[y] <= 'F') 
            || (buf[y] >= '0' && buf[y] <= '9' )))
                c_len_num++;
            if (c_len_num < 2 || c_len_num > 6)
                return (3);
            c_len_num = 0;
        }
        y++;
    }
        if (buf[y - 1] == ' ')
            return (3);
    return (0);
}

double value(double x1, double x2)
{
	int rez;
	rez = x2 - x1;
	if (rez < 0)
		rez = -rez;
	return (rez);
}

void line(void *mlx_ptr, void *win_ptr, double x1, double y1, double x2, double y2)
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
    	double c, d1;

	c = H/4 + 12/2; 
	d1 = V/4 + 19/2;

	dx = (x2 - x1 >= 0 ? 1 : -1);
	dy = (y2 - y1 >= 0 ? 1 : -1);
	lengthX = value(x1, x2);
	lengthY = value(y1, y2);
	length = (lengthX > lengthY ? lengthX : lengthY) + 1;
    if (length == 1)
        mlx_pixel_put(mlx_ptr, win_ptr,  x1,   y1, 0x111000);
    x = x1;
    y = y1;
	//функция
	if (lengthY <= lengthX)
    {
        d = -lengthX;
        while(length--)
        {
             mlx_pixel_put(mlx_ptr, win_ptr,  x + c,   y + d1, 0xFF3333);
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
             mlx_pixel_put(mlx_ptr, win_ptr,  x + c,   y + d1, 0xFF3333);
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

int		rotate_Y(t_fdf *fdf)
{
	int y;
    int x;

    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {
			fdf->matrix[y][x].x = ( (19 * 10) / 2) + ((10 * fdf->matrix[y][x].d_x  - ((19 * 10) / 2)) * cos(fdf->angl) + (10 *fdf->matrix[y][x].d_z) * sin(fdf->angl));
			fdf->matrix[y][x].z = ( (19 * 10) / 2) + ((10 * fdf->matrix[y][x].d_z) * cos(fdf->angl)) - (((19 * 10) / 2) - 10 *fdf->matrix[y][x].d_x) * sin(fdf->angl);				
        }
    }
	y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 18)
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y][x + 1].x, fdf->matrix[y][x + 1].y);
    }  
    x = -1;
    while (++x < 19)
    {
        y = -1;
        while (fdf->matrix[++y + 1])
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y + 1][x].x, fdf->matrix[y + 1][x].y);
	}
    fdf->angl +=0.13;
	return (0);
}

int		rotate_YY(t_fdf *fdf)
{
	int y;
    int x;

    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {
			fdf->matrix[y][x].x = ((19 * 10) / 2) + (((10 * fdf->matrix[y][x].d_x  - ((19 * 10) / 2)) * cos(fdf->angl) + (10 *fdf->matrix[y][x].d_z) * sin(fdf->angl)));
			fdf->matrix[y][x].z = ((19 * 10) / 2) + (((10 * fdf->matrix[y][x].d_z) * cos(fdf->angl)) - (((19 * 10) / 2) - 10 *fdf->matrix[y][x].d_x) * sin(fdf->angl));				
        }
    }
	y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 18)
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y][x + 1].x, fdf->matrix[y][x + 1].y);
    }  
    x = -1;
    while (++x < 19)
    {
        y = -1;
        while (fdf->matrix[++y + 1])
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y + 1][x].x, fdf->matrix[y + 1][x].y);
	}
    fdf->angl -=0.13;
	return (0);
}

int		rotate_X(t_fdf *fdf)
{
	int y;
    int x;

    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {
			fdf->matrix[y][x].y = ( (11 * 10) / 2) + ((10 * fdf->matrix[y][x].d_y  - ((11 * 10) / 2)) * cos(fdf->angl) + (10 *fdf->matrix[y][x].d_z) * sin(fdf->angl));
        }
    }
	y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 18)
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y][x + 1].x, fdf->matrix[y][x + 1].y);
    }  
    x = -1;
    while (++x < 19)
    {
        y = -1;
        while (fdf->matrix[++y + 1])
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y + 1][x].x, fdf->matrix[y + 1][x].y);
	}
    fdf->angl +=0.13;
	return (0);
}

int		rotate_XX(t_fdf *fdf)
{
	int y;
    int x;

    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {
			fdf->matrix[y][x].y = ( (11 * 10) / 2) + ((10 * fdf->matrix[y][x].d_y  - ((11 * 10) / 2)) * cos(fdf->angl) + (10 *fdf->matrix[y][x].d_z) * sin(fdf->angl));
        }
    }
	y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 18)
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y][x + 1].x, fdf->matrix[y][x + 1].y);
    }  
    x = -1;
    while (++x < 19)
    {
        y = -1;
        while (fdf->matrix[++y + 1])
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y + 1][x].x, fdf->matrix[y + 1][x].y);
	}
    fdf->angl -=0.13;
	return (0);
}

void deafult_state(t_fdf *fdf)
{
	int x;
	int y;

	x = -1;
	y = -1;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	while (fdf->matrix[++y])
	{
		x = 0;
		while (x < 19)
		{
			fdf->matrix[y][x].y = 10 * fdf->matrix[y][x].d_y;
			fdf->matrix[y][x].x = 10 * fdf->matrix[y][x].d_x;
			fdf->matrix[y][x].z = 10 * fdf->matrix[y][x].d_z;
			x++;
		}	
	}
	y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 18)
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y][x + 1].x, fdf->matrix[y][x + 1].y);
    }  
    x = -1;
    while (++x < 19)
    {
        y = -1;
        while (fdf->matrix[++y + 1])
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y + 1][x].x, fdf->matrix[y + 1][x].y);
	}
}

int manegment_control(int KeyCode, t_fdf *fdf)
{
	if (KeyCode == D)
		rotate_X(fdf);
	else if (KeyCode == A)
	 	rotate_XX(fdf);
	else if (KeyCode == S)
		rotate_YY(fdf);
	else if (KeyCode == W)
		rotate_Y(fdf);
	else if (KeyCode == SPACE)
		deafult_state(fdf);
	else if (KeyCode == ESC)
		exit(0);
	return (0);
}

void myabe(t_fdf *fdf)
{

	double angl;
	int y;
	int x;
	fdf->mlx_ptr = mlx_init();
    fdf->win_ptr = mlx_new_window (fdf->mlx_ptr,V, H, "Why?" );
	angl = 3.14/6;
	y = -1;
	while (fdf->matrix[++y])
	{
		x = 0;
		while (x < 19)
		{
			fdf->matrix[y][x].y = 10 * fdf->matrix[y][x].d_y;
			fdf->matrix[y][x].x = 10 * fdf->matrix[y][x].d_x;
			x++;
		}	
	}
	y = -1;
	while (fdf->matrix[++y + 2])
	{
		x = -1;
		while (++x < 18)
			line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y][x + 1].x, fdf->matrix[y][x + 1].y);
	}
	x = -1;
	while (++x < 19)
	{
		y = -1;
		while (fdf->matrix[++y + 2])
			line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y + 1][x].x, fdf->matrix[y + 1][x].y);
	}
    mlx_hook(fdf->win_ptr, 2, 3, &manegment_control, fdf);
	mlx_loop(fdf->mlx_ptr);
}


int func_parse_stroke (t_fdf *fdf, char *string)
{
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	if (vslidate_str(string) || validate_hard(string))
		return (-1);
	while(string[i])
	{
		while(string[i] == ' ' || string[i] == '\t')
			i++;
		if (string[i] == '\n')
		{
			while(string[i] == '\n')
				i++;
			y++;
			x = 0;
		}
		if ((string[i] >= '0' && string[i] <= '9'))
		{
			fdf->matrix[y][x].d_x = x;
			fdf->matrix[y][x].d_y = y;
			fdf->matrix[y][x].d_z = ft_atoi(&string[i]);
			fdf->matrix[y][x].color = ft_comma(&string[i]);
			x++;
			i++;
		}
		while(string[i] && ( (string[i] >= '0' && string[i] <= '9') || string[i] ==',' || 
		(string[i] >= 'A' && string[i] <= 'F')))
			i++;		
	}
	myabe(fdf);
	return (0);
}

int	creat_matrix(char *line) ///////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	t_point **matrix;
	t_fdf   *fdf;
	int n;
	int y;

	y = 0;
    fdf = (t_fdf *)malloc(sizeof(t_fdf));
	n = count_new_line(line);
	matrix = (t_point **)malloc(sizeof(t_point *) * (n + 1));
	while(y < n)
	{
		matrix[y] = (t_point*)malloc(sizeof(t_point) * 19);
		y++;
	}
	matrix[n] = NULL;
    fdf->matrix = matrix;
    fdf->angl = 0;
	fdf->len_y = n;
	func_parse_stroke(fdf ,line);
	return (0);
}

int count_new_line(char *line)
{
    int count;
    int i;

    i = 0;
    count = 0;
    while (line[i++])
        if(line[i] == '\n')
            count++;
    return (count);
}

int func_read(int fd)
{
	char    *line = NULL;
	int     len;
	char    *buf;
	char	*leaks;

	if ((buf = (char *)malloc(BUFF_SIZE + 1)) == NULL)
		return ((-1));
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[len] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	creat_matrix(line);
	free(line);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		argc = open(argv[1], O_RDONLY);
		if ((argc = func_read(argc)) != 0)
			return  (error_output(argv, FALSE));// add to func params argc
		close(argc);
	}
	else 
		return (error_output(argv, TRUE));
	return (0);
}

			    // fdf->matrix[y][x].y = ((11 * 10) / 2) + (((10 * fdf->matrix[y][x].d_y  - ((11 * 10) / 2)) * cos(3.14/4) + (fdf->matrix[y][x].z) * sin(3.14/4)));
				// fdf->matrix[y][x].z = ((19 * 10) / 2) + (((10 * fdf->matrix[y][x].z) * cos(3.14/4)) - (((19 * 10) / 2) - 10 *fdf->matrix[y][x].d_y) * sin(3.14/4));
				// px = (x * z) / (z * dist);
				// py = (y * z) / (z * dist);

				// 				По оси Z
				// x'=x*cos(L)-y*sin(L);
				// y'=y*cos(L) - x*sin(L);             zzzzzz
                // fdf->matrix[y][x].x = 10 * (fdf->matrix[y][x].d_x + (fdf->matrix[y][x].d_x * cos(fdf->angl) - fdf->matrix[y][x].d_y * sin(fdf->angl)));
                // fdf->matrix[y][x].y = 10 * (fdf->matrix[y][x].d_y + (fdf->matrix[y][x].d_y * cos(fdf->angl) - fdf->matrix[y][x].d_x * sin(fdf->angl)));

					// 				По оси Y
					// x'=x*cos(L)+z*sin(L);
					// y'=y;
					// z'=-x*sin(L)+z*cos(L);