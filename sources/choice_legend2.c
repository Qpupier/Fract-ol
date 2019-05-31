/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   choice_legend2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/16 10:39:35 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/22 13:03:15 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_return_button(t_mlx_img img)
{
	ft_line(img, ft_make_cplx(14, 25), ft_make_cplx(25, 14), WHITE);
	ft_line(img, ft_make_cplx(15, 25), ft_make_cplx(25, 15), WHITE);
	ft_line(img, ft_make_cplx(15, 25), ft_make_cplx(25, 35), WHITE);
	ft_line(img, ft_make_cplx(14, 25), ft_make_cplx(25, 36), WHITE);
}

void	ft_legend_fern(void *mlx_ptr, void *win_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 							\
			DIS / 2 - 5 * ft_strlen("Fractales de Fern"), 15, 	\
			WHITE_H, "Fractales de Fern");
	mlx_string_put(mlx_ptr, win_ptr, 5, 50 + 5, WHITE_H, "FERN 1");
	mlx_string_put(mlx_ptr, win_ptr, 							\
			5, 50 + 5 + (HEIGHT - 50) / 2, WHITE_H, "FERN 2");
}

void	ft_choice_fern(t_param *p)
{
	int	i;

	i = -1;
	while (++i < HEIGHT)
		ft_pixel_put(p->mlx->param_fern[0], DIS - 1, i, WHITE);
	i = -1;
	while (++i < DIS)
	{
		ft_pixel_put(p->mlx->param_fern[0], i, 50, WHITE);
		ft_pixel_put(p->mlx->param_fern[0], i, (HEIGHT - 50) / 2 + 50, WHITE);
	}
	ft_return_button(p->mlx->param_fern[0]);
	i = 100;
	while (i--)
		mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, 	\
				p->mlx->param_fern[i].ptr, 0, 0);
	ft_legend_fern(p->mlx->mlx_ptr, p->mlx->win_ptr);
	p->param = 3;
}

void	ft_legend_newton(void *mlx_ptr, void *win_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 								\
			DIS / 2 - 5 * ft_strlen("Fractales de Newton"), 15, 	\
			WHITE_H, "Fractales de Newton");
	mlx_string_put(mlx_ptr, win_ptr, 5, 50 + 5, WHITE_H, "NEWTON");
	mlx_string_put(mlx_ptr, win_ptr, 								\
			5, 50 + 5 + (HEIGHT - 50) / 2, WHITE_H, "HALLEY");
}

void	ft_choice_newton(t_param *p)
{
	int	i;

	i = -1;
	while (++i < HEIGHT)
		ft_pixel_put(p->mlx->param_newton, DIS - 1, i, WHITE);
	i = -1;
	while (++i < WIDTH + DIS)
		ft_pixel_put(p->mlx->param_newton, i, HEIGHT, WHITE);
	i = -1;
	while (++i < DIS)
	{
		ft_pixel_put(p->mlx->param_newton, i, 50, WHITE);
		ft_pixel_put(p->mlx->param_newton, i, (HEIGHT - 50) / 2 + 50, WHITE);
	}
	ft_return_button(p->mlx->param_newton);
	mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, 	\
			p->mlx->param_newton.ptr, 0, 0);
	ft_legend_newton(p->mlx->mlx_ptr, p->mlx->win_ptr);
	p->param = 4;
}
