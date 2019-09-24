/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 23:22:59 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/08 10:35:26 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		initialmatrix(t_fdf *fdf, t_point **matrix, int n)
{
	matrix[n] = NULL;
	fdf->matrix = matrix;
	fdf->anglx = 0;
	fdf->angly = 0;
	fdf->anglz = 0;
	fdf->len_y = n;
}

static int		new_check_func(char *s)
{
	char		*checker;

	checker = ft_strrchr(s, '\n');
	if (checker[0] && checker[1])
		return (FALSE);
	return (TRUE);
}

void			addone_elem(char **s, char **s1)
{
	free_leeks(s);
	free_leeks(s1);
}

int				count_elem(char **line)
{
	t_lekerro	norma;

	norma.check = -1;
	if (ft_strchr(*line, '\n') && new_check_func(*line))
	{
		norma.one = ft_strsplit(*line, '\n');
		norma.two = ft_strsplit(norma.one[0], ' ');
		while (norma.two[++norma.check])
			;
		norma.i = -1;
		while (norma.one[++norma.i])
		{
			norma.j = -1;
			free_leeks(norma.two);
			norma.two = ft_strsplit(norma.one[norma.i], ' ');
			while (norma.two[++norma.j])
				;
			if (norma.j != norma.check)
				return (-2);
		}
		addone_elem(norma.two, norma.one);
		return (norma.check);
	}
	ft_putstr("must endl \\n !");
	return (-2);
}

int				creat_matrix(char **line)
{
	t_point		**matrix;
	t_fdf		*fdf;
	int			n;
	int			y;
	int			len;

	if (vslidate_str(*line) == 3 || validate_hard(*line) == 3)
		return (-1);
	if ((len = count_elem(&(*line)) + 1) < 0)
		return (error_output(NULL, 0, FALSE));
	y = 0;
	if ((fdf = (t_fdf *)malloc(sizeof(t_fdf))) == NULL)
		return (-1);
	n = count_new_line(*line);
	matrix = (t_point **)malloc(sizeof(t_point *) * (n + 1));
	while (y < n)
	{
		matrix[y] = (t_point*)malloc(sizeof(t_point) * len);
		y++;
	}
	initialmatrix(fdf, matrix, n);
	func_parse_stroke(fdf, *line);
	return (0);
}
