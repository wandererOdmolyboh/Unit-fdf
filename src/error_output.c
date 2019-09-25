/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:25:18 by ashypilo          #+#    #+#             */
/*   Updated: 2019/04/01 12:41:58 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	error_output(char **argv, int argc, int ch)
{
	if (!ch)
		ft_putstr("error\n");
	else if (ch == 2)
		ft_putstr("file doesn't exists or cannot be opened\n");
	else if (ch == 3)
	{
		ft_putstr("you must input 1800 < Horizontal > 100 and ");
		ft_putstr("1800 < Vertiacal > 10\n");
		close(argc);
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" source_file\n");
	}
	return (0);
}
