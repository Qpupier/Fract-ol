/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 11:48:49 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/03 12:01:47 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_it_verif(int fractal, int it, int side)
{
	/*A READAPTER AVEC LE ZOOM*/if (fractal >= 14 && fractal <= 17)
		return (0);
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

int		ft_deal_key(int key, t_param *p)
{
	//ft_putnbr(key);
	//ft_putendl("");
	if (key == ESC)
		exit(0);
	else if (key == LESS && ft_it_verif(p->fractal, p->it[p->fractal], 0))
		p->it[p->fractal] = p->it[p->fractal] <= 20 	\
				? p->it[p->fractal] - 1 : p->it[p->fractal] * 0.95;//A LIMITER
	else if (key == MORE && ft_it_verif(p->fractal, p->it[p->fractal], 1))
		p->it[p->fractal] = p->it[p->fractal] <= 20 	\
				? p->it[p->fractal] + 1 : p->it[p->fractal] * 1.05;//A LIMITER
	else if (key == S)
		p->stop = p->stop ? 0 : 1;
	else if (key == LEFT && p->pos_left[p->fractal].rl > -6)
		p->pos_left[p->fractal].rl -= 0.05 * p->zoom[p->fractal];
	else if (key == RIGHT && p->pos_left[p->fractal].rl < 2)
		p->pos_left[p->fractal].rl += 0.05 * p->zoom[p->fractal];
	else if (key == UP && p->pos_left[p->fractal].im > -6)
		p->pos_left[p->fractal].im -= 0.05 * p->zoom[p->fractal];
	else if (key == DOWN && p->pos_left[p->fractal].im < 2)
		p->pos_left[p->fractal].im += 0.05 * p->zoom[p->fractal];
	else if (key == INF)
	{
		if (p->fractal < 15 && p->deg[p->fractal] > 1)
			p->deg[p->fractal]--;
		else if (p->fractal == 20 && p->pyth_angle > -90)
			p->pyth_angle--;
	}
	else if (key == SUP)
	{
		if (p->fractal < 15 && p->deg[p->fractal] < 10)
			p->deg[p->fractal]++;
		else if (p->fractal == 20 && p->pyth_angle < 90)
			p->pyth_angle++;
	}
	else if (key == H_LESS)
	{
		if (p->fractal < 15 && p->deg_mandelbrot[p->fractal / 2 - 3] > 1)
			p->deg_mandelbrot[p->fractal / 2 - 3]--;
		else if (p->fractal == 20 && p->pyth_size)
			p->pyth_size--;
	}
	else if (key == H_MORE)
	{
		if (p->fractal < 15 && p->deg_mandelbrot[p->fractal / 2 - 3] < 10)
			p->deg_mandelbrot[p->fractal / 2 - 3]++;
		else if (p->fractal == 20)//ZOOOOOM + LIMITER
			p->pyth_size++;
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
	if (p->fractal < 14 || p->fractal > 17)
		ft_fractol(p);
	return (0);
}

int		ft_mouse_move(int x, int y, t_param *p)
{
	if (p->fractal < 5 && !p->stop && x >= DIS && x < WIDTH + DIS && y >= 0 && y < HEIGHT)
	{
		p->c[p->fractal].rl = (double)(x - DIS) * 2 / WIDTH - 1;
		p->c[p->fractal].im = (double)y * 2 / HEIGHT - 1;
		ft_fractol(p);
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

int		ft_mouse_event_scroll(int key, int x, int y, t_param *p)
{
	t_cplx	pos;
	char	*s;
	char	*tmp;

	p->mouse_l = 0;
	p->mouse_r = 0;
	if (key > 3)
	{
		x -= DIS;
		pos = ft_scale_coords(p, x, y);
		if (key == 5 && p->dis_zoom[p->fractal] < 50)
		{
			p->zoom[p->fractal] *= 0.5;
			p->dis_zoom[p->fractal]++;
		}
		else if (key == 4 && p->dis_zoom[p->fractal] > -3)
		{
			p->zoom[p->fractal] *= 2;
			p->dis_zoom[p->fractal]--;
		}
		p->pos_left[p->fractal] = ft_make_cplx(pos.rl - p->zoom[p->fractal] * x / WIDTH, pos.im - p->zoom[p->fractal] * y / HEIGHT);
	}
	else if (key == 1)
	{
		p->mouse_l = 1;
		if (x >= 0 && x < DIS && y >= 0 && y < HEIGHT)
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
					mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, p->mlx->param.ptr, 0, 0);
					ft_legend(p->mlx);
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
		}
		else if (x >= 0 && x < DIS && y >= HEIGHT && y < HEIGHT + PARAM)
			if ((p->fractal >= 23) && x >= DIS / 2 - 10 * (int)ft_strlen("  Inverted  ") && x < DIS / 2 + 10 * (int)ft_strlen("  Inverted  ") && y >= HEIGHT + 55 && y < HEIGHT + 95)
			{
				if (p->fractal == 23)
					p->koch = x < DIS / 2 ? 0 : 1;
				else
					p->tree_nb = x < DIS / 2 ? 2 : 3;
				ft_fractol(p);
			}
	}
	else if (key == 2)
		p->mouse_r = 1;
	else
	{
		tmp = ft_itoa(++p->screenshot);
		s = ft_strnew(ft_strlen("screencapture -i ~/Desktop/Fractal_screenshot_.jpg") + ft_strlen(tmp));
		ft_strcat(s, "screencapture -i ~/Desktop/Fractal_screenshot_");
		ft_strcat(s, tmp);
		ft_strcat(s, ".jpg");
		system(s);
		free(s);
		write(1, "Succesful screenshot !\n", 23);
	}
	key > 2 ? ft_fractol(p) : ft_put_image(p);
	return (0);
}

int		ft_deal_key_release(t_param *p)
{
	(void)p;
	return (0);
}
