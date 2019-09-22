/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:55:38 by smaddox           #+#    #+#             */
/*   Updated: 2019/09/20 18:55:50 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	modify_image(int x, int y, float val, t_img *img)
{
	uint32_t	*stepper;
	uint32_t	color;
	int			index;

	color = 0xFFFFFF00 * val;
	index = ((int)x) + ((int)y * img->size_line);
	stepper = (uint32_t*)img->img_data;
	stepper[index] = color;
}

void	redraw(t_controller *controller)
{
	int		x;
	int		y;
	float	val;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			val = controller->mode[controller->select_mode](x /
					controller->zoom - controller->pan_x, y /
					controller->zoom - controller->pan_y, controller);
			modify_image(x, y, val, controller->img);
			++x;
		}
		++y;
	}
	mlx_clear_window(controller->mlx, controller->window);
	mlx_put_image_to_window(controller->mlx,
			controller->window, controller->img->img_ptr, 0, 0);
}

void	controller_init(t_controller *controller, int mode)
{
	controller->mode[0] = &mandlebrot;
	controller->mode[1] = &julia;
	controller->mode[2] = &another_fractol;
	controller->select_mode = mode;
	controller->zoom = DEFAULT_ZOOM;
	controller->pan_x = 2;
	controller->pan_y = 1.5;
	controller->mlx = mlx_init();
	controller->window = mlx_new_window(controller->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
}

int		main(int ac, char **av)
{
	t_controller	controller;
	t_img			img;

	if (ac != 2 || av[1][0] - '0' > 2 || av[1][0] - '0' < 0)
	{
		write(1, "usage: 0:mandlebrot 1:julia 2:biomorph\n", 40);
		return (1);
	}
	controller_init(&controller, av[1][0] - '0');
	controller.img = &img;
	img.img_ptr = mlx_new_image(controller.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	img.img_data = mlx_get_data_addr(img.img_ptr,
			&(img.bpp), &(img.size_line), &(img.endian));
	img.size_line /= 4;
	redraw(&controller);
	mlx_hook(controller.window, 6, 0, mouse_hook, &controller);
	mlx_hook(controller.window, 2, 0, key_hook, &controller);
	mlx_hook(controller.window, 4, 0, scroll_hook, &controller);
	mlx_loop(controller.mlx);
	return (0);
}
