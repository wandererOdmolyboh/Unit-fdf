/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:32:53 by wanderer          #+#    #+#             */
/*   Updated: 2019/03/15 15:06:20 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

void	deafult_state(t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->anglX = 0;
	fdf->anglY = 0;
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

int		manegment_control(int KeyCode, t_fdf *fdf)
{
	if (KeyCode == D)
		rotate_Y(fdf, TRUE);
	else if (KeyCode == A)
		rotate_Y(fdf, FALSE);
	else if (KeyCode == S)
		rotate_X(fdf, FALSE);
	else if (KeyCode == W)
		rotate_X(fdf, TRUE);
	else if (KeyCode == P)
		rotate_dop(fdf);
	else if (KeyCode == SPACE)
		deafult_state(fdf);
	else if (KeyCode == PLUS)
		scaleB(fdf);
	else if (KeyCode == MINUS)
		scaleS(fdf);
	else if (KeyCode == C)
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	else if (KeyCode == RIGHT)
		shift_X(fdf, TRUE);
	else if (KeyCode == LEFT)
		shift_X(fdf, FALSE);
	else if (KeyCode == UP)
		shift_Y(fdf, FALSE);
	else if (KeyCode == DOWN)
		shift_Y(fdf, TRUE);
	else if (KeyCode == ESC)
		exit(0);
	return (0);
}

void	myabe(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, V, H, "__F_D_F_42__");
	deafult_state(fdf);
	mlx_hook(fdf->win_ptr, 2, 1L << 1, &manegment_control, fdf);
	mlx_loop(fdf->mlx_ptr);
}

int		func_parse_stroke(t_fdf *fdf, char *string)
{
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 0;
	if (vslidate_str(string) || validate_hard(string))
		return (-1);
	while (string[i])
	{
		while (string[i] == ' ' || string[i] == '\t')
			i++;
		if (string[i] == '\n')
		{
			while (string[i] == '\n')
				i++;
			fdf->matrix[y][x].check = 1;
			x = 0;
			y++;
		}
		if ((string[i] >= '0' && string[i] <= '9'))
		{
			fdf->matrix[y][x].d_x = x * SIZE;
			fdf->matrix[y][x].d_y = y * SIZE;
			fdf->matrix[y][x].d_z = ft_atoi(&string[i]) * SIZE;
			fdf->matrix[y][x].color = ft_comma(&string[i]);
			fdf->matrix[y][x].check = 0;
			x++;
			i++;
		}
		while (string[i] && ((string[i] >= '0' && string[i] <= '9') ||
		string[i] == ',' || string[i] == 'x' || (string[i] >=
		'A' && string[i] <= 'F')))
			i++;
	}
	myabe(fdf);
	return (0);
}

int	creat_matrix(char *line)
{
	t_point	**matrix;
	t_fdf	*fdf;
	int		n;
	int		y;

	y = 0;
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	n = count_new_line(line);
	matrix = (t_point **)malloc(sizeof(t_point *) * (n + 1));
	while (y < n)
	{
		matrix[y] = (t_point*)malloc(sizeof(t_point) * 19);
		y++;
	}
	matrix[n] = NULL;
	fdf->matrix = matrix;
	fdf->anglX = 0;
	fdf->anglY = 0;
	fdf->anglZ = 0;
	fdf->len_y = n;
	func_parse_stroke(fdf, line);
	return (0);
}

int		count_new_line(char *line)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (line[i++])
		if (line[i] == '\n')
			count++;
	return (count);
}

int	func_read(int fd)
{
	char	*line;
	int		len;
	char	*buf;
	char	*leaks;

	line = NULL;
	if ((buf = (char *)malloc(BUFF_SIZE + 1)) == NULL)
		return ((-1));
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[len] = '\0';
		leaks = line;
		line = ft_strjoin(line, buf);
		free(leaks);
	}
	free(buf);
	creat_matrix(line);
	free(line);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && H > 100 && V > 100)
	{
		argc = open(argv[1], O_RDONLY);
		if ((argc = func_read(argc)) != 0)
			return (error_output(argv, FALSE));
		close(argc);
	}
	else
		return (error_output(argv, TRUE));
	return (0);
}
