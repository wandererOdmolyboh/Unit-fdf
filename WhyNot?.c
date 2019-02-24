/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WhyNot?.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:55:14 by wanderer          #+#    #+#             */
/*   Updated: 2019/02/24 20:10:58 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int vslidate_str(char *buf)
{
    int i;

    i = 0;
    while(buf[i])
    {
        if (buf[i] == ' ' || buf[i] == '\t' || (buf[i] >= '0' && buf[i] <= '9')
        || (buf[i] >= 'A' && buf[i] <= 'F')
        || buf[i] == 'x' || buf[i] == ',' || buf[i] == '\n')
            i++;
        else
            return(-1);
        i++;
    }
    return (0);
}

int validate_hard(char *buf)
{
    int y;
    int c_len_num;

    y = 0;
    while(buf[y])
    {
        c_len_num = 0;
        if (buf[y] == 'x')
        {
            if (buf[y] && buf[y - 1]!= '0' && buf[y - 2]!= ',')
                return (3);
            while(buf[++y] && ((buf[y]>= 'A' && buf[y] <= 'F') 
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

int main (void)
{
    char *string = "1,0xFF0000 10,0xFF0000";
    if (validate_hard(string) != 0)
        printf("NO 1\n");
    else if (vslidate_str(string) != 0)
        printf("NO 2\n");
    else 
        printf("OK\n");
    return (0);
}