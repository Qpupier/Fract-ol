/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 22:43:46 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 17:26:10 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_display_result(t_param *p, double i, double x, double y)
{
	double	nb;
	t_cplx	z;

	z = ft_make_cplx(0, 0);
	if (i < p->it[p->fractal])
	{
		if (p->fractal < 14)
		{
			nb = i * NB_COLORS / p->it[p->fractal];
			ft_pixel_put(p->mlx->win[p->fractal], x, y, 	\
					ft_color_average(p->colors[p->fractal][(int)nb], 	\
					p->colors[p->fractal][(int)nb + 1], nb - (int)nb));
		}
		else if (p->fractal == 14)
			while (ft_cplx_modul_2(z) < 4)
				z = ft_iter(p, z);
	}
	else if (p->fractal == 15)
	{
		i = -1;
		while (++i < p->it[p->fractal])
			z = ft_iter(p, z);
	}
	else if (p->fractal < 14)
		ft_pixel_put(p->mlx->win[p->fractal], x, y, BLACK);
}

void	ft_display2(t_param *p, double max)
{
	int i;

	i = -1;
	while (++i < WIDTH * HEIGHT)
		if (p->buddhabrot[i] < max / 6)
			ft_pixel_put(p->mlx->win[p->fractal], i / HEIGHT, i % HEIGHT, 	\
					ft_color_average(BLACK, WHITE, p->buddhabrot[i] * 3 / max));
		else
			ft_pixel_put(p->mlx->win[p->fractal], i / HEIGHT, i % HEIGHT, 	\
					ft_color_average(WHITE, p->fractal == 14 				\
					? RED : BLUE, p->buddhabrot[i] / max - 1 / 6));
}

void	*ft_display(void *t)
{
	int		i;
	int		j;
	t_param	*p;

	p = (t_param *)t;
	i = -1;
	while (++i < HEIGHT)
	{
		j = p->min - 1;
		while (++j < p->max)
			ft_algo(p, j, i);
	}
	return (t);
}

void	ft_put_image(t_param *p)
{
	int	i;

	i = 100;
	mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, 			\
			p->mlx->win[p->fractal].ptr, DIS, 0);
	if (p->fractal == 16 || p->fractal == 17)
		while (i--)
			mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, 	\
					p->mlx->win_fern[p->fractal - 16][i].ptr, DIS, 0);
	ft_img_dark(p->mlx->param2);
	ft_params(p);
}
