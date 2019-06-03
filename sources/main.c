/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 12:28:44 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/03 10:37:13 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_create_window(t_param *p)
{
	int	i;

	p->mlx->mlx_ptr = mlx_init();
	p->mlx->mlx_loading_ptr = mlx_init();
	p->mlx->win_loading_ptr = 	\
			mlx_new_window(p->mlx->mlx_loading_ptr, 300, 100, "Loading...");
	i = -1;
	while (++i < WIDTH * HEIGHT)
		p->buddhabrot[i] = 0;
	p->fractal = -1;
	while (++p->fractal < NB_FRACTALES)
		ft_create_img(p->mlx->mlx_ptr, &p->mlx->win[p->fractal], WIDTH, HEIGHT);
	i = -1;
	while (++i < 100)
	{
		ft_create_img(p->mlx->mlx_ptr, &p->mlx->win_fern[0][i], WIDTH, HEIGHT);
		ft_create_img(p->mlx->mlx_ptr, &p->mlx->win_fern[1][i], WIDTH, HEIGHT);
		ft_create_img(p->mlx->mlx_ptr, &p->mlx->param_fern[i], DIS, HEIGHT);
	}
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param, DIS, HEIGHT);
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param2, DIS + WIDTH, PARAM);
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param_dark, DIS, HEIGHT);
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param_julia, DIS, HEIGHT);
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param_mandelbrot, DIS, HEIGHT);
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param_newton, DIS, HEIGHT);
	ft_create_img(p->mlx->mlx_ptr, &p->mlx->param_sierpinsky, DIS, HEIGHT);
}

void	ft_fractol(t_param *p)
{
	if (p->fractal >= 16)
		ft_img_dark(&p->mlx->win[p->fractal]);
	if (p->init)
		ft_init_zoom(p);
	ft_multithreading(p);
}

void	ft_start(t_param *p)
{
	p->fractal = -1;
	while (++p->fractal < NB_FRACTALES)
	{
		ft_fractol(p);
		if (p->fractal == 14 || p->fractal == 15)
			ft_display2(p, ft_buddha(p));
	}
	p->init = 0;
	p->fractal = 0;
	mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, p->mlx->win[0].ptr, 	\
			DIS, 0);
	ft_miniatures(p);
}

void	ft_malloc(t_param **p)
{
	if (!((*p) = (t_param *)malloc(sizeof(*(*p)))))
		ft_error("Malloc error");
	if (!((*p)->mlx = (t_mlx *)malloc(sizeof(*(*p)->mlx))))
		ft_error("Malloc error");
	if (!((*p)->buddhabrot = 	\
			(int *)malloc(sizeof(*(*p)->buddhabrot) * WIDTH * HEIGHT)))
		ft_error("Malloc error");
}

int		main(void)
{
	t_param *p;
	time_t	t;

	ft_malloc(&p);
	srand((unsigned)time(&t));
	ft_init(p);
	ft_start(p);
	mlx_hook(p->mlx->win_ptr, 2, 0, &ft_deal_key, p);
	mlx_mouse_hook(p->mlx->win_ptr, &ft_mouse_event_scroll, p);
	mlx_hook(p->mlx->win_ptr, 6, 0, &ft_mouse_move, p);
	mlx_hook(p->mlx->win_ptr, 5, 0, &ft_deal_key_release, p);
	mlx_hook(p->mlx->win_ptr, 17, 0, &ft_exit, p);
	mlx_loop(p->mlx->mlx_ptr);
	return (0);
}
