/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_moves_choices.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 23:18:01 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 22:07:23 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	ft_mouse_left_click(t_param *p, int x, int y)
{
	t_cplx tmp;
	t_cplx tmp2;

	p->mouse_r = 0;
	tmp = ft_make_cplx(x, y);
	tmp2 = ft_cplx_remove(p->pos_left[p->fractal], 						\
			ft_cplx_div(ft_cplx_mult(ft_cplx_remove(tmp, p->mouse), 	\
			ft_make_cplx(p->zoom[p->fractal], p->zoom[p->fractal])), 	\
			ft_make_cplx(WIDTH, HEIGHT)));
	if (p->fractal >= 21 												\
			|| (tmp2.rl <= -6 && tmp2.rl < p->pos_left[p->fractal].rl) 	\
			|| (tmp2.rl >= 2 && tmp2.rl > p->pos_left[p->fractal].rl) 	\
			|| (tmp2.im <= -6 && tmp2.im < p->pos_left[p->fractal].im) 	\
			|| (tmp2.im >= 2 && tmp2.im > p->pos_left[p->fractal].im))
		return ;
	p->pos_left[p->fractal] = tmp2;
	p->mouse = tmp;
	ft_fractol(p);
}

static void	ft_mouse_right_click(t_param *p, int x, int y)
{
	int	i;

	p->mouse_l = 0;
	ft_fractol(p);
	i = ft_min(p->mouse.rl, x) - 1;
	while (++i <= ft_max(p->mouse.rl, x))
	{
		ft_pixel_put(p->mlx->win[p->fractal], i, p->mouse.im, WHITE);
		ft_pixel_put(p->mlx->win[p->fractal], i, y, WHITE);
	}
	i = ft_min(p->mouse.im, y) - 1;
	while (++i <= ft_max(p->mouse.im, y))
	{
		ft_pixel_put(p->mlx->win[p->fractal], p->mouse.rl, i, WHITE);
		ft_pixel_put(p->mlx->win[p->fractal], x, i, WHITE);
	}
	mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, 	\
			p->mlx->win[p->fractal].ptr, DIS, 0);
}

int			ft_mouse_move(int x, int y, t_param *p)
{
	if ((p->fractal >= 14 && p->fractal <= 17) || p->fractal >= 21)
		return (0);
	x -= DIS;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (p->fractal < 5 && !p->stop)
		{
			p->c[p->fractal] = 	\
					ft_make_cplx(x * 2.0 / WIDTH - 1, y * 2.0 / HEIGHT - 1);
			ft_fractol(p);
		}
		if (p->mouse_l)
			ft_mouse_left_click(p, x, y);
		else if (p->mouse_r && !ft_cplx_equ(p->mouse, ft_make_cplx(x, y)))
			ft_mouse_right_click(p, x, y);
	}
	return (0);
}

void		ft_choice_param(t_param *p, int x, int y)
{
	if (!x)
	{
		if (!y)
			p->fractal = 0;
		else if (y == 1)
			p->fractal = 14;
		else if (y == 2)
			p->fractal = 16;
		else if (y == 3)
			p->fractal = 20;
		else
			p->fractal = 23;
	}
	else
	{
		if (!y)
			p->fractal = 5;
		else if (y == 1)
			p->fractal = 15;
		else if (y == 2)
			p->fractal = 18;
		else
			p->fractal = (y == 3) ? 21 : 24;
	}
}

int			ft_button_degraded(t_param *p, int key, double x, double y)
{
	t_rgb	color;

	color = ft_color_average(ft_color_average(RED, BLUE, x / 256), 	\
			ft_color_average(GREEN, WHITE, x / 256), y / 256);
	if (key == 1 && p->fractal < 14)
		p->colors[p->fractal][1] = color;
	else if (key == 1 && p->fractal == 21)
		p->colors_carpet[0] = color;
	else if (key == 1)
		p->colors_tree[0] = color;
	else if (key == 2 && p->fractal < 14)
		p->colors[p->fractal][3] = color;
	else if (key == 2 && p->fractal == 21)
		p->colors_carpet[1] = color;
	else if (key == 2)
		p->colors_tree[1] = color;
	else if (p->fractal < 14)
		p->colors[p->fractal][2] = color;
	else
		return (0);
	return (1);
}
