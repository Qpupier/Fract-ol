/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   choice_legend.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 20:25:50 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 18:15:53 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_button(t_mlx_img img, int x, int y)
{
	ft_line(img, ft_make_cplx(x + DIS / 2 - 20, y + 21), 	\
			ft_make_cplx(x + DIS / 2 - 9, y + 10), WHITE);
	ft_line(img, ft_make_cplx(x + DIS / 2 - 20, y + 20), 	\
			ft_make_cplx(x + DIS / 2 - 10, y + 10), WHITE);
	ft_line(img, ft_make_cplx(x + DIS / 2 - 20, y + 20), 	\
			ft_make_cplx(x + DIS / 2 - 30, y + 10), WHITE);
	ft_line(img, ft_make_cplx(x + DIS / 2 - 20, y + 21), 	\
			ft_make_cplx(x + DIS / 2 - 31, y + 10), WHITE);
}

void	ft_legend_julia(void *mlx_ptr, void *win_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 							\
			DIS / 2 - 5 * ft_strlen("Fractales de Julia"), 15, 	\
			WHITE_H, "Fractales de Julia");
	mlx_string_put(mlx_ptr, win_ptr, 5, 50 + 5, WHITE_H, "JULIA");
	mlx_string_put(mlx_ptr, win_ptr, 							\
			5, 50 + 5 + (HEIGHT - 50) / 2, WHITE_H, "JULIA SHIP");
	mlx_string_put(mlx_ptr, win_ptr, 							\
			5 + DIS / 2, 50 + 5 + (HEIGHT - 50) / 2, WHITE_H, "JULIA CROSS");
	mlx_string_put(mlx_ptr, win_ptr, 							\
			5, 50 + 5 + 3 * (HEIGHT - 50) / 4, WHITE_H, "FULL JULIA");
	mlx_string_put(mlx_ptr, win_ptr, 							\
			5 + DIS / 2, 50 + 5 + 3 * (HEIGHT - 50) / 4, 		\
			WHITE_H, "JULIA INSECT");
}

void	ft_legend_mandelbrot(void *mlx_ptr, void *win_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 									\
			DIS / 2 - 5 * ft_strlen("Fractales de Mandelbrot"), 15, 	\
			WHITE_H, "Fractales de Mandelbrot");
	mlx_string_put(mlx_ptr, win_ptr, 5, 50 + 5, WHITE_H, "MANDELBROT");
	mlx_string_put(mlx_ptr, win_ptr, 									\
			5, 50 + (HEIGHT - 50) / 3 + 5, WHITE_H, "BURNING SHIP");
	mlx_string_put(mlx_ptr, win_ptr, 									\
			5 + DIS / 2, 50 + 5 + (HEIGHT - 50) / 3, WHITE_H, "CROSS");
	mlx_string_put(mlx_ptr, win_ptr, 									\
			5, 50 + 5 + (HEIGHT - 50) / 2, 					\
			WHITE_H, "FULL MANDELBROT");
	mlx_string_put(mlx_ptr, win_ptr, 									\
			5 + DIS / 2, 50 + 5 + (HEIGHT - 50) / 2, WHITE_H, "INVERTED");
	mlx_string_put(mlx_ptr, win_ptr, 									\
			5, 50 + 5 + 2 * (HEIGHT - 50) / 3, WHITE_H, "MIRROR");
	mlx_string_put(mlx_ptr, win_ptr, 									\
			5 + DIS / 2, 50 + 5 + 2 * (HEIGHT - 50) / 3, WHITE_H, "STAR");
	mlx_string_put(mlx_ptr, win_ptr, 									\
			5, 50 + 5 + 5 * (HEIGHT - 50) / 6, WHITE_H, "CIRCLE");
	mlx_string_put(mlx_ptr, win_ptr, 									\
			5 + DIS / 2, 50 + 5 + 5 * (HEIGHT - 50) / 6, 				\
			WHITE_H, "RETURN CIRCLE");
}

void	ft_choice_julia(t_param *p)
{
	int	i;

	i = -1;
	while (++i < HEIGHT)
		ft_pixel_put(p->mlx->param_julia, DIS - 1, i, WHITE);
	i = (HEIGHT - 50) / 2 - 1 + 50;
	while (++i < HEIGHT)
		ft_pixel_put(p->mlx->param_julia, DIS / 2, i, WHITE);
	i = -1;
	while (++i < DIS)
	{
		ft_pixel_put(p->mlx->param_julia, i, 50, WHITE);
		ft_pixel_put(p->mlx->param_julia, i, (HEIGHT - 50) / 2 + 50, WHITE);
		ft_pixel_put(p->mlx->param_julia, i, 3 * (HEIGHT - 50) / 4 + 50, WHITE);
	}
	ft_return_button(p->mlx->param_julia);
	mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, 	\
			p->mlx->param_julia.ptr, 0, 0);
	ft_legend_julia(p->mlx->mlx_ptr, p->mlx->win_ptr);
	p->param = 1;
}

void	ft_choice_mandelbrot(t_param *p)
{
	int			i;
	t_mlx_img	m;

	m = p->mlx->param_mandelbrot;
	i = -1;
	while (++i < HEIGHT)
		ft_pixel_put(m, DIS - 1, i, WHITE);
	i = (HEIGHT - 50) / 3 + 50 - 1;
	while (++i < HEIGHT)
		ft_pixel_put(m, DIS / 2, i, WHITE);
	i = -1;
	while (++i < DIS)
	{
		ft_pixel_put(m, i, 50, WHITE);
		ft_pixel_put(m, i, (HEIGHT - 50) / 3 + 50, WHITE);
		ft_pixel_put(m, i, (HEIGHT - 50) / 2 + 50, WHITE);
		ft_pixel_put(m, i, 2 * (HEIGHT - 50) / 3 + 50, WHITE);
		ft_pixel_put(m, i, 5 * (HEIGHT - 50) / 6 + 50, WHITE);
	}
	ft_return_button(m);
	mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, m.ptr, 0, 0);
	ft_legend_mandelbrot(p->mlx->mlx_ptr, p->mlx->win_ptr);
	p->param = 2;
}
