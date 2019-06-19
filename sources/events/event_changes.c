/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_changes.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 23:16:07 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 22:54:27 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_top_less(t_param *p)
{
	if (p->fractal < 15 && p->deg_mandelbrot[p->fractal / 2 - 3] > 1)
		p->deg_mandelbrot[p->fractal / 2 - 3]--;
	else if (p->fractal == 24 && p->tree_ratio > 0.5)
		p->tree_ratio -= 0.1;
}

void	ft_top_more(t_param *p)
{
	if (p->fractal < 15 && p->deg_mandelbrot[p->fractal / 2 - 3] < 10)
		p->deg_mandelbrot[p->fractal / 2 - 3]++;
	else if (p->fractal == 24 && p->tree_ratio < 0.9)
		p->tree_ratio += 0.1;
}

void	ft_event_tree(t_param *p, int key)
{
	if (p->fractal == 24)
	{
		if (key == NB_1 && p->tree_degree[0] > -180)
			p->tree_degree[0]--;
		if (key == NB_4 && p->tree_degree[0] < 180)
			p->tree_degree[0]++;
		if (key == NB_2 && p->tree_degree[1] > -180)
			p->tree_degree[1]--;
		if (key == NB_5 && p->tree_degree[1] < 180)
			p->tree_degree[1]++;
		if (key == NB_3 && p->tree_degree[2] > -180)
			p->tree_degree[2]--;
		if (key == NB_6 && p->tree_degree[2] < 180)
			p->tree_degree[2]++;
	}
}

void	ft_event_moves(t_param *p, int key)
{
	if (key == LEFT && p->fractal < 21 && p->pos_left[p->fractal].rl > -6)
		p->pos_left[p->fractal].rl -= 0.05 * p->zoom[p->fractal];
	else if (key == RIGHT && p->fractal < 21 && p->pos_left[p->fractal].rl < 2)
		p->pos_left[p->fractal].rl += 0.05 * p->zoom[p->fractal];
	else if (key == UP && p->fractal < 21 && p->pos_left[p->fractal].im > -6)
		p->pos_left[p->fractal].im -= 0.05 * p->zoom[p->fractal];
	else if (key == DOWN && p->fractal < 21 && p->pos_left[p->fractal].im < 2)
		p->pos_left[p->fractal].im += 0.05 * p->zoom[p->fractal];
}

void	ft_event_display(t_param *p, int key)
{
	ft_fractol(p);
	if (key == R)
		ft_miniatures(p);
}
