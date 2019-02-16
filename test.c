/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:32:53 by wanderer          #+#    #+#             */
/*   Updated: 2019/02/16 16:55:53 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <mlx.h>
#include <stdlib.h>
// #include <X.h>
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
			fdf->matrix[y][x].x = fdf->scaling * (fdf->matrix[y][x].d_x * cos(fdf->anglY) + fdf->matrix[y][x].d_z * sin(fdf->anglY));
			fdf->matrix[y][x].z = fdf->scaling * (fdf->matrix[y][x].d_z * cos(fdf->anglY) - fdf->matrix[y][x].d_x * sin(fdf->anglY));				
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
            fdf->matrix[y][x].y = fdf->scaling * (fdf->matrix[y][x].d_y  * cos(fdf->anglX) - fdf->matrix[y][x].d_z  * sin(fdf->anglX));
            fdf->matrix[y][x].z = fdf->scaling * (fdf->matrix[y][x].d_z  * cos(fdf->anglX) + fdf->matrix[y][x].d_y  * sin(fdf->anglX));
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
        fdf->anglX += ANGLE;
    else
        fdf->anglX -=ANGLE;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {

            fdf->matrix[y][x].x = fdf->matrix[y][x].x * cos(fdf->anglX) +
            fdf->matrix[y][x].y * sin(fdf->anglX);
            fdf->matrix[y][x].y = fdf->matrix[y][x].x * sin(fdf->anglX) +
            fdf->matrix[y][x].y * cos(fdf->anglX);
        }
    }
    orisovka(fdf);
    return (0);
}


int		scale(t_fdf *fdf, int scale)
{
	int y;
    int x;

	if (scale)
        fdf->scaling += 10;
    else
        fdf->scaling -= 10;
    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {
			fdf->matrix[y][x].x = fdf->matrix[y][x].d_x * fdf->scaling * SCALE;
			fdf->matrix[y][x].y = fdf->matrix[y][x].d_y * fdf->scaling * SCALE;
			fdf->matrix[y][x].z = fdf->matrix[y][x].d_z * fdf->scaling * SCALE;
        }
    }
	orisovka(fdf);
	return (0);
}

int		rotate_dop(t_fdf *fdf)
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
			fdf->matrix[y][x].y = ((19 * 10) / 2) + 10 * fdf->matrix[y][x].d_y -((11 * 10) / 2) * cos(fdf->anglX) + 10 *  fdf->matrix[y][x].d_z * sin(fdf->anglX);
        }
    }
	orisovka(fdf);
	return (0);
}
void deafult_state(t_fdf *fdf)
{
	int x;
	int y;

	x = -1;
	y = -1;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->anglX = 0;
	fdf->anglY = 0;
	fdf->scaling = 20;
	while (fdf->matrix[++y])
	{
		x = 0;
		while (x < 19)
		{
			fdf->matrix[y][x].y = fdf->scaling * fdf->matrix[y][x].d_y;
			fdf->matrix[y][x].x = fdf->scaling * fdf->matrix[y][x].d_x;
			fdf->matrix[y][x].z = fdf->scaling * fdf->matrix[y][x].d_z;
			x++;
		}	
	}
    orisovka(fdf);
}

int manegment_control(int KeyCode, t_fdf *fdf)
{
	 if (KeyCode == D || KeyCode == RIGHT)
	 	rotate_Y(fdf, TRUE);
	else if (KeyCode == A || KeyCode == LEFT)
	 	rotate_Y(fdf, FALSE);
	else if (KeyCode == S || KeyCode == DOWN)
	 	rotate_X(fdf, FALSE);
	else if (KeyCode == W || KeyCode == UP)
	  	rotate_X(fdf, TRUE);
	else if (KeyCode == Q)
	 	rotate_dop(fdf);
	else if (KeyCode == SPACE)
		deafult_state(fdf);
	else if (KeyCode == PLUS)
		scale(fdf, TRUE);
	else if (KeyCode == MINUS && fdf->scaling > 0)
		scale(fdf, FALSE);
	else if (KeyCode == ESC)
		exit(0);
	else if (KeyCode == C)
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	return (0);
}

void myabe(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
    fdf->win_ptr = mlx_new_window (fdf->mlx_ptr,V, H, "Why?" );

    mlx_hook(fdf->win_ptr, 2, 1L<<1, &manegment_control, fdf);
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
//	if (vslidate_str(string) || validate_hard(string))
//		return (-1);
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
    fdf->anglX = 0;
	fdf->anglY = 0;
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
	system("leaks -q a.aut");
	return (0);
}