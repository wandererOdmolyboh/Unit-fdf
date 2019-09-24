/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manegment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:13:50 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/08 11:12:38 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	helper_control(int keycode, t_fdf *fdf)
{
	if (keycode == C)
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	else if (keycode == RIGHT)
		shift_x(fdf, TRUE);
	else if (keycode == LEFT)
		shift_x(fdf, FALSE);
	else if (keycode == UP)
		shift_y(fdf, FALSE);
	else if (keycode == DOWN)
		shift_y(fdf, TRUE);
	else if (keycode == NUMB3)
		proection_ox(fdf);
	else if (keycode == NUMB4)
		proection_oy(fdf);
	else if (keycode == NUMB1)
		change_color(fdf);
	else if (keycode == NUMB2)
		change_coloros(fdf);
}

int			manegment_control(int keycode, t_fdf *fdf)
{
	if (keycode == W)
		rotate_y(fdf, TRUE);
	else if (keycode == S)
		rotate_y(fdf, FALSE);
	else if (keycode == A)
		rotate_x(fdf, FALSE);
	else if (keycode == D)
		rotate_x(fdf, TRUE);
	else if (keycode == P)
		rotate_dop(fdf);
	else if (keycode == SPACE)
		deafult_state(fdf);
	else if (keycode == PLUS)
		scaleb(fdf);
	else if (keycode == MINUS)
		scales(fdf);
	else if (keycode == ESC)
		closer(fdf);
	else
		helper_control(keycode, fdf);
	return (0);
}
