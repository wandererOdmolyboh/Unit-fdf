/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:25:18 by ashypilo          #+#    #+#             */
/*   Updated: 2019/01/31 17:30:17 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int error_output(char **argv, int ch)
{
	if (!ch)
	{
		ft_putstr("error\n");
	}
	else 
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" source_file\n");
	}
	return (0);
	/// добавить очистку! и переделать функцию!
}
