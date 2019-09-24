/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:12:19 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/01 16:04:12 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	change_color(t_fdf *fdf)
{
	int x;
	int y;

	y = -1;
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x].check != 1)
			if (fdf->matrix[y][x].color < 16777216)
				fdf->matrix[y][x].color += 100;
	}
	orisovka(fdf);
}

void	change_coloros(t_fdf *fdf)
{
	int x;
	int y;

	y = -1;
	while (fdf->matrix[++y])
	{
		x = -1;
		while (fdf->matrix[y][++x].check != 1)
			if (fdf->matrix[y][x].d_z != 0)
				if (fdf->matrix[y][x].color < 16777215)
					fdf->matrix[y][x].color += 100;
	}
	orisovka(fdf);
}
