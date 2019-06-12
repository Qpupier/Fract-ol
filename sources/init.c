/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/07 19:10:55 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 19:53:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_colors(t_param *p)
{
	int	i;

	if (!(p->colors_newton = malloc(sizeof(t_rgb) * 15)))
		ft_error("Malloc error");
	i = -1;
	while (++i < 15)
		p->colors_newton[i] = ft_color_rgb_random();
	p->colors[0] = BLACK;
	p->colors[1] = ft_color_hex_to_rgb("0x8888FF");
	p->colors[2] = RED;
	p->colors[3] = ft_color_hex_to_rgb("0xAA");
	p->colors_carpet[0] = RED;
	p->colors_carpet[1] = BLUE;
	p->colors_tree[0] = WHITE;
	p->colors_tree[1] = BLUE;
}

void	ft_init_others(t_param *p, int fractal)
{
	p->zoom[fractal] = 4;
	p->dis_zoom[fractal] = 0;
	p->pos_left[fractal] = ft_make_cplx(-2, -2);
	p->deg[fractal] = 2;
	p->it_tmp[fractal] = 0;
	p->it[fractal] = fractal == 14 ? 10000 : 300;
}

void	ft_init_julia(t_param *p, int fractal)
{
	ft_init_others(p, fractal);
	p->c[fractal] = ft_make_cplx(-0.8, 0.156);
}

void	ft_init_mandelbrot(t_param *p, int fractal)
{
	ft_init_others(p, fractal);
	p->deg_mandelbrot[fractal / 2 - 3] = 4;
}

void	ft_init_fern(t_param *p, int fractal)
{
	ft_init_others(p, fractal);
	ft_init_fern_values(p);
	p->it[fractal] = 300000;
}

void	ft_init_newton(t_param *p, int fractal)
{
	ft_init_others(p, fractal);
	p->deg_newton[fractal - 18] = 3;
	p->it[fractal] = fractal == 18 ? 5 : 4;
}

void	ft_init_pythagore(t_param *p, int fractal)
{
	ft_init_others(p, fractal);
	p->pyth_angle = 0;
	p->it[fractal] = 6;
}

void	ft_init_carpet(t_param *p, int fractal)
{
	ft_init_others(p, fractal);
	p->it[fractal] = 3;
}

void	ft_init_triangle(t_param *p, int fractal)
{
	ft_init_others(p, fractal);
	p->it[fractal] = 6;
}

void	ft_init_koch(t_param *p, int fractal)
{
	ft_init_others(p, fractal);
	p->koch = 0;
	p->it[fractal] = 3;
}

void	ft_init_tree(t_param *p, int fractal)
{
	ft_init_others(p, fractal);
	p->tree_nb = 3;
	p->tree_degree[0] = -120;
	p->tree_degree[1] = 0;
	p->tree_degree[2] = 120;
	p->tree_ratio = 0.5;
	p->tree_size = MIN / 5;
	p->it[fractal] = 3;
}

void	ft_init(t_param *p)
{
	int	i;

	p->init = 1;
	p->param = 0;
	p->vignette = 0;
	ft_create_window(p);
	p->screenshot = 0;
	p->mouse_l = 0;
	p->mouse_r = 0;
	p->stop = 0;
	ft_init_colors(p);
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

void	ft_init_params(t_param *p)
{
	int	i;

	i = -1;
	while (++i < HEIGHT)
	{
		ft_pixel_put(p->mlx->param, DIS / 2, i, WHITE);
		ft_pixel_put(p->mlx->param, DIS - 1, i, WHITE);
	}
	i = -1;
	while (++i < DIS)
	{
		ft_pixel_put(p->mlx->param, i, HEIGHT / 5, WHITE);
		ft_pixel_put(p->mlx->param, i, 2 * HEIGHT / 5, WHITE);
		ft_pixel_put(p->mlx->param, i, 3 * HEIGHT / 5, WHITE);
		ft_pixel_put(p->mlx->param, i, 4 * HEIGHT / 5, WHITE);
	}
	mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, p->mlx->param.ptr, 0, 0);
	ft_params(p);
	ft_legend(p->mlx);
}

int		ft_buddha(t_param *p)
{
	int i;
	int max;

	max = 0;
	i = -1;
	while (++i < WIDTH * HEIGHT)
		if (p->buddhabrot[i] > max)
			max = p->buddhabrot[i];
	return (max);
}
