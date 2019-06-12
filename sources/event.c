/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 11:48:49 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 19:00:56 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_it_verif(int fractal, int it, int side)
{
	if (!side)
	{
		if (it)
			return (1);
	}
	else if (it < 1000)
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

double	ft_min(double a, double b)
{
	return (a < b ? a : b);
}

double	ft_max(double a, double b)
{
	return (a > b ? a : b);
}

void	ft_it_less(t_param *p, int tmp)
{
	if (ft_it_verif(p->fractal, p->it[p->fractal], 0))
	{
		if (tmp)
			p->it_tmp[p->fractal] = p->it[p->fractal] + p->it_tmp[p->fractal] <= 20 || !p->it_tmp[p->fractal] 	\
					? p->it_tmp[p->fractal] - 0.5 : p->it_tmp[p->fractal] * 0.99;
		else
			p->it[p->fractal] = p->it[p->fractal] <= 20 	\
					? p->it[p->fractal] - 1 : p->it[p->fractal] * 0.95;
	}
}

void	ft_it_more(t_param *p, int tmp)
{
	if (ft_it_verif(p->fractal, p->it[p->fractal], 1))
	{
		if (tmp)
			p->it_tmp[p->fractal] = p->it[p->fractal] + p->it_tmp[p->fractal] <= 20 || !p->it_tmp[p->fractal] 	\
					? p->it_tmp[p->fractal] + 0.5 : p->it_tmp[p->fractal] * 1.01;
		else
			p->it[p->fractal] = p->it[p->fractal] <= 20 	\
					? p->it[p->fractal] + 1 : p->it[p->fractal] * 1.05;
	}
}

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
	else if (key == LEFT && p->fractal < 21 && p->pos_left[p->fractal].rl > -6)
		p->pos_left[p->fractal].rl -= 0.05 * p->zoom[p->fractal];
	else if (key == RIGHT && p->fractal < 21 && p->pos_left[p->fractal].rl < 2)
		p->pos_left[p->fractal].rl += 0.05 * p->zoom[p->fractal];
	else if (key == UP && p->fractal < 21 && p->pos_left[p->fractal].im > -6)
		p->pos_left[p->fractal].im -= 0.05 * p->zoom[p->fractal];
	else if (key == DOWN && p->fractal < 21 && p->pos_left[p->fractal].im < 2)
		p->pos_left[p->fractal].im += 0.05 * p->zoom[p->fractal];
	else if (key == INF)
	{
		if (p->fractal < 13 && p->deg[p->fractal] > 1)
			p->deg[p->fractal]--;
		else if ((p->fractal == 18 || p->fractal == 19) && p->deg_newton[p->fractal - 18] > 2)
			p->deg_newton[p->fractal - 18]--;
		else if (p->fractal == 20 && p->pyth_angle > -90)
			p->pyth_angle--;
		else if (p->fractal == 24 && p->tree_size > 10)
			p->tree_size--;
	}
	else if (key == SUP)
	{
		if (p->fractal < 15 && p->deg[p->fractal] < 10)
			p->deg[p->fractal]++;
		else if ((p->fractal == 18 || p->fractal == 19) && p->deg_newton[p->fractal - 18] < 15)
			p->deg_newton[p->fractal - 18]++;
		else if (p->fractal == 20 && p->pyth_angle < 90)
			p->pyth_angle++;
		else if (p->fractal == 24 && p->tree_size < HEIGHT / 4)
			p->tree_size++;
	}
	else if (key == H_LESS)
	{
		if (p->fractal < 15 && p->deg_mandelbrot[p->fractal / 2 - 3] > 1)
			p->deg_mandelbrot[p->fractal / 2 - 3]--;
		else if (p->fractal == 24 && p->tree_ratio > 0.5)
			p->tree_ratio -= 0.1;
	}
	else if (key == H_MORE)
	{
		if (p->fractal < 15 && p->deg_mandelbrot[p->fractal / 2 - 3] < 10)
			p->deg_mandelbrot[p->fractal / 2 - 3]++;
		else if (p->fractal == 24 && p->tree_ratio < 0.9)
			p->tree_ratio += 0.1;
	}
	else if (p->fractal == 24)
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
	else if (key == R)
		p->init_fractal[p->fractal](p, p->fractal);
	ft_fractol(p);
	if (key == R)
		ft_miniatures(p);
	return (0);
}

int		ft_mouse_move(int x, int y, t_param *p)
{
	t_cplx tmp;
	int		i;

	if ((p->fractal >= 14 && p->fractal <= 17) || p->fractal >= 21)
		return (0);
	x -= DIS;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (p->fractal < 5 && !p->stop)
		{
			p->c[p->fractal] = ft_make_cplx(x * 2.0 / WIDTH - 1, y * 2.0 / HEIGHT - 1);
			ft_fractol(p);
		}
		if (p->mouse_l)
		{
			p->mouse_r = 0;
			tmp = ft_make_cplx(x, y);
			p->pos_left[p->fractal] = 								\
					ft_cplx_remove(p->pos_left[p->fractal], 		\
					ft_cplx_div(ft_cplx_mult(ft_cplx_remove(tmp, 	\
					p->mouse), ft_make_cplx(p->zoom[p->fractal], 	\
					p->zoom[p->fractal])), ft_make_cplx(WIDTH, HEIGHT)));
			p->mouse = tmp;
			ft_fractol(p);
		}
		else if (p->mouse_r && !ft_cplx_equ(p->mouse, ft_make_cplx(x, y)))
		{
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
			mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, p->mlx->win[p->fractal].ptr, DIS, 0);
		}
	}
	return (0);
}

