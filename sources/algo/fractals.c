/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractals.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/12 20:56:29 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 22:53:50 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static t_cplx	ft_result2(t_param *p, t_cplx z, t_cplx c)
{
	if (p->fractal == 9)
		return (ft_cplx_add(ft_cplx_pow(z, p->deg[p->fractal]), 			\
				ft_cplx_div(ft_cplx_pow(c, p->deg[p->fractal]), 			\
				ft_cplx_add(ft_cplx_pow(c, 									\
				p->deg_mandelbrot[p->fractal / 2 - 3]), 					\
				ft_make_cplx(-0.5, 0)))));
	else if (p->fractal == 10)
		return (ft_cplx_add(ft_cplx_add(ft_cplx_pow(z, 						\
				p->deg[p->fractal]), ft_cplx_pow(c, p->deg[p->fractal])), 	\
				ft_make_cplx(-1, 0)));
	else if (p->fractal == 11)
		return (ft_cplx_cos(ft_cplx_div(z, 									\
				ft_cplx_pow(c, p->deg_mandelbrot[p->fractal / 2 - 3]))));
	else if (p->fractal == 12)
		return (ft_cplx_sin(ft_cplx_mult(z, 								\
				ft_cplx_pow(c, p->deg[p->fractal]))));
		return (ft_cplx_sinh(ft_cplx_div(z, c)));
}

t_cplx			ft_result(t_param *p, t_cplx z, t_cplx c)
{
	if (p->fractal == 14 || p->fractal == 15)
		return (ft_cplx_add(ft_cplx_pow(z, 2), c));
	if (!p->fractal || p->fractal == 5)
		return (ft_cplx_add(ft_cplx_pow(z, p->deg[p->fractal]), c));
	else if (p->fractal == 1 || p->fractal == 6)
		return (ft_cplx_add(ft_cplx_pow(ft_make_cplx(ft_abs(z.rl), 		\
				ft_abs(z.im)), p->deg[p->fractal]), c));
	else if (p->fractal == 2 || p->fractal == 7)
		return (ft_cplx_add(ft_cplx_add(ft_cplx_pow(z, 					\
				p->deg[p->fractal]), ft_cplx_pow(c, p->fractal == 2 	\
				? 2 : p->deg_mandelbrot[p->fractal / 2 - 3])), 			\
				ft_make_cplx(-1.401155, 0)));
	else if (p->fractal == 3 || p->fractal == 8)
		return (ft_cplx_add(ft_cplx_add(ft_cplx_pow(z, 					\
				p->deg[p->fractal]), ft_cplx_div(ft_cplx_pow(c, 		\
				p->deg[p->fractal]), 									\
				ft_cplx_add(ft_cplx_pow(z, p->deg[p->fractal]), c))), c));
	else if (p->fractal == 4)
		return (ft_cplx_add(ft_cplx_div(ft_cplx_add(ft_cplx_pow(z, 		\
				p->deg[p->fractal]), z), ft_cplx_ln(z)), c));
		return (ft_result2(p, z, c));
}

t_cplx			ft_scale_coords(t_param *p, double x, double y)
{
	return (ft_make_cplx(p->pos_left[p->fractal].rl + 	\
			p->zoom[p->fractal] * x / WIDTH, 			\
			p->pos_left[p->fractal].im + p->zoom[p->fractal] * y / HEIGHT));
}

t_cplx			ft_inverse_coords(t_param *p, double x, double y)
{
	return (ft_make_cplx((x - p->pos_left[p->fractal].rl) * WIDTH 	\
			/ p->zoom[p->fractal], 									\
			(y - p->pos_left[p->fractal].im) * WIDTH / p->zoom[p->fractal]));
}

void			ft_algo(t_param *p, double x, double y)
{
	t_cplx	z;
	double	i;
	t_cplx	tmp;

	if (p->fractal >= 18 && p->fractal < 21)
		return (ft_fractal_newton(p, x, y));
	tmp = ft_scale_coords(p, x, y);
	if (p->fractal < 5)
		z = tmp;
	else
	{
		z = ft_make_cplx(0, 0);
		if (p->fractal == 12)
			z = ft_make_cplx(1, 0);
		else if (p->fractal == 13)
			z = ft_make_cplx(0, 1);
		p->c[p->fractal] = tmp;
	}
	i = -1;
	while (++i < p->it[p->fractal] && ft_cplx_modul_2(z) < 4)
	{
		z = ft_result(p, z, p->c[p->fractal]);
	}
	ft_display_result(p, i, x, y);
}
