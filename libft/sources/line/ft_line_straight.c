/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_line_straight.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 15:07:18 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 10:57:41 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_line_straight(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	if (a.rl == z.rl)
		return (ft_line_straight_vert(img, a, z, color));
	else if (a.im == z.im)
		return (ft_line_straight_horiz(img, a, z, color));
	return (0);
}
