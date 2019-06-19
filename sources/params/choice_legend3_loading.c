/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   choice_legend3_loading.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/17 09:25:26 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 22:53:50 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		ft_legend_sierpinski(void *mlx_ptr, void *win_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 									\
			DIS / 2 - 5 * ft_strlen("Fractales de Sierpinski"), 15, 	\
			WHITE_H, "Fractales de Sierpinski");
	mlx_string_put(mlx_ptr, win_ptr, 5, 50 + 5, WHITE_H, "CARPET");
	mlx_string_put(mlx_ptr, win_ptr, 									\
			5, 50 + 5 + (HEIGHT - 50) / 2, WHITE_H, "TRIANGLE");
}

void		ft_choice_sierpinski(t_param *p)
{
	int	i;

	i = -1;
	while (++i < HEIGHT)
		ft_pixel_put(p->mlx->param_sierpinski, DIS - 1, i, WHITE);
	i = -1;
	while (++i < DIS)
	{
		ft_pixel_put(p->mlx->param_sierpinski, i, 50, WHITE);
		ft_pixel_put(p->mlx->param_sierpinski, i, 		\
				(HEIGHT - 50) / 2 + 50, WHITE);
	}
	ft_return_button(p->mlx->param_sierpinski);
	mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, 	\
			p->mlx->param_sierpinski.ptr, 0, 0);
	ft_legend_sierpinski(p->mlx->mlx_ptr, p->mlx->win_ptr);
	p->param = 5;
}

static void	ft_loading_names(t_param *p, void *mlx_ptr, void *win_ptr)
{
	if (p->fractal < 5)
		mlx_string_put(mlx_ptr, win_ptr, 10, 90, GREY_H, "Julia");
	else if (p->fractal < 14)
		mlx_string_put(mlx_ptr, win_ptr, 10, 90, GREY_H, "Mandelbrot");
	else if (p->fractal < 15)
		mlx_string_put(mlx_ptr, win_ptr, 10, 90, GREY_H, "Buddhabrot");
	else if (p->fractal < 16)
		mlx_string_put(mlx_ptr, win_ptr, 10, 90, GREY_H, "Bubblebrot");
	else if (p->fractal < 18)
		mlx_string_put(mlx_ptr, win_ptr, 10, 90, GREY_H, "Fern");
	else if (p->fractal < 20)
		mlx_string_put(mlx_ptr, win_ptr, 10, 90, GREY_H, "Newton");
	else if (p->fractal < 21)
		mlx_string_put(mlx_ptr, win_ptr, 10, 90, GREY_H, "Pythagore");
	else if (p->fractal < 23)
		mlx_string_put(mlx_ptr, win_ptr, 10, 90, GREY_H, "Sierpinski");
	else if (p->fractal < 24)
		mlx_string_put(mlx_ptr, win_ptr, 10, 90, GREY_H, "Koch");
	else
		mlx_string_put(mlx_ptr, win_ptr, 10, 90, GREY_H, "Tree");
}

static void	ft_loading_next(t_param *p)
{
	mlx_destroy_window(p->mlx->mlx_loading_ptr, p->mlx->win_loading_ptr);
	p->mlx->win_ptr = mlx_new_window(p->mlx->mlx_ptr, WIDTH + DIS, 	\
			HEIGHT + PARAM, "Fract'ol");
}

void		ft_loading(t_param *p)
{
	char	*fractal;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = p->mlx->mlx_loading_ptr;
	win_ptr = p->mlx->win_loading_ptr;
	ft_trace_borders(mlx_ptr, win_ptr, p->fractal);
	fractal = ft_itoa((p->fractal + 1) * 100 / NB_FRACTALES);
	mlx_string_put(mlx_ptr, win_ptr, 400 - 10 * ft_strlen(fractal) + 5, 	\
			20, WHITE_H, fractal);
	ft_strdel(&fractal);
	mlx_string_put(mlx_ptr, win_ptr, 410, 20, WHITE_H, "%");
	mlx_string_put(mlx_ptr, win_ptr, 10, 20, WHITE_H, "Loading...");
	fractal = ft_itoa(p->fractal + 1);
	mlx_string_put(mlx_ptr, win_ptr, p->fractal < 9 ? 370 : 360, 90, 		\
			GREY_H, fractal);
	ft_strdel(&fractal);
	mlx_string_put(mlx_ptr, win_ptr, 385, 90, GREY_H, "/");
	fractal = ft_itoa(NB_FRACTALES);
	mlx_string_put(mlx_ptr, win_ptr, 400, 90, GREY_H, fractal);
	ft_strdel(&fractal);
	ft_loading_names(p, mlx_ptr, win_ptr);
	mlx_do_sync(p->mlx->mlx_loading_ptr);
	if (p->fractal == 24)
		ft_loading_next(p);
}
