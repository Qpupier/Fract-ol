/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   choice_legend3.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/17 09:25:26 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/17 18:18:22 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_legend_sierpinsky(void *mlx_ptr, void *win_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 									\
			DIS / 2 - 5 * ft_strlen("Fractales de Sierpinsky"), 15, 	\
			WHITE_H, "Fractales de Sierpinsky");
	mlx_string_put(mlx_ptr, win_ptr, 5, 50 + 5, WHITE_H, "CARPET");
	mlx_string_put(mlx_ptr, win_ptr, 									\
			5, 50 + 5 + (HEIGHT - 50) / 2, WHITE_H, "TRIANGLE");
}

void	ft_choice_sierpinsky(t_param *p)
{
	int	i;

	i = -1;
	while (++i < HEIGHT)
		ft_pixel_put(p->mlx->param_sierpinsky, DIS - 1, i, WHITE);
	i = -1;
	while (++i < DIS)
	{
		ft_pixel_put(p->mlx->param_sierpinsky, i, 50, WHITE);
		ft_pixel_put(p->mlx->param_sierpinsky, i, 		\
				(HEIGHT - 50) / 2 + 50, WHITE);
	}
	ft_return_button(p->mlx->param_sierpinsky);
	mlx_put_image_to_window(p->mlx, p->mlx->win_ptr, 	\
			p->mlx->param_sierpinsky.ptr, 0, 0);
	ft_legend_sierpinsky(p->mlx->mlx_ptr, p->mlx->win_ptr);
	p->param = 5;
}
