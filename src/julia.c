/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:59:31 by smaddox           #+#    #+#             */
/*   Updated: 2019/09/20 17:36:04 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float		julia(float x, float y, struct s_controller *controller)
{
	float	temp;
	float	i;

	i = -1;
	while (++i < MAX_ITER)
	{
		temp = (x * x - y * y) + controller->mouse.x;
		y = (2 * x * y) + controller->mouse.y;
		x = temp;
		if (x * x + y * y > 4)
			return (i / MAX_ITER);
	}
	return (0);
}
