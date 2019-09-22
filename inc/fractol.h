/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:05:56 by smaddox           #+#    #+#             */
/*   Updated: 2019/09/20 17:49:56 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx.h"

# define DEFAULT_ZOOM 200
# define MAX_ITER 50
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define WINDOW_TITLE "FRACTOL"
# define ABS(x) (((x) < 0) ? -(x) : (x))

typedef struct	s_mouse
{
	float		x;
	float		y;
}				t_mouse;

typedef struct	s_img
{
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_controller
{
	void		*mlx;
	void		*window;
	float		(*mode[3])(float, float, struct s_controller*);
	int			select_mode;
	float		pan_x;
	float		pan_y;
	float		zoom;
	t_mouse		mouse;
	t_img		*img;
}				t_controller;

float			mandlebrot(float x, float y, struct s_controller *controller);
float			julia(float x, float y, struct s_controller *controller);
float			another_fractol(float x, float y,
		struct s_controller *controller);
int				scroll_hook(int key, int x, int y, t_controller *controller);
int				mouse_hook(int x, int y, t_controller *controller);
int				key_hook(int key, t_controller *controller);
void			redraw(t_controller *controller);
#endif
