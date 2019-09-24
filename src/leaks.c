/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:33:10 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/01 12:44:37 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_leeks(char **leaks)
{
	int i;

	i = -1;
	while (leaks[++i])
	{
		free(leaks[i]);
		leaks[i] = NULL;
	}
	free(leaks);
	leaks = NULL;
}
