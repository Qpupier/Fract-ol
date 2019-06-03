/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/12 21:00:43 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/31 21:16:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_loading(t_param *p)
{
	char	*fractal;

	fractal = ft_itoa((p->fractal + 1) * 100 / NB_FRACTALES);
	ft_trace_borders(p->mlx->mlx_loading_ptr, p->mlx->win_loading_ptr, 	\
			p->fractal);
	mlx_string_put(p->mlx->mlx_loading_ptr, p->mlx->win_loading_ptr, 	\
			135, 40, WHITE_H, fractal);
	mlx_string_put(p->mlx->mlx_loading_ptr, p->mlx->win_loading_ptr, 	\
			145, 40, WHITE_H, "  %");
	free(fractal);
	mlx_do_sync(p->mlx->mlx_loading_ptr);
	if (p->fractal == 24)
	{
		mlx_destroy_window(p->mlx->mlx_loading_ptr, p->mlx->win_loading_ptr);
		p->mlx->win_ptr = mlx_new_window(p->mlx->mlx_ptr, 				\
				WIDTH + DIS, HEIGHT + PARAM, "Fract'ol");
	}
}

void	*ft_display(void *t)
{
	int		i;
	int		j;
	t_param	*p;

	p = (t_param *)t;
	i = -1;
	while (++i < HEIGHT)
	{
		j = p->min - 1;
		while (++j < p->max)
			ft_algo(p, j, i);
	}
	return (t);
}

int		ft_choice_fractal(t_param *p)
{
	int	i;

	i = 100;
	if (p->fractal == 16 || p->fractal == 17)
		while (i--)
		{
			ft_img_dark(&p->mlx->win_fern[p->fractal - 16][i]);
			ft_fern(p->mlx->win_fern[p->fractal - 16][i], p->fern, 			\
					p->fractal - 16, p->it[p->fractal]);
		}
	else if (p->fractal == 20)
		ft_pythagore(p, ft_make_cplx(WIDTH / 2 - p->pyth_size / 2, 			\
				HEIGHT - 200 - p->pyth_size), (t_pyth){0, p->pyth_size, 0, 0});
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
				(t_tree){SIZE / 5, 0});
	return ((p->fractal > 15 && p->fractal != 18) ? 1 : 0);
}

void	ft_put_image(t_param *p)
{
	int	i;

	i = 100;
	mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, 			\
			p->mlx->win[p->fractal].ptr, DIS, 0);
	if (p->fractal == 16 || p->fractal == 17)
		while (i--)
			mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, 	\
					p->mlx->win_fern[p->fractal - 16][i].ptr, DIS, 0);
	ft_img_dark(&p->mlx->param2);
	ft_params(p);
}

void	ft_multithreading(t_param *p)
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
