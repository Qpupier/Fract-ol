/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pixel_put.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 14:56:08 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 11:34:16 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_pixel_put(t_mlx_img img, int x, int y, t_rgb color)
{
	int t;

	if (x < 0 || y < 0 || x >= img.width || y >= img.height)
		return ;
	t = y * img.s_l + x * 4;
	img.img[t] = (char)(color.b);
	img.img[t + 1] = (char)(color.g);
	img.img[t + 2] = (char)(color.r);
	img.img[t + 3] = (char)(color.a);
}
