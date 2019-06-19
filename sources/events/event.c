/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 11:48:49 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 21:44:36 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int		ft_deal_key(int key, t_param *p)
{
	if (key == ESC)
		exit(0);
	else if (p->fractal >= 14 && p->fractal <= 17)
		return (0);
	if (key == LESS)
		ft_it_less(p, 0);
	else if (key == MORE)
		ft_it_more(p, 0);
	else if (key == SPACE && p->fractal < 5)
		p->stop = p->stop ? 0 : 1;
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		ft_event_moves(p, key);
	else if (key == INF)
		ft_it_inf(p);
	else if (key == SUP)
		ft_it_sup(p);
	else if (key == TOP_LESS)
		ft_top_less(p);
	else if (key == TOP_MORE)
		ft_top_more(p);
	else if (key == R)
		p->init_fractal[p->fractal](p, p->fractal);
	ft_event_tree(p, key);
	ft_event_display(p, key);
	return (0);
}

int		ft_mouse_event_scroll(int key, int x, int y, t_param *p)
{
	if (key > 3 && !(p->fractal >= 14 && p->fractal <= 17) && p->fractal < 21)
		ft_mouse_zoom(p, key, x, y);
	else if (key == 1)
		ft_left_click(p, x, y);
	else if (x >= DIS && x < WIDTH + DIS && y >= 0 && y < HEIGHT)
		ft_mouse_event_win(p, key, x, y);
	if ((p->fractal < 14 || p->fractal == 21 || p->fractal == 24) 		\
			&& key <= 3 && x >= 32 && x < DIS - 32 && y >= HEIGHT + 32 	\
			&& y < HEIGHT + PARAM - 32)
	{
		if (ft_button_degraded(p, key, x - 32, y - 32 - HEIGHT))
			ft_fractol(p);
		return (0);
	}
	if (key != 3)
		(key > 2 && !(p->fractal >= 14 && p->fractal <= 17) 			\
				&& p->fractal != 21) ? ft_fractol(p) : ft_put_image(p);
	return (0);
}

void	ft_find_zoom(t_param *p, double prev, double after)
{
	while (prev > after)
	{
		p->dis_zoom[p->fractal]++;
		if (p->fractal >= 18 && p->fractal < 21)
			ft_it_more(p, 1);
		prev /= 2;
	}
}

int		ft_deal_key_release(int key, int x, int y, t_param *p)
{
	int	dx;
	int	dy;

	if ((p->fractal >= 14 && p->fractal <= 17) || p->fractal >= 21)
		return (0);
	x -= DIS;
	if (key == 2 && p->dis_zoom[p->fractal] < 50 && p->mouse_r 	\
			&& p->fractal != 20 && !ft_cplx_equ(p->mouse, ft_make_cplx(x, y)))
	{
		x = x < 0 ? 0 : x;
		x = x >= WIDTH ? WIDTH - 1 : x;
		y = y < 0 ? 0 : y;
		y = y >= HEIGHT ? HEIGHT - 1 : y;
		dx = ft_abs(p->mouse.rl - x);
		dy = ft_abs(p->mouse.im - y);
		if (dx < dy)
			ft_refresh_1(p, x, y);
		else
			ft_refresh_2(p, x, y);
		ft_fractol(p);
	}
	p->mouse_l = 0;
	p->mouse_r = 0;
	return (0);
}

void	ft_params3(t_param *p, int n)
{
	if (p->fractal < 5)
	{
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10, n, 	\
				WHITE_H, p->stop 										\
				? "Julia variations : Disable" : "Julia variations : Enable");
		n += 30;
	}
	if (p->fractal < 14)
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10, 		\
				HEIGHT + PARAM - 30, WHITE_H, "3 colors : ");
	else if (p->fractal == 21 || p->fractal == 24)
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10, 		\
				HEIGHT + PARAM - 30, WHITE_H, "2 colors : ");
	ft_params_help(p);
}
