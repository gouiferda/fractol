
/*
void *add_px_parallel1(void *fractol)
{
	double x;
	double y;
	int iterations;
	int color;
	double x_start;
	double x_finish;
	double y_start;
	double y_finish;
	t_fractol *f;

	f = (t_fractol *)fractol;

	x_start =  f->offset_x + (f->zoom * -2);
	x_finish = f->offset_x + (f->zoom * 0);
	y_start = f->y_start;
	y_finish = f->y_finish;
	x = x_start;
	y = y_start;
	while (x <= x_finish)
	{
		y = y_start;
		while (y <= f->y_finish)
		{
			iterations = get_iters_julia(f, x, y);
			add_px(f, x, y, get_color_by_iter(f, iterations));
			y++;
		}
		x++;
	}
}

void *add_px_parallel2(void *fractol)
{
	double x;
	double y;
	int iterations;
	int color;
	double x_start;
	double x_finish;
	double y_start;
	double y_finish;
	t_fractol *f;

	f = (t_fractol *)fractol;
	x_start =  f->offset_x + (f->zoom * 0);
	x_finish = f->offset_x + (f->zoom * 2);
	y_start = f->y_start;
	y_finish = f->y_finish;
	x = x_start;
	y = y_start;
	while (x <= x_finish)
	{
		y = y_start;
		while (y <= f->y_finish)
		{
			iterations = get_iters_julia(f, x, y);
			add_px(f, x, y, get_color_by_iter(f, iterations));
			y++;
		}
		x++;
	}
}

void draw_test(t_fractol *fractol)
{
	pthread_t thread;
	int i;

	adjust_plane_cords(fractol);
	pthread_create(&thread, NULL, add_px_parallel1, fractol);
	pthread_create(&thread, NULL, add_px_parallel2, fractol);

	//printf("draw_test waiting for thread to terminate...\n");
	pthread_join(thread, NULL);
	if (fractol->to_draw_plane)
		draw_plane(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img_ptr, 0, 0);
	//printf("draw_test finished\n");
}
*/
