/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/07 19:10:55 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/31 17:30:54 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_colors(t_param *p)
{
	int	i;

	if (!(p->colors_newton = malloc(sizeof(t_rgb) * p->deg_newton[p->fractal - 18])))
		ft_error("Malloc error");
	if (!(p->colors = malloc(sizeof(t_rgb) * (p->nb_colors + 1))))
		ft_error("Malloc error");
	i = -1;
	while (++i < p->deg_newton[p->fractal - 18])
		p->colors_newton[i] = ft_color_rgb_random();
	p->colors[0] = BLACK;
	p->colors[1] = ft_color_hex_to_rgb("0x8888FF");
	p->colors[2] = RED;
	p->colors[3] = ft_color_hex_to_rgb("0xAA");
}

void	ft_init(t_param *p)
{
	int	i;

	p->init = 1;
	p->param = 0;
	p->vignette = 0;
	ft_create_window(p);
	i = -1;
	while (++i < NB_FRACTALES)
	{
		p->zoom[i] = 4;
		p->dis_zoom[i] = 0;
		p->pos_left[i] = ft_make_cplx(-2, -2);
		p->deg[i] = 2;
		if (i < 5)
			p->c[i] = ft_make_cplx(-0.8, 0.156);
		else if (i == 7 || i == 9 || i == 11)
			p->deg_mandelbrot[i / 2 - 3] = 4;
		else if (i == 18 || i == 19)
			p->deg_newton[i - 18] = 3;
	}
	p->stop = 0;
	ft_init_fern(p);
	p->nb_colors = 3;
	ft_init_colors(p);
	p->pyth_size = 100;
	p->pyth_angle = 0;
	p->koch = 0;
	p->tree_nb = 3;
	p->tree_degree[0] = -120;
	p->tree_degree[1] = 0;
	p->tree_degree[2] = 120;
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

void	ft_init_zoom(t_param *p)
{
	int	i;

	i = -1;
	while (++i < 16)
		p->it[p->fractal] = 300;
	p->it[14] = 10000;
	p->it[16] = 300000;
	p->it[17] = 300000;
	p->it[18] = 5;
	p->it[19] = 5;
	p->it[20] = 6;
	p->it[21] = 3;
	p->it[22] = 6;
	p->it[23] = 3;
	p->it[24] = 3;
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
