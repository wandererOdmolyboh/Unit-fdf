/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:10:52 by wanderer          #+#    #+#             */
/*   Updated: 2019/07/03 11:57:38 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_string(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 10,
	16000, "Rotation fdf --- > W/S/A/D");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 25,
	16000, "Shift fdf --- > UP/DOWN/LEFT/RIGHT");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 40,
	16000, "Exit --- > Esc");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 55,
	16000, "Clear --- > C");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 70,
	16000, "Zoom --- > +/-");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 85,
	16000, "Change color --- > 1/2");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 100,
	16000, "Proection --- > 3/4");
}
