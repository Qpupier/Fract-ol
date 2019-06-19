/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_colors.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/12 21:00:43 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 22:53:51 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		ft_colors(t_param *p)
{
	double	i;
	double	j;

	i = 32 - 2;
	while (++i <= 32 + 256)
	{
		ft_pixel_put(p->mlx->param2, i, 31, WHITE);
		ft_pixel_put(p->mlx->param2, i, 32 + 256, WHITE);
		ft_pixel_put(p->mlx->param2, 31, i, WHITE);
		ft_pixel_put(p->mlx->param2, 32 + 256, i, WHITE);
	}
	j = -1;
	while (++j < 256)
	{
		i = -1;
		while (++i < 256)
			ft_pixel_put(p->mlx->param2, i + 32, j + 32, 			\
			ft_color_average(ft_color_average(RED, BLUE, i / 256), 	\
			ft_color_average(GREEN, WHITE, i / 256), j / 256));
	}
}

t_rgb		ft_sierpinski_color(t_param *p, int nb)
{
	return (nb > 1 ? ft_color_average(p->colors_carpet[0], 				\
			p->colors_carpet[1], (double)(nb - 1) / (p->it[21] - 1)) 	\
			: p->colors_carpet[0]);
}

static int	ft_choice_fractal(t_param *p)
{
	if (p->fractal == 16 || p->fractal == 17)
		ft_img_fern(p);
	else if (p->fractal == 20)
		ft_pythagore(p, ft_make_cplx(ft_inverse_coords(p, 0, 0).rl - 400 	\
				/ p->zoom[p->fractal] * 0.5, 								\
				ft_inverse_coords(p, 0, 2).im - 1200 						\
				/ p->zoom[p->fractal]), 									\
				(t_pyth){0, 400 / p->zoom[p->fractal], 0, 0});
	else if (p->fractal == 21)
		ft_sierpinski_carpet(p, ft_make_real(0, 0), 						\
				ft_make_real(WIDTH, HEIGHT), 1);
	else if (p->fractal == 22)
		ft_sierpinski_triangle(p, ft_make_real((WIDTH - MIN + 30) * 0.5, 	\
				(2 * HEIGHT - (MIN - 30) * sqrt(3)) * 0.25), MIN - 30, 0);
	else if (p->fractal == 23)
		ft_size_koch(p, ft_make_cplx(0, 0), WIDTH, HEIGHT);
	else if (p->fractal == 24)
		ft_tree(p, ft_make_cplx(WIDTH / 2, HEIGHT - HEIGHT / 10), 0, 		\
				(t_tree){p->tree_size, 0});
	return ((p->fractal > 15 && p->fractal != 18 && p->fractal != 19) ? 1 : 0);
}

void		ft_multithreading(t_param *p)
{
	pthread_t	thread[THREAD_MAX];
	t_param		multi[THREAD_MAX];
	int			i;

	if (!ft_choice_fractal(p))
	{
		i = -1;
		while (++i < THREAD_MAX)
		{
			multi[i] = *p;
			multi[i].min = THREAD_WIDTH * i;
			multi[i].max = multi[i].min + THREAD_WIDTH;
			pthread_create(&thread[i], NULL, ft_display, &multi[i]);
		}
		while (i--)
			pthread_join(thread[i], NULL);
	}
	p->init ? ft_loading(p) : ft_put_image(p);
}

void		ft_refresh(t_param *p)
{
	int	i;

	i = -1;
	if (!p->param)
		ft_init_params(p);
	else if (p->param == 1)
		ft_choice_julia(p);
	else if (p->param == 2)
		ft_choice_mandelbrot(p);
	else if (p->param == 3)
		ft_choice_fern(p);
	else if (p->param == 4)
		ft_choice_newton(p);
	else
		ft_choice_sierpinski(p);
}
