/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_iterations.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 23:10:45 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 22:53:50 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int		ft_it_verif(int fractal, int it, int side)
{
	if (!side && it)
		return (1);
	else if (side && it < 1000)
	{
		if (fractal == 20)
		{
			if (it < 12)
				return (1);
		}
		else if (fractal == 24)
		{
			if (it < 15)
				return (1);
		}
		else if (fractal >= 18)
		{
			if (it < 8)
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

void			ft_it_less(t_param *p, int tmp)
{
	if (ft_it_verif(p->fractal, p->it[p->fractal], 0))
	{
		if (tmp)
			p->it_tmp[p->fractal] = p->it[p->fractal] + 					\
					p->it_tmp[p->fractal] <= 20 || !p->it_tmp[p->fractal] 	\
					? p->it_tmp[p->fractal] - 0.5 							\
					: p->it_tmp[p->fractal] * 0.99;
		else
			p->it[p->fractal] = p->it[p->fractal] <= 20 					\
					? p->it[p->fractal] - 1 : p->it[p->fractal] * 0.95;
	}
}

void			ft_it_more(t_param *p, int tmp)
{
	if (ft_it_verif(p->fractal, p->it[p->fractal], 1))
	{
		if (tmp)
			p->it_tmp[p->fractal] = p->it[p->fractal] + 					\
					p->it_tmp[p->fractal] <= 20 || !p->it_tmp[p->fractal] 	\
					? p->it_tmp[p->fractal] + 0.5 							\
					: p->it_tmp[p->fractal] * 1.01;
		else
			p->it[p->fractal] = p->it[p->fractal] <= 20 	\
					? p->it[p->fractal] + 1 : p->it[p->fractal] * 1.05;
	}
}

void			ft_it_inf(t_param *p)
{
	if (p->fractal < 13 && p->deg[p->fractal] > 1)
		p->deg[p->fractal]--;
	else if ((p->fractal == 18 || p->fractal == 19) 	\
			&& p->deg_newton[p->fractal - 18] > 2)
		p->deg_newton[p->fractal - 18]--;
	else if (p->fractal == 20 && p->pyth_angle > -90)
		p->pyth_angle--;
	else if (p->fractal == 24 && p->tree_size > 10)
		p->tree_size--;
}

void			ft_it_sup(t_param *p)
{
	if (p->fractal < 15 && p->deg[p->fractal] < 10)
		p->deg[p->fractal]++;
	else if ((p->fractal == 18 || p->fractal == 19) 	\
			&& p->deg_newton[p->fractal - 18] < 15)
		p->deg_newton[p->fractal - 18]++;
	else if (p->fractal == 20 && p->pyth_angle < 90)
		p->pyth_angle++;
	else if (p->fractal == 24 && p->tree_size < HEIGHT / 4)
		p->tree_size++;
}
