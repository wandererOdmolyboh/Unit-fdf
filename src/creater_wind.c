/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creater_wind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:12:08 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/07/03 11:55:47 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			closer(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void		window(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, V, H, "__F_D_F_42__");
	deafult_state(fdf);
	put_string(fdf);
	mlx_hook(fdf->win_ptr, 2, 1L << 1, &manegment_control, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, closer, fdf);
	mlx_loop(fdf->mlx_ptr);
}
