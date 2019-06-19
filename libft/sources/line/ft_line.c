/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_line.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 15:08:15 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 10:56:35 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_line(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	int	dx;
	int	dy;

	if (ft_line_straight(img, a, z, color))
		return ;
	dx = ft_abs(z.rl - a.rl);
	dy = ft_abs(z.im - a.im);
	dx >= dy ? ft_line_horiz(img, a, z, color) : ft_line_vert(img, a, z, color);
}
