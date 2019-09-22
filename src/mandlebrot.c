/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:31:22 by smaddox           #+#    #+#             */
/*   Updated: 2019/09/20 18:22:44 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float		mandlebrot(float x, float y, struct s_controller *controller)
{
	float	rc;
	float	ic;
	float	tempr;
	float	tempi;
	float	i;

	controller = &(*controller);
	rc = x;
	ic = y;
	i = -1;
	while (++i < MAX_ITER)
	{
		tempr = rc * rc - ic * ic + x;
		tempi = 2 * rc * ic + y;
		rc = tempr;
		ic = tempi;
		if (rc * rc + ic * ic > 4)
			return (i / MAX_ITER);
	}
	return (0);
}
