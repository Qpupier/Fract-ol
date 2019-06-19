/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/07 19:10:55 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 17:43:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	ft_fractals_ptr(t_param *p)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if (i < 5)
			p->init_fractal[i] = ft_init_julia;
		else if (i == 7 || i == 9 || i == 11)
			p->init_fractal[i] = ft_init_mandelbrot;
		else
			p->init_fractal[i] = ft_init_others;
	}
	p->init_fractal[16] = ft_init_fern;
	p->init_fractal[17] = ft_init_fern;
	p->init_fractal[18] = ft_init_newton;
	p->init_fractal[19] = ft_init_newton;
	p->init_fractal[20] = ft_init_pythagore;
	p->init_fractal[21] = ft_init_carpet;
	p->init_fractal[22] = ft_init_triangle;
	p->init_fractal[23] = ft_init_koch;
	p->init_fractal[24] = ft_init_tree;
	i = -1;
	while (++i < NB_FRACTALES)
		p->init_fractal[i](p, i);
}

static void	ft_init_colors(t_param *p)
{
	int	i;

	if (!(p->colors_newton = malloc(sizeof(t_rgb) * 15)))
		ft_error("Malloc error");
	i = -1;
	while (++i < 15)
		p->colors_newton[i] = ft_color_rgb_random();
	i = -1;
	while (++i < NB_FRACTALES)
	{
		p->colors[i][0] = BLACK;
		p->colors[i][1] = ft_color_hex_to_rgb("0x8888FF");
		p->colors[i][2] = RED;
		p->colors[i][3] = ft_color_hex_to_rgb("0xAA");
	}
	p->colors_carpet[0] = RED;
	p->colors_carpet[1] = BLUE;
	p->colors_tree[0] = WHITE;
	p->colors_tree[1] = BLUE;
}

static void	ft_create_images(t_param *p)
{
	int	i;

	i = -1;
	while (++i < 100)
	{
		ft_create_img(p->mlx->mlx_ptr, &p->mlx->win_fern[0][i], WIDTH, HEIGHT);
		ft_create_img(p->mlx->mlx_ptr, &p->mlx->win_fern[1][i], WIDTH, HEIGHT);
		ft_create_img(p->mlx->mlx_ptr, &p->mlx->param_fern[i], DIS, HEIGHT);
	}
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param, DIS, HEIGHT);
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param2, DIS + WIDTH, PARAM);
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param_dark, DIS, HEIGHT);
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param_julia, DIS, HEIGHT);
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param_mandelbrot, DIS, HEIGHT);
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param_newton, DIS, HEIGHT);
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param_sierpinski, DIS, HEIGHT);
}

void		ft_create_window(t_param *p)
{
	int	i;
	int	tmp;

	p->mlx->mlx_ptr = mlx_init();
	p->mlx->mlx_loading_ptr = mlx_init();
	p->mlx->win_loading_ptr = 	\
			mlx_new_window(p->mlx->mlx_loading_ptr, 430, 130, "Fract'ol");
	i = -1;
	while (++i < WIDTH * HEIGHT)
		p->buddhabrot[i] = 0;
	tmp = p->fractal;
	p->fractal = -1;
	while (++p->fractal < NB_FRACTALES)
		ft_create_img(p->mlx->mlx_ptr, &p->mlx->win[p->fractal], WIDTH, HEIGHT);
	p->fractal = tmp;
	ft_create_images(p);
}

void		ft_init(t_param *p)
{
	p->init = 1;
	p->param = 0;
	p->vignette = 0;
	ft_create_window(p);
	p->screenshot = 0;
	p->mouse_l = 0;
	p->mouse_r = 0;
	p->stop = 0;
	ft_init_colors(p);
	ft_fractals_ptr(p);
}
