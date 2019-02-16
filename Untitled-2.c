int		rotate_Y(t_fdf *fdf)
{
	int y;
    int x;

    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {
			fdf->matrix[y][x].x = ( (19 * 10) / 2) + ((10 * fdf->matrix[y][x].d_x  - ((19 * 10) / 2)) * cos(fdf->angl) + (10 *fdf->matrix[y][x].d_z) * sin(fdf->angl));
			fdf->matrix[y][x].z = ( (19 * 10) / 2) + ((10 * fdf->matrix[y][x].d_z) * cos(fdf->angl)) - (((19 * 10) / 2) - 10 *fdf->matrix[y][x].d_x) * sin(fdf->angl);				
        }
    }
	y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 18)
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y][x + 1].x, fdf->matrix[y][x + 1].y);
    }  
    x = -1;
    while (++x < 19)
    {
        y = -1;
        while (fdf->matrix[++y + 1])
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y + 1][x].x, fdf->matrix[y + 1][x].y);
	}
    fdf->angl +=0.13;
	return (0);
}

int		rotate_YY(t_fdf *fdf)
{
	int y;
    int x;

    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {
			fdf->matrix[y][x].x = ((19 * 10) / 2) + (((10 * fdf->matrix[y][x].d_x  - ((19 * 10) / 2)) * cos(fdf->angl) + (10 *fdf->matrix[y][x].d_z) * sin(fdf->angl)));
			fdf->matrix[y][x].z = ((19 * 10) / 2) + (((10 * fdf->matrix[y][x].d_z) * cos(fdf->angl)) - (((19 * 10) / 2) - 10 *fdf->matrix[y][x].d_x) * sin(fdf->angl));				
        }
    }
	y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 18)
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y][x + 1].x, fdf->matrix[y][x + 1].y);
    }  
    x = -1;
    while (++x < 19)
    {
        y = -1;
        while (fdf->matrix[++y + 1])
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y + 1][x].x, fdf->matrix[y + 1][x].y);
	}
    fdf->angl -=0.13;
	return (0);
}

int		rotate_X(t_fdf *fdf)
{
	int y;
    int x;

    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {
			fdf->matrix[y][x].y = ( (11 * 10) / 2) + ((10 * fdf->matrix[y][x].d_y  - ((11 * 10) / 2)) * cos(fdf->angl) + (10 *fdf->matrix[y][x].d_z) * sin(fdf->angl));
        }
    }
	y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 18)
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y][x + 1].x, fdf->matrix[y][x + 1].y);
    }  
    x = -1;
    while (++x < 19)
    {
        y = -1;
        while (fdf->matrix[++y + 1])
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y + 1][x].x, fdf->matrix[y + 1][x].y);
	}
    fdf->angl +=0.13;
	return (0);
}

int		rotate_XX(t_fdf *fdf)
{
	int y;
    int x;

    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 19)
        {
			fdf->matrix[y][x].y = ( (11 * 10) / 2) + ((10 * fdf->matrix[y][x].d_y  - ((11 * 10) / 2)) * cos(fdf->angl) + (10 *fdf->matrix[y][x].d_z) * sin(fdf->angl));
        }
    }
	y = -1;
    while (fdf->matrix[++y])
    {
        x = -1;
        while (++x < 18)
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y][x + 1].x, fdf->matrix[y][x + 1].y);
    }  
    x = -1;
    while (++x < 19)
    {
        y = -1;
        while (fdf->matrix[++y + 1])
            line(fdf->mlx_ptr, fdf->win_ptr,fdf->matrix[y][x].x, fdf->matrix[y][x].y, fdf->matrix[y + 1][x].x, fdf->matrix[y + 1][x].y);
	}
    fdf->angl -=0.13;
	return (0);
}