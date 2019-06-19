/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_fractals_1.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 22:54:00 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 22:53:50 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

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
