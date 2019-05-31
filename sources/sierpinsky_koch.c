/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sierpinsky_koch.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/11 11:26:47 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/31 17:12:53 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_sierpinski_carpet(t_param *p, t_real o, t_real coord, int nb)
{
	int	i;
	int	j;

	if (nb > p->it[21] || nb <= 0)
		return ;
	j = o.y + coord.y / 3 - 1;
	while (++j < o.y + 2 * coord.y / 3)
	{
		i = o.x + coord.x / 3 - 1;
		while (++i < o.x + 2 * coord.x / 3)
			ft_pixel_put(p->mlx->win[p->fractal], i, j, 			\
					ft_color_average(RED, BLUE, 					\
					(double)(nb - 1) / (p->it[21] - 1)));
	}
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			if (i != 1 || j != 1)
				ft_sierpinski_carpet(p, 							\
						ft_make_real(o.x + i * coord.x / 3, 		\
						o.y + j * coord.y / 3), 					\
						ft_make_real(coord.x / 3, coord.y / 3), nb + 1);
	}
}

void	ft_draw_triangle(t_param *p, t_real o, int size, t_cplx pt)
{
	int	i;

	i = -1;
	while (++i < size)
		if (p->triangle_init)
			ft_line(p->mlx->win[p->fractal], pt, 	\
					ft_make_cplx(o.x + i, o.y + size * sqrt(3) * 0.5), WHITE);
		else
			ft_line(p->mlx->win[p->fractal], pt, 	\
					ft_make_cplx(o.x + i, o.y), BLACK);
}

void	ft_sierpinski_triangle(t_param *p, t_real o, int size, int nb)
{
	if (nb > p->it[22] || nb < 0)
		return ;
	if (!nb)
	{
		p->triangle_init = 1;
		ft_draw_triangle(p, o, size, 									\
				ft_make_cplx(WIDTH / 2, (2 * HEIGHT - size * sqrt(3)) * 0.25));
		ft_sierpinski_triangle(p, o, size, nb + 1);
		return ;
	}
	p->triangle_init = 0;
	ft_draw_triangle(p, 												\
			ft_make_real(o.x + size / 4, o.y + size * sqrt(3) * 0.25), 	\
			size / 2, ft_make_cplx(o.x + size / 2, o.y + size * sqrt(3) * 0.5));
	ft_sierpinski_triangle(p, 											\
			ft_make_real(o.x + size / 4, o.y), size / 2, nb + 1);
	ft_sierpinski_triangle(p, 											\
			ft_make_real(o.x, o.y + size * sqrt(3) * 0.25), size / 2, nb + 1);
	ft_sierpinski_triangle(p, 											\
			ft_make_real(o.x + size / 2, o.y + size * sqrt(3) * 0.25), 	\
			size / 2, nb + 1);
}

void	ft_koch(t_param *p, t_cplx d, t_cplx e, int nb)
{
	t_cplx	nb1;
	t_cplx	nb2;
	t_cplx	nb3;

	if (nb == p->it[23] || p->it[23] < 0)
	{
		ft_line(p->vignette ? p->mlx->param : p->mlx->win[p->fractal], 	\
				d, e, WHITE);
		return ;
	}
	nb1 = ft_coord_average(d, e, (double)1 / 3);
	nb2 = ft_coord_average(d, e, (double)2 / 3);
	nb3 = ft_cplx_turn(nb1, nb2, (p->koch ? -1 : 1) * M_PI / 3);
	ft_koch(p, d, nb1, nb + 1);
	ft_koch(p, nb1, nb3, nb + 1);
	ft_koch(p, nb3, nb2, nb + 1);
	ft_koch(p, nb2, e, nb + 1);
}

void	ft_size_koch(t_param *p, t_cplx o, int w, int h)
{
	t_cplx	dep;

	dep = ft_make_cplx(w / 2 + o.rl, 9 * h / 10 + o.im);
	ft_koch(p, dep, ft_cplx_turn(dep, 									\
			ft_make_cplx(w / 2 + o.rl, h / 2 + o.im), 2 * M_PI / 3), 0);
	ft_koch(p, ft_cplx_turn(dep, 										\
			ft_make_cplx(w / 2 + o.rl, h / 2 + o.im), 2 * M_PI / 3), 	\
			ft_cplx_turn(dep, 											\
			ft_make_cplx(w / 2 + o.rl, h / 2 + o.im), 4 * M_PI / 3), 0);
	ft_koch(p, ft_cplx_turn(dep, 										\
			ft_make_cplx(w / 2 + o.rl, h / 2 + o.im), 4 * M_PI / 3), dep, 0);
}
