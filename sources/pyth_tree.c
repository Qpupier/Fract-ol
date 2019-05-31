/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pyth_tree.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 14:36:20 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/31 17:12:25 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_cplx	ft_draw_square(t_param *p, t_real xy, t_pyth q)
{
	int		i;
	int		j;
	t_cplx	c;
	double	degre;

	degre = ft_deg_to_rad(q.side ? q.pyth_deg : -q.pyth_deg);
	i = xy.x + 1;
	while (q.side ? (--i > xy.x - q.size) : (++i < xy.x + q.size))
	{
		j = xy.y + 1;
		while (--j > xy.y - q.size)
		{
			c = ft_cplx_mult(ft_make_cplx(i - xy.x, j - xy.y), 	\
					ft_make_cplx(cos(degre), sin(degre)));
			ft_pixel_put(p->mlx->win[p->fractal], 				\
					c.rl + xy.x, c.im + xy.y, 					\
					ft_color_average(GREEN, 					\
					ft_color_hex_to_rgb("0x228B22"), 			\
					(double)q.nb / (p->it[20] - 1)));
		}
	}
	return (ft_cplx_mult(ft_make_cplx(0, -q.size), 				\
			ft_make_cplx(cos(degre), sin(degre))));
}

int		ft_init_pythagore(t_param *p, int y, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < p->pyth_size)
	{
		j = -1;
		while (++j < p->pyth_size)
			ft_pixel_put(p->mlx->win[p->fractal], 		\
					WIDTH / 2 - p->pyth_size / 2 + j, 	\
					HEIGHT - 200 - p->pyth_size + i, GREEN);
	}
	y += size;
	return (y);
}

void	ft_pythagore(t_param *p, t_cplx xy, t_pyth q)
{
	int	angle;

	if (q.nb >= p->it[20] || q.nb < 0)
		return ;
	if (!q.nb)
		xy.im = ft_init_pythagore(p, xy.im, q.size);
	else
		ft_draw_square(p, ft_cplx_to_real(xy), q);
	angle = (90 - p->pyth_angle) / 2;
	q.pyth_deg = q.side ? q.pyth_deg : -q.pyth_deg;
	ft_pythagore(p, ft_cplx_add(xy, 									\
			ft_cplx_mult(ft_make_cplx(-q.size * q.side, -q.size), 		\
			ft_make_cplx(cos(ft_deg_to_rad(q.pyth_deg)), 				\
			sin(ft_deg_to_rad(q.pyth_deg))))), (t_pyth){q.nb + 1, 		\
			q.size * cos(ft_deg_to_rad(angle)), angle - q.pyth_deg, 0});
	ft_pythagore(p, ft_cplx_add(xy, 									\
			ft_cplx_mult(ft_make_cplx((1 - q.side) * q.size, -q.size), 	\
			ft_make_cplx(cos(ft_deg_to_rad(q.pyth_deg)), 				\
			sin(ft_deg_to_rad(q.pyth_deg))))), (t_pyth){q.nb + 1, 		\
			q.size * cos(ft_deg_to_rad(90 - angle)), 					\
			q.pyth_deg + 90 - angle, 1});
}

void	ft_tree(t_param *p, t_cplx xy, double tree_angle, t_tree t)
{
	t_cplx		l;
	t_cplx		r;
	t_cplx		m;
	t_mlx_img	img;

	img = p->vignette ? p->mlx->param : p->mlx->win[p->fractal];
	if (t.nb >= p->it[24] || t.nb < 0)
		return ;
	if (!t.nb)
	{
		ft_line(img, xy, ft_cplx_add(xy, ft_make_cplx(0, -t.size * 2)), WHITE);
		xy = ft_cplx_remove(xy, ft_make_cplx(0, t.size * 2));
	}
	l = ft_cplx_turn(ft_cplx_remove(xy, ft_make_cplx(0, t.size)), xy, 		\
			tree_angle + ft_deg_to_rad(p->tree_degree[0]));
	r = ft_cplx_turn(ft_cplx_remove(xy, ft_make_cplx(0, t.size)), xy, 		\
			tree_angle + ft_deg_to_rad(p->tree_degree[2]));
	ft_line(img, xy, l, WHITE);
	ft_line(img, xy, r, WHITE);
	ft_tree(p, l, tree_angle + ft_deg_to_rad(p->tree_degree[0]), (t_tree){t.size * 0.5, t.nb + 1});
	ft_tree(p, r, tree_angle + ft_deg_to_rad(p->tree_degree[2]), (t_tree){t.size * 0.5, t.nb + 1});
	if (p->tree_nb == 3)
	{
		m = ft_cplx_turn(ft_cplx_remove(xy, ft_make_cplx(0, t.size)), xy, 	\
				tree_angle + ft_deg_to_rad(p->tree_degree[1]));
		ft_line(img, xy, m, WHITE);
		ft_tree(p, m, tree_angle + ft_deg_to_rad(p->tree_degree[1]), (t_tree){t.size * 0.5, t.nb + 1});
	}
}
