/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_line_straight_horiz.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 15:06:42 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 10:57:05 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_line_straight_horiz(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	int	x1;

	x1 = a.rl;
	while (ft_abs(z.rl - x1) >= 1)
	{
		ft_pixel_put(img, x1, a.im, color);
		x1 < z.rl ? x1++ : x1--;
	}
	return (1);
}
