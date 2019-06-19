/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_fractals_2.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 22:55:23 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 22:53:50 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

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
