/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:14:44 by denya             #+#    #+#             */
/*   Updated: 2019/02/25 00:00:22 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int vslidate_str(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == ' ' || buf[i] == '\t' || (buf[i] >= '0'
		&& buf[i] <= '9') || (buf[i] >= 'A' && buf[i] <= 'F')
		|| buf[i] == 'x' || buf[i] == ',' || buf[i] == '\n')
			i++;
		else
			return (-1);
		i++;
	}
	return (0);
}

int validate_hard(char *buf)
{
	int y;
	int c_len_num;

	y = 0;
	while (buf[y])
	{
		c_len_num = 0;
		if (buf[y] == 'x')
		{
			if (buf[y] && buf[y - 1] != '0' && buf[y - 2] != ',')
				return (3);
			while (buf[++y] && ((buf[y] >= 'A' && buf[y] <= 'F') 
			|| (buf[y] >= '0' && buf[y] <= '9' )))
				c_len_num++;
			if (c_len_num < 3 || c_len_num > 7)
				return (3);
			c_len_num = 0;
		}
		else
			y++;
	}
	if (buf[y - 1] == ' ')
		return (3);
	return (0);
}
