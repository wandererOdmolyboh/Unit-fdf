/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:32:13 by denya             #+#    #+#             */
/*   Updated: 2019/02/16 16:50:04 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H
# define R 0.0174533

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <mlx.h>

typedef	struct	s_point
{
	double			d_x;
	double			d_y;
	double			d_z;
	double			x;
	double			y;
	double			z;
	char			*color;
	int				check;

}				t_point;

typedef	struct	s_fdf
{

	void 		*mlx_ptr;
	void 		*win_ptr;
	t_point 	**matrix;
	double		anglX;
	double		anglY;
	int			len_y;
	int			len_x;
	int			scaling;

}				t_fdf;

# define BUFF_SIZE 60
// # define D_COLOR ft_strsub("0xFFFFFF");
# define TRUE 1
# define FALSE 0

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

# define C 8

# define Q 12
# define E 14

# define PLUS 69
# define MINUS 78

# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124

# define SPACE 49
# define ANGLE 0.02
# define SCALE 1.2


# define ALPHA 15
# define V 1800
# define H 1200

int validate_hard(char *buf);
int vslidate_str(char *buf);
void create_list(char *line);
int error_output(char **argv, int ch);
int count_new_line(char *line);
int **create_matrix(char *line, int len);
int *create_element_matrix(char *stroke);
int count_element(char *element);
int matrix_povorota(t_point *point, int angle);
void orisovka(t_fdf *fdf);



#endif