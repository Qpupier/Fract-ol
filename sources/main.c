/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 12:28:44 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 15:46:45 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_fractol(t_param *p)
{
	if (p->fractal >= 16)
		ft_img_dark(p->mlx->win[p->fractal]);
	ft_multithreading(p);
}

static void	ft_start(t_param *p)
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

static void	ft_malloc(t_param **p)
{
	if (!((*p) = (t_param *)malloc(sizeof(*(*p)))))
		ft_error("Malloc error");
	if (!((*p)->mlx = (t_mlx *)malloc(sizeof(*(*p)->mlx))))
		ft_error("Malloc error");
	if (!((*p)->buddhabrot = 	\
			(int *)malloc(sizeof(*(*p)->buddhabrot) * WIDTH * HEIGHT)))
		ft_error("Malloc error");
}

void		ft_usage(void)
{
	ft_error("usage: ./fractol [\"Julia\",\"Mandelbrot\",\"Buddhabrot\",\
\"Bubblebrot\",\"Fern\",\"Newton\",\"Pythagore\",\"Sierpinski\",\"Koch\",\
\"Tree\"]");
}

int			main(int ac, char **av)
{
	t_param *p;
	time_t	t;

	if (ac != 2)
		ft_usage();
	ft_malloc(&p);
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
