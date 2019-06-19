/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pyth_tree.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 14:36:20 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 22:53:50 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static t_cplx	ft_draw_square(t_param *p, t_real xy, t_pyth q)
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
			c = ft_cplx_mult(ft_make_cplx(i - xy.x, j - xy.y), 			\
					ft_make_cplx(cos(degre), sin(degre)));
			ft_pixel_put(p->mlx->win[p->fractal], 						\
					c.rl + xy.x, c.im + xy.y, ft_color_average(GREEN, 	\
					ft_color_hex_to_rgb("0x228B22"), (double)q.nb 		\
					/ (p->it[p->fractal] + p->it_tmp[p->fractal] - 1)));
		}
	}
	return (ft_cplx_mult(ft_make_cplx(0, -q.size), 						\
			ft_make_cplx(cos(degre), sin(degre))));
}

static int		ft_begin_pyth(t_param *p, int y, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 400 / p->zoom[p->fractal])
	{
		j = -1;
		while (++j < 400 / p->zoom[p->fractal])
			ft_pixel_put(p->mlx->win[p->fractal], 			\
					ft_inverse_coords(p, 0, 0).rl - 400 	\
					/ p->zoom[p->fractal] * 0.5 + j, 		\
					ft_inverse_coords(p, 0, 2).im - 1200 	\
					/ p->zoom[p->fractal] + i, GREEN);
	}
	y += size;
	return (y);
}

void			ft_pythagore(t_param *p, t_cplx xy, t_pyth q)
{
	int	angle;

	if (q.nb >= p->it[p->fractal] + p->it_tmp[p->fractal] || q.nb < 0)
		return ;
	if (!q.nb)
		xy.im = ft_begin_pyth(p, xy.im, q.size);
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

static void		ft_branches(t_param *p, t_cplx xy, double tree_angle, t_tree t)
{
	t_cplx		branch;
	t_mlx_img	img;
	int			i;

	img = p->vignette ? p->mlx->param : p->mlx->win[p->fractal];
	i = -1;
	while (++i < 3)
		if (i != 1 || p->tree_nb == 3)
		{
			branch = ft_cplx_turn(ft_cplx_remove(xy, 						\
					ft_make_cplx(0, t.size)), xy, 							\
					tree_angle + ft_deg_to_rad(p->tree_degree[i]));
			ft_line(img, xy, branch, ft_color_average(p->colors_tree[0], 	\
					p->colors_tree[1], (double)t.nb / p->it[24]));
			ft_tree(p, branch, 												\
					tree_angle + ft_deg_to_rad(p->tree_degree[i]), 			\
					(t_tree){t.size * p->tree_ratio, t.nb + 1});
		}
}

void			ft_tree(t_param *p, t_cplx xy, double tree_angle, t_tree t)
{
	t_mlx_img	img;

	img = p->vignette ? p->mlx->param : p->mlx->win[p->fractal];
	if (t.nb >= p->it[24] + p->it_tmp[24] || t.nb < 0)
		return ;
	if (!t.nb)
	{
		ft_line(img, xy, ft_cplx_add(xy, ft_make_cplx(0, -t.size * 2)), 	\
				p->colors_tree[0]);
		xy = ft_cplx_remove(xy, ft_make_cplx(0, t.size * 2));
		ft_tree(p, xy, 0, (t_tree){p->tree_size * (p->vignette ? 0.2 : 1), 1});
		return ;
	}
	ft_branches(p, xy, tree_angle, t);
}
