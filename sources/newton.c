/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   newton.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/12 20:47:09 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/31 17:30:21 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_cplx	ft_result_newton(t_param *p, t_cplx z, int deg)
{
	int	a;
	int	b;

	if (deg % 2)
	{
		a = (deg - 1) * 0.5;
		b = a + 1;
	}
	else
	{
		a = deg - 1;
		b = a + 2;
	}
	(void)p;
	if (p->fractal == 18)
		return (ft_cplx_div(ft_cplx_add(ft_cplx_mult(ft_make_cplx(deg - 1, 	\
				0), ft_cplx_pow(z, deg)), 									\
				ft_make_cplx(1, 0)), ft_cplx_mult(ft_make_cplx(deg, 0), 	\
				ft_cplx_pow(z, deg - 1))));
	return (ft_cplx_div(ft_cplx_add(ft_cplx_mult(ft_make_cplx(a, 0), 		\
			ft_cplx_pow(z, deg + 1)), 										\
			ft_cplx_mult(ft_make_cplx(b, 0), z)), 							\
			ft_cplx_add(ft_cplx_mult(ft_make_cplx(b, 0), 					\
			ft_cplx_pow(z, deg)), ft_make_cplx(a, 0))));
}

int		ft_check_epsilon(t_cplx z, int deg, double e)
{
	int	i;

	i = -1;
	while (++i < deg)
		if (ft_cplx_modul_2(ft_cplx_remove(z, 			\
				ft_make_cplx(cos(i * 2 * M_PI / deg), 	\
				sin(i * 2 * M_PI / deg)))) < e)
			return (++i);
	return (0);
}

void	ft_fractal_newton(t_param *p, double x, double y)
{
	double	i;
	int		nb;
	t_cplx	z;
	int		col;

	z = ft_scale_coords(p, x, y);
	i = -1;
	while (!(nb = ft_check_epsilon(z, p->deg_newton[p->fractal - 18], 0.00001)) 				\
			&& ++i < (p->it[p->fractal] + p->it_tmp[p->fractal]) * p->deg_newton[p->fractal - 18])
		z = ft_result_newton(p, z, p->deg_newton[p->fractal - 18]);
	if (p->deg_newton[p->fractal - 18] <= 7)
	{
		col = --nb < 3 ? 													\
				RED_H >> nb * 8 : ~((RED_H >> (nb - 3) * 8) | 0xFF000000);
		ft_pixel_put(p->mlx->win[p->fractal], x, y, 						\
				ft_color_average(ft_color_int_to_rgb(col), 					\
				BLACK, i / ((p->it[p->fractal] + p->it_tmp[p->fractal]) * p->deg_newton[p->fractal - 18])));
	}
	else if (nb)
		ft_pixel_put(p->mlx->win[p->fractal], x, y, 						\
				ft_color_average(p->colors_newton[nb - 1], BLACK, 			\
				i / ((p->it[p->fractal] + p->it_tmp[p->fractal]) * p->deg_newton[p->fractal - 18])));
	else
		ft_pixel_put(p->mlx->win[p->fractal], x, y, BLACK);
}

t_cplx	ft_iter(t_param *p, t_cplx z)
{
	int		bx;
	int		by;

	z = ft_result(p, z, p->c[p->fractal]);
	bx = (z.rl + 2) * WIDTH / 4;
	by = (z.im + 2) * WIDTH / 4;
	if (bx >= 0 && by >= 0 && bx < WIDTH && by < HEIGHT)
		p->buddhabrot[by * HEIGHT + bx]++;
	return (z);
}
