/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:32:53 by wanderer          #+#    #+#             */
/*   Updated: 2019/02/24 20:15:44 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

int func_parse_stroke (t_fdf *fdf, char *string);


static int check_value(char str, int *color, int *power)
{
	if (str == 'A')
        *color = *color + 10  * pow(16, (*power));
    else if (str == 'B')
        *color = *color + 11  * pow(16, (*power));
    else if (str == 'C')
		*color = *color + 12  * pow(16, (*power));
    else if (str == 'D')
		*color = *color + 13  * pow(16, (*power));
    else if (str == 'E')
		*color = *color + 14  * pow(16, (*power));
    else if (str == 'F')
		*color = *color + 15  * pow(16, (*power));
    (*power)++;
	return (*color);
}

static int        color_found(char *str)
{
	int 	i;
    int		color;
    char	*s;
	int		power;
	power = 0;
    color = 0;
	i = 2;
	
    while (str[i] && i < 8)
        i++;
    while(i-- > 2)
    {
		if (str[i] >= 'A' && str[i] <= 'F')
			check_value(str[i], &color, &(power));
        else
        {
            s = ft_strsub(&str[i], 0, 1);
            color += ft_atoi(s) * pow(16, power++);	
        }
    }
    return (color);
}

int	ft_comma(char *string)
{
	int i;
	char *leaks;

	i = 0;
	while(string[i] && (string[i] >= '0' && string[i] <= '9' ))
		i++;
	if (string[i] != ',')
		return (16777215);
	else
	{
		leaks = ft_strsub(string + i, 1 , 9);
		i = color_found(leaks);
		free(leaks);
		return (i);
	}
}

int		scale(t_fdf *fdf, int scale)// отдельныи функции
{
	int y;
    int x;
	static double scaling = 1;


	if (scale)
        scaling += 0.3;
    else
        scaling -= 0.3;
	if (scaling > 2.3 || scaling < 0.7)
		return (0);
    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {
			fdf->matrix[y][x].d_x = fdf->matrix[y][x].d_x * scaling;
			fdf->matrix[y][x].d_y = fdf->matrix[y][x].d_y * scaling;
			fdf->matrix[y][x].d_z = fdf->matrix[y][x].d_z * scaling;
			fdf->matrix[y][x].x = fdf->matrix[y][x].d_x;
			fdf->matrix[y][x].y = fdf->matrix[y][x].d_y;
			fdf->matrix[y][x].z = fdf->matrix[y][x].d_z;
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
	fdf->scaling = 1;
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
    fdf->win_ptr = mlx_new_window (fdf->mlx_ptr,V, H, "__F_D_F_42__" );

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
		while(string[i] && ( (string[i] >= '0' && string[i] <= '9') || string[i] == ',' || string[i] == 'x'||
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
	int 	n;
	int 	y;

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