/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:32:53 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/03 10:11:21 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			count_new_line(char *line)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (line[i++])
		if (line[i] == '\n')
			count++;
	return (count);
}

int			func_read(int fd)
{
	char	*line;
	int		len;
	char	*buf;
	char	*leaks;

	line = NULL;
	if ((buf = (char *)malloc(BUFF_SIZE + 1)) == NULL)
		return ((-1));
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[len] = '\0';
		leaks = line;
		line = ft_strjoin(line, buf);
		free(leaks);
	}
	free(buf);
	if (!(line) || ft_strlen(line) == 0 || creat_matrix(&line) == -1)
	{
		free(line);
		ft_putstr("file empty or another Error\n");
		return (-1);
	}
	free(line);
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		argc = open(argv[1], O_RDONLY);
		if (argc == -1)
			return (error_output(argv, argc, 2));
		else if (H < 100 && H > 1800 && V < 100 && V > 1800)
			return (error_output(argv, argc, 3));
		else if ((argc = func_read(argc)) != 0)
			return (error_output(argv, argc, FALSE));
		close(argc);
	}
	else
		return (error_output(argv, argc, TRUE));
	return (0);
}
