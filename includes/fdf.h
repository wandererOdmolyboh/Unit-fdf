/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:29:52 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/07/03 11:56:01 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef	struct	s_point
{
	double		d_x;
	double		d_y;
	double		d_z;
	double		x;
	double		y;
	double		z;
	int			color;
	int			check;
}				t_point;

typedef	struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_point		**matrix;
	double		anglx;
	double		angly;
	double		anglz;
	int			len_y;
	int			len_x;
	double		scaling;
}				t_fdf;

typedef	struct	s_nor
{
	double		dx;
	double		dy;
	double		lengthx;
	double		lengthy;
	double		length;
	double		x;
	double		y;
	double		d;
	double		c;
	double		d1;
	int			color;
	int			color_next;
	int			step1;
}				t_nor;

typedef	struct	s_lekerro
{
	char		**one;
	char		**two;
	int			check;
	int			i;
	int			j;
}				t_lekerro;

# define BUFF_SIZE 60
# define TRUE 1
# define FALSE 0

# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define E 14
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124

# define C 8
# define SPACE 49
# define ESC 53
# define P 35
# define PLUS 69
# define MINUS 78
# define NUMB1 18
# define NUMB2 19
# define NUMB3 20
# define NUMB4 21
# define X 7

# define ANGLE 0.02
# define SCALE 0.1
# define SIZE 15

# define ALPHA 15
# define V 2000
# define H 1600

int				rotate_x(t_fdf *fdf, int direct);
int				rotate_y(t_fdf *fdf, int direct);
int				shift_y(t_fdf *fdf, int direct);
int				shift_x(t_fdf *fdf, int direct);
int				scaleb(t_fdf *fdf);
int				scales(t_fdf *fdf);
int				closer(void *param);
int				validate_hard(char *buf);
int				vslidate_str(char *buf);
int				error_output(char **argv, int argc, int ch);
int				count_new_line(char *line);
int				**create_matrix(char *line, int len);
int				*create_element_matrix(char *stroke);
int				rotate_dop(t_fdf *fdf);
int				count_element(char *element);
int				matrix_povorota(t_point *point, int angle);
int				ft_comma(char *string);
void			orisovka(t_fdf *fdf);
int				func_parse_stroke (t_fdf *fdf, char *string);
void			line(t_fdf *fdf, t_point matrix1, t_point matrix2);
int				grad(t_point matrix1, t_point matrix2, t_nor norma);
double			value(double x1, double x2);
int				manegment_control(int keycode, t_fdf *fdf);
void			deafult_state(t_fdf *fdf);
void			put_string(t_fdf *fdf);
void			change_coloros(t_fdf *fdf);
void			change_color(t_fdf *fdf);
void			free_leeks(char **leaks);
int				creat_matrix(char **line);
void			window(t_fdf *fdf);
void			free_leeks(char **leaks);
void			proection_oy(t_fdf *fdf);
void			proection_ox(t_fdf *fdf);

#endif
