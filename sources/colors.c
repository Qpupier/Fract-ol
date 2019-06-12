/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colors.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 10:39:31 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 11:33:12 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_colors(t_param *p)
{
	int	i;
	int	j;
	double c1;
	double c2;

	i = 32 - 2;
	while (++i <= 32 + 256)
	{
		ft_pixel_put(p->mlx->param2, i, 31, WHITE);
		ft_pixel_put(p->mlx->param2, i, 32 + 256, WHITE);
		ft_pixel_put(p->mlx->param2, 31, i, WHITE);
		ft_pixel_put(p->mlx->param2, 32 + 256, i, WHITE);
	}
	c1 = 0;
	j = 32 - 1;
	while (++j < 32 + 256)
	{
		c2 = 0;
		i = 32 - 1;
		while (++i < 32 + 256)
		{
			ft_pixel_put(p->mlx->param2, i, j, 							\
			ft_color_average(ft_color_average(RED, BLUE, c2 / 256), 	\
			ft_color_average(GREEN, WHITE, c2 / 256), c1 / 256));
			c2++;
		}
		c1++;
	}
}
