/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:25:18 by ashypilo          #+#    #+#             */
/*   Updated: 2019/03/15 13:28:17 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error_output(char **argv, int ch)
{
	if (!ch)
	{
		ft_putstr("error\n");
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" source_file or you must input Horizontal > 100 and Vertiacal > 100\n");
	}
	return (0);
}
