/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WhyNot?.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:55:14 by wanderer          #+#    #+#             */
/*   Updated: 2019/02/24 23:12:52 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"


static int check_value(char str, int *color, int *power)
{
	if (str == 'A')
        *color = *color + 10  * pow(16, (*power));
    else if (str == 'B')
        *color = *color + 11  * pow(16, (*power));
    else if (str == 'C')
		*color = *color + 12  * pow(16, (*power));
    else if (str == 'D')
		*color = *color + 13  * pow(16, (*power));
    else if (str == 'E')
		*color = *color + 14  * pow(16, (*power));
    else if (str == 'F')
		*color = *color + 15  * pow(16, (*power));
    (*power)++;
	return (*color);
}

static int        color_found(char *str)
{
	int 	i;
    int		color;
    char	*s;
	int		power;
	power = 0;
    color = 0;
	i = 2;
	
    while (str[i] && i < 8)
        i++;
    while(i-- > 2)
    {
		if (str[i] >= 'A' && str[i] <= 'F')
			check_value(str[i], &color, &(power));
        else
        {
            s = ft_strsub(&str[i], 0, 1);
            color += ft_atoi(s) * pow(16, power++);	
        }
    }
    return (color);
}

int	ft_comma(char *string)
{
	int i;
	char *leaks;

	i = 0;
	while(string[i] && (string[i] >= '0' && string[i] <= '9' ))
		i++;
	if (string[i] != ',')
		return (16777215);
	else
	{
		leaks = ft_strsub(string + i, 1 , 9);
		i = color_found(leaks);
		free(leaks);
		return (i);
	}
}

int count_new_line(char *line)
{
    int count;
    int i;

    i = 0;
    count = 0;
    while (line[i++])
        if(line[i] == '\n')
            count++;
    return (count);
}

int funck_check(t_point **matrix)
{
    int x;
    int y;
    int len;
    int i;

    len = 0;
    x = -1;
    while(matrix[0][++x].check != 1)
    {
        len++;
    }
    y = -1;
    while(matrix[++y])
    {
        x = -1;
        while(matrix[y][++x].check != 1)
          i++;  
        if (len != x)
            return (-1);
    }
    return (0);
}

int main (void)
{
    char **stringY;
    char **stringX;
    char *string = "1,0xFF0000 10,0xFF0000\n1,2xFF0011 10,0xFF0000\n";
    int y, x;
    int n;
    t_point **matrix;
    y = -1;
    n = count_new_line(string);
    stringY = ft_strsplit(string, '\n'); 
    matrix = (t_point **)malloc(sizeof(t_point *) * (n + 1));
    matrix[n] = NULL;
    while(stringY[++y])
    {
        x = -1;
        n = ft_strlen(stringY[y]);
        stringX = ft_strsplit(stringY[y], ' ');
        matrix[y] = (t_point*)malloc(sizeof(t_point) * n);
        while(stringX[++x])
        {
            matrix[y][x].d_x = x;
			matrix[y][x].d_y = y;
			matrix[y][x].d_z = ft_atoi(stringX[x]);
			matrix[y][x].color = ft_comma(stringX[x]);
            matrix[y][x].check = 0;
        }
        matrix[y][x].check = 1;
    }
    if ( funck_check(matrix) == -1)
        printf("NOOOO");
    return (0);
}