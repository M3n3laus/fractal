/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:17:51 by smaddox           #+#    #+#             */
/*   Updated: 2019/09/20 17:39:10 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_controller *controller)
{
	if (key == 53)
		exit(0);
	if (key == 15)
	{
		controller->zoom = DEFAULT_ZOOM;
		controller->pan_x = 2;
		controller->pan_y = 1.5;
	}
	if (key == 124)
	{
		controller->select_mode++;
		controller->select_mode = controller->select_mode % 3;
	}
	if (key == 2 || key == 0)
		controller->pan_x += (key == 2) ? .01 : -.01;
	if (key == 13 || key == 1)
		controller->pan_y += (key == 1) ? .01 : -.01;
	redraw(controller);
	return (0);
}

int	mouse_hook(int x, int y, t_controller *controller)
{
	if (((controller->select_mode == 1) || (controller->select_mode == 2))
			&& x <= WINDOW_WIDTH && x >= 0 && y >= 0 && y < WINDOW_HEIGHT)
	{
		controller->mouse.x = x * 4.0 / WINDOW_WIDTH - 2;
		controller->mouse.y = y * 4.0 / WINDOW_HEIGHT - 2;
		redraw(controller);
	}
	return (0);
}

int	scroll_hook(int key, int x, int y, t_controller *controller)
{
	if (x <= WINDOW_WIDTH && x >= 0 && y >= 0 && y < WINDOW_HEIGHT)
	{
		if (key == 4 && controller->zoom < INT_MAX)
			controller->zoom += 100;
		else if (key == 5)
			controller->zoom -= 100;
		redraw(controller);
	}
	return (0);
}
