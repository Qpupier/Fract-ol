/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 12:28:44 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 11:37:37 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_create_window(t_param *p)
{
	int	i;
	int	tmp;

	p->mlx->mlx_ptr = mlx_init();
	p->mlx->mlx_loading_ptr = mlx_init();
	p->mlx->win_loading_ptr = 	\
			mlx_new_window(p->mlx->mlx_loading_ptr, 430, 130, "Fract'ol");
	i = -1;
	while (++i < WIDTH * HEIGHT)
		p->buddhabrot[i] = 0;
	tmp = p->fractal;
	p->fractal = -1;
	while (++p->fractal < NB_FRACTALES)
		ft_create_img(p->mlx->mlx_ptr, &p->mlx->win[p->fractal], WIDTH, HEIGHT);
	p->fractal = tmp;
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
		ft_img_dark(p->mlx->win[p->fractal]);
	ft_multithreading(p);
}

void	ft_start(t_param *p)
{
	int	tmp;

	tmp = p->fractal;
	p->fractal = -1;
	while (++p->fractal < NB_FRACTALES)
	{
		ft_fractol(p);
		if (p->fractal == 14 || p->fractal == 15)
			ft_display2(p, ft_buddha(p));
	}
	p->init = 0;
	p->fractal = tmp;
	ft_put_image(p);
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

void	ft_usage(void)
{
	ft_error("usage: ./fractol [\"Julia\",\"Mandelbrot\",\"Buddhabrot\",\"Bubblebrot\",\"Fern\",\"Newton\",\"Pythagore\",\"Sierpinsky\",\"Koch\",\"Tree\"]");
}

void	ft_init_fractal(t_param *p, char *fractal)
{
	if (ft_strequ(fractal, "Julia"))
		p->fractal = 0;
	else if (ft_strequ(fractal, "Mandelbrot"))
		p->fractal = 5;
	else if (ft_strequ(fractal, "Buddhabrot"))
		p->fractal = 14;
	else if (ft_strequ(fractal, "Bubblebrot"))
		p->fractal = 15;
	else if (ft_strequ(fractal, "Fern"))
		p->fractal = 16;
	else if (ft_strequ(fractal, "Newton"))
		p->fractal = 18;
	else if (ft_strequ(fractal, "Pythagore"))
		p->fractal = 20;
	else if (ft_strequ(fractal, "Sierpinsky"))
		p->fractal = 21;
	else if (ft_strequ(fractal, "Koch"))
		p->fractal = 23;
	else if (ft_strequ(fractal, "Tree"))
		p->fractal = 24;
	else
		ft_usage();
}

int		main(int ac, char **av)
{
	t_param *p;
	time_t	t;

	if (ac > 2)
		ft_usage();
	ft_malloc(&p);
	if (ac == 1)
		p->fractal = 0;
	else
		ft_init_fractal(p, av[1]);
	srand((unsigned)time(&t));
	ft_init(p);
	ft_img_dark(p->mlx->param_dark);
	ft_start(p);
	mlx_hook(p->mlx->win_ptr, 2, 0, &ft_deal_key, p);
	mlx_mouse_hook(p->mlx->win_ptr, &ft_mouse_event_scroll, p);
	mlx_hook(p->mlx->win_ptr, 6, 0, &ft_mouse_move, p);
	mlx_hook(p->mlx->win_ptr, 5, 0, &ft_deal_key_release, p);
	mlx_hook(p->mlx->win_ptr, 17, 0, &ft_exit, p);
	mlx_loop(p->mlx->mlx_ptr);
	return (0);
}
