/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_buddha_refresh.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 10:39:31 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 22:53:50 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_init_fractal(t_param *p, char *fractal)
{
	if (ft_strequ(fractal, "Julia"))
		p->fractal = 0;
	else if (ft_strequ(fractal, "Mandelbrot"))
		p->fractal = 5;
	else if (ft_strequ(fractal, "Buddhabrot"))
		p->fractal = 14;
	else if (ft_strequ(fractal, "Bubblebrot"))
		p->fractal = 15;
	else if (ft_strequ(fractal, "Fern"))
		p->fractal = 16;
	else if (ft_strequ(fractal, "Newton"))
		p->fractal = 18;
	else if (ft_strequ(fractal, "Pythagore"))
		p->fractal = 20;
	else if (ft_strequ(fractal, "Sierpinski"))
		p->fractal = 21;
	else if (ft_strequ(fractal, "Koch"))
		p->fractal = 23;
	else if (ft_strequ(fractal, "Tree"))
		p->fractal = 24;
	else
		ft_usage();
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

void	ft_refresh_1(t_param *p, int x, int y)
{
	int	dx;
	int	dy;

	dx = ft_abs(p->mouse.rl - x);
	dy = ft_abs(p->mouse.im - y);
	p->pos_left[p->fractal] = ft_scale_coords(p, 		\
			ft_min(p->mouse.rl, x) - (dy - dx) / 2, 	\
			ft_min(p->mouse.im, y));
	ft_find_zoom(p, p->zoom[p->fractal], 				\
			(p->zoom[p->fractal] = dy * p->zoom[p->fractal] / MIN));
}

void	ft_refresh_2(t_param *p, int x, int y)
{
	int	dx;
	int	dy;

	dx = ft_abs(p->mouse.rl - x);
	dy = ft_abs(p->mouse.im - y);
	p->pos_left[p->fractal] = ft_scale_coords(p, 	\
			ft_min(p->mouse.rl, x), 				\
			ft_min(p->mouse.im, y) - (dx - dy) / 2);
	ft_find_zoom(p, p->zoom[p->fractal], 			\
			(p->zoom[p->fractal] = dx * p->zoom[p->fractal] / MIN));
}