void	ft_choice_param(t_param *p, int x, int y)
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
		else if (y == 3)
			p->fractal = 21;
		else
			p->fractal = 24;
	}
}

int		ft_button_degraded(t_param *p, int key, double x, double y)
{
	t_rgb	color;

	color = ft_color_average(ft_color_average(RED, BLUE, x / 256), 	\
			ft_color_average(GREEN, WHITE, x / 256), y / 256);
	if (key == 1 && p->fractal < 14)
			p->colors[1] = color;
	else if (key == 1 && p->fractal == 21)
		p->colors_carpet[0] = color;
	else if (key == 1)
		p->colors_tree[0] = color;
	else if (key == 2 && p->fractal < 14)
		p->colors[3] = color;
	else if (key == 2 && p->fractal == 21)
		p->colors_carpet[1] = color;
	else if (key == 2)
		p->colors_tree[1] = color;
	else if (p->fractal < 14)
		p->colors[2] = color;
	else
		return (0);
	return (1);
}

int		ft_mouse_event_scroll(int key, int x, int y, t_param *p)
{
	t_cplx	pos;
	char	*s;
	char	*tmp;

	if (key > 3 && !((p->fractal >= 14 && p->fractal <= 17) || p->fractal >= 21))
	{
		x -= DIS;
		pos = ft_scale_coords(p, x, y);
		if (key == 4 && (p->fractal == 20 ? p->dis_zoom[p->fractal] > -1 : p->fractal > -3) && p->dis_zoom[p->fractal] > -3)
		{
			p->zoom[p->fractal] *= 2;
			p->dis_zoom[p->fractal]--;
			if (p->fractal >= 18 && p->fractal < 21)
				ft_it_less(p, 1);
		}
		else if (key == 5 && (p->fractal == 20 ? p->dis_zoom[p->fractal] < 4 : p->fractal < 50) && p->dis_zoom[p->fractal] < 50)
		{
			p->zoom[p->fractal] *= 0.5;
			p->dis_zoom[p->fractal]++;
			if (p->fractal >= 18 && p->fractal < 21)
				ft_it_more(p, 1);
		}
		p->pos_left[p->fractal] = ft_make_cplx(pos.rl - p->zoom[p->fractal] * x / WIDTH, pos.im - p->zoom[p->fractal] * y / HEIGHT);
	}
	else if (key == 1)
	{
		if (!p->mouse_l && x >= DIS && x < WIDTH + DIS && y >= 0 && y < HEIGHT)
		{
			p->mouse = ft_make_cplx(x - DIS, y);
			p->mouse_l = 1;
		}
		else if (x >= 0 && x < DIS && y >= 0 && y < HEIGHT)
		{
			if (!p->param)
			{
				if (x >= DIS / 2 - 40 && x < DIS / 2 && y < 30)
					ft_choice_julia(p);
				else if (x >= DIS - 40 && y < 30)
					ft_choice_mandelbrot(p);
				else if (x >= DIS / 2 - 40 && x < DIS / 2 && y >= 2 * HEIGHT / 5 && y < 2 * HEIGHT / 5 + 30)
					ft_choice_fern(p);
				else if (x >= DIS - 40 && y >= 2 * HEIGHT / 5 && y < 2 * HEIGHT / 5 + 30)
					ft_choice_newton(p);
				else if (x >= DIS - 40 && y >= 3 * HEIGHT / 5 && y < 3 * HEIGHT / 5 + 30)
					ft_choice_sierpinsky(p);
				else
					ft_choice_param(p, x * 2 / DIS, y * 5 / HEIGHT);
			}
			else
			{
				if (x >= 10 && x < 30 && y >= 10 && y < 40)
				{
					p->param = 0;
					mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, p->mlx->param_dark.ptr, 0, 0);
				}
				else if (p->param == 1 && y >= 50)
				{
					if (y < (HEIGHT - 50) / 2 + 50)
						p->fractal = 0;
					else if (x < DIS / 2 && y < HEIGHT - (HEIGHT - 50) / 4)
						p->fractal = 1;
					else if (y < HEIGHT - (HEIGHT - 50) / 4)
						p->fractal = 2;
					else if (x < DIS / 2)
						p->fractal = 3;
					else
						p->fractal = 4;
				}
				else if (p->param == 2 && y >= 50)
				{
					if (y < (HEIGHT - 50) / 3 + 50)
						p->fractal = 5;
					else if (x < DIS / 2 && y < (HEIGHT - 50) / 2 + 50)
						p->fractal = 6;
					else if (y < (HEIGHT - 50) / 2 + 50)
						p->fractal = 7;
					else if (x < DIS / 2 && y < 2 * (HEIGHT - 50) / 3 + 50)
						p->fractal = 8;
					else if (y < 2 * (HEIGHT - 50) / 3 + 50)
						p->fractal = 9;
					else if (x < DIS / 2 && y < 5 * (HEIGHT - 50) / 6 + 50)
						p->fractal = 10;
					else if (y < 5 * (HEIGHT - 50) / 6 + 50)
						p->fractal = 11;
					else if (x < DIS / 2)
						p->fractal = 12;
					else
						p->fractal = 13;
				}
				else if (p->param == 3 && y >= 50)
				{
					if (y < (HEIGHT - 50) / 2 + 50)
						p->fractal = 16;
					else
						p->fractal = 17;
				}
				else if (p->param == 4 && y >= 50)
				{
					if (y < (HEIGHT - 50) / 2 + 50)
						p->fractal = 18;
					else
						p->fractal = 19;
				}
				else if (p->param == 5 && y >= 50)
				{
					if (y < (HEIGHT - 50) / 2 + 50)
						p->fractal = 21;
					else
						p->fractal = 22;
				}
			}
			ft_miniatures(p);
		}
		else if (x >= DIS && x < WIDTH + DIS && y >= HEIGHT && y < HEIGHT + PARAM)
			if ((p->fractal >= 23) && x >= DIS + 10 && x < DIS + 10 + 20 * (int)ft_strlen("  Inverted  ") && y >= HEIGHT + 90 && y < HEIGHT + 130)
			{
				if (p->fractal == 23)
					p->koch = x < DIS + DIS / 2 ? 0 : 1;
				else
					p->tree_nb = x < DIS + DIS / 2 ? 2 : 3;
				ft_fractol(p);
			}
	}
	else if (x >= DIS && x < WIDTH + DIS && y >= 0 && y < HEIGHT)
	{
		if (key == 2 && p->dis_zoom[p->fractal] < 50 && !p->mouse_r && !((p->fractal >= 14 && p->fractal <= 17) || p->fractal >= 20))
		{
			p->mouse = ft_make_cplx(x - DIS, y);
			p->mouse_r = 1;
		}
		else if (key == 3)
		{
			tmp = ft_itoa(++p->screenshot);
			if (!(s = ft_strnew(ft_strlen("screencapture -i 	\
					~/Desktop/Fractal_screenshot_.jpg") + ft_strlen(tmp))))
				ft_error("Malloc error");
			ft_strcat(s, "screencapture -i ~/Desktop/Fractal_screenshot_");
			ft_strcat(s, tmp);
			ft_strdel(&tmp);
			ft_strcat(s, ".jpg");
			system(s);
			ft_strdel(&s);
			ft_putendl("Succesful screenshot !");
		}
	}
	if ((p->fractal < 14 || p->fractal == 21 || p->fractal == 24) && key <= 3 && x >= 32 && x < DIS - 32 && y >= HEIGHT + 32 && y < HEIGHT + PARAM - 32)
	{
		if (ft_button_degraded(p, key, x - 32, y - 32 - HEIGHT))
			ft_fractol(p);
		return (0);
	}
	if (key != 3)
		(key > 2 && !((p->fractal >= 14 && p->fractal <= 17) || p->fractal == 21)) ? ft_fractol(p) : ft_put_image(p);
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
	if (key == 2 && p->dis_zoom[p->fractal] < 50 && p->mouse_r && p->fractal != 20 && !ft_cplx_equ(p->mouse, ft_make_cplx(x, y)))
	{
		x = x < 0 ? 0 : x;
		x = x >= WIDTH ? WIDTH - 1 : x;
		y = y < 0 ? 0 : y;
		y = y >= HEIGHT ? HEIGHT - 1 : y;
		dx = ft_abs(p->mouse.rl - x);
		dy = ft_abs(p->mouse.im - y);
		if (dx < dy)
		{
			p->pos_left[p->fractal] = ft_scale_coords(p, 					\
					ft_min(p->mouse.rl, x) - (dy - dx) / 2, 				\
					ft_min(p->mouse.im, y));
			ft_find_zoom(p, p->zoom[p->fractal], 	\
					(p->zoom[p->fractal] = dy * p->zoom[p->fractal] / MIN));
		}
		else
		{
			p->pos_left[p->fractal] = ft_scale_coords(p, 					\
					ft_min(p->mouse.rl, x), 								\
					ft_min(p->mouse.im, y) - (dx - dy) / 2);
			ft_find_zoom(p, p->zoom[p->fractal], 	\
					(p->zoom[p->fractal] = dx * p->zoom[p->fractal] / MIN));
		}
		ft_fractol(p);
	}
	p->mouse_l = 0;
	p->mouse_r = 0;
	return (0);
}
