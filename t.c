void line(void *mlx_ptr, void *win_ptr, double x1, double y1, double x2, double y2)
{
    double dx;
    double dy;
    double lengthX;
    double lengthY;
    double length;
	double x;
	double y;
	double d;

	dx = (x2 - x1 >= 0 ? 1 : -1);
	dy = (y2 - y1 >= 0 ? 1 : -1);
	//функция
	lengthX = (x2 - x1);
    if (lengthX < 0)
        lengthX = -lengthX;
	lengthY = (y2 - y1);
    if (lengthY < 0)
        lengthY = -lengthY;
	//конец
	length = (lengthX > lengthY ? lengthX : lengthY) + 1;
    if (length == 1)
        mlx_pixel_put(mlx_ptr, win_ptr,  x1,   y1, 0xFF3333);
    x = x1;
    y = y1;
//функция
	if (lengthY <= lengthX)
    {
        d = -lengthX;
        while(length--)
        {
            mlx_pixel_put(mlx_ptr, win_ptr,  x,   y, 0xFF3333);
            x += dx;
            d += 2 * lengthY;
            if (d > 0)
            {
                d -= 2 * lengthX;
                y += dy;
            }
        }
    }
    else
    {
        d = - lengthY;
        while(length--)
        {
            mlx_pixel_put(mlx_ptr, win_ptr,  x,   y, 0xFF3333);
            y += dy;
            d += 2 * lengthX;
            if (d > 0)
            {
                d -= 2 * lengthY;
                x += dx;
            }
        }
    }
	//конец
}




void line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
{
	int A, B, sign;
	int signa, signb;
	int f = 0;
	int x = x0, y = y0;
	A = y1 - y0;
	B = x0 - x1;
	if (abs(A) > abs(B)) 
		sign = 1;
	else 
		sign = -1;
	if (A < 0)
  		signa = -1;
	else 
  		signa = 1;
	if (B < 0)
  		signb = -1;
	else signb = 1;
	mlx_pixel_put(mlx_ptr, win_ptr,  x0,   y0, 0xFF3333);
  	if (sign == -1) 
	{
		do 
		{
			f += A*signa;
			if (f > 0)
			{
				f -= B*signb;
				y += signa;
			}
			x -= signb;
      		mlx_pixel_put(mlx_ptr, win_ptr,  x,   y, 0xFF3333);
		} 
		while (x != x1 || y != y1);
	}
	else
	{
		do
		{
			f += B*signb;
			if (f > 0)
			{
				f -= A*signa;
				x -= signb;
			}
			y += signa;
			mlx_pixel_put(mlx_ptr, win_ptr,  x,   y, 0xFF3333);
		}
		while (x != x1 || y != y1);
	}
}