/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_zoom_menu.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 23:20:03 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 21:10:20 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		ft_mouse_zoom(t_param *p, int key, int x, int y)
{
	t_cplx	pos;

	if (x < DIS || x >= DIS + WIDTH || y < 0 || y >= HEIGHT)
		return ;
	x -= DIS;
	pos = ft_scale_coords(p, x, y);
	if (key == 4 && (p->fractal == 20 ? p->dis_zoom[p->fractal] > -1 		\
			: p->fractal > -3) && p->dis_zoom[p->fractal] > -3)
	{
		p->zoom[p->fractal] *= 2;
		p->dis_zoom[p->fractal]--;
		if (p->fractal >= 18 && p->fractal < 21)
			ft_it_less(p, 1);
	}
	else if (key == 5 && (p->fractal == 20 ? p->dis_zoom[p->fractal] < 4 	\
			: p->fractal < 50) && p->dis_zoom[p->fractal] < 50)
	{
		p->zoom[p->fractal] *= 0.5;
		p->dis_zoom[p->fractal]++;
		if (p->fractal >= 18 && p->fractal < 21)
			ft_it_more(p, 1);
	}
	p->pos_left[p->fractal] = 												\
			ft_make_cplx(pos.rl - p->zoom[p->fractal] * x / WIDTH, 			\
			pos.im - p->zoom[p->fractal] * y / HEIGHT);
}

static void	ft_choice_0(t_param *p, int x, int y)
{
	if (x >= DIS / 2 - 40 && x < DIS / 2 && y < 30)
		ft_choice_julia(p);
	else if (x >= DIS - 40 && y < 30)
		ft_choice_mandelbrot(p);
	else if (x >= DIS / 2 - 40 && x < DIS / 2 && 	\
			y >= 2 * HEIGHT / 5 && y < 2 * HEIGHT / 5 + 30)
		ft_choice_fern(p);
	else if (x >= DIS - 40 && y >= 2 * HEIGHT / 5 && y < 2 * HEIGHT / 5 + 30)
		ft_choice_newton(p);
	else if (x >= DIS - 40 && y >= 3 * HEIGHT / 5 && y < 3 * HEIGHT / 5 + 30)
		ft_choice_sierpinski(p);
	else
		ft_choice_param(p, x * 2 / DIS, y * 5 / HEIGHT);
}

static void	ft_menu_fractals(t_param *p, int x, int y)
{
	if (!p->param)
		ft_choice_0(p, x, y);
	else
	{
		if (x >= 10 && x < 30 && y >= 10 && y < 40)
		{
			p->param = 0;
			mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, 	\
					p->mlx->param_dark.ptr, 0, 0);
		}
		else if (p->param == 1 && y >= 50)
			ft_choice_1(p, x, y);
		else if (p->param == 2 && y >= 50)
			ft_choice_2(p, x, y);
		else if (p->param == 3 && y >= 50)
			ft_choice_3(p, y);
		else if (p->param == 4 && y >= 50)
			ft_choice_4(p, y);
		else if (p->param == 5 && y >= 50)
			ft_choice_5(p, y);
	}
	ft_miniatures(p);
}

void		ft_left_click(t_param *p, int x, int y)
{
	if (!p->mouse_l && x >= DIS && x < WIDTH + DIS && y >= 0 && y < HEIGHT)
	{
		p->mouse = ft_make_cplx(x - DIS, y);
		p->mouse_l = 1;
	}
	else if (x >= 0 && x < DIS && y >= 0 && y < HEIGHT)
		ft_menu_fractals(p, x, y);
	else if (x >= DIS && x < WIDTH + DIS && y >= HEIGHT && y < HEIGHT + PARAM)
		if ((p->fractal >= 23) && x >= DIS + 10 						\
				&& x < DIS + 10 + 20 * (int)ft_strlen("  Inverted  ") 	\
				&& y >= HEIGHT + 90 && y < HEIGHT + 130)
		{
			if (p->fractal == 23)
				p->koch = x < DIS + DIS / 2 ? 0 : 1;
			else
				p->tree_nb = x < DIS + DIS / 2 ? 2 : 3;
			ft_fractol(p);
		}
}

void		ft_mouse_event_win(t_param *p, int key, int x, int y)
{
	char	*s;
	char	*tmp;

	if (key == 2 && p->dis_zoom[p->fractal] < 50 && !p->mouse_r 	\
			&& !((p->fractal >= 14 && p->fractal <= 17) || p->fractal >= 20))
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
