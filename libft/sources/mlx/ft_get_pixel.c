/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_pixel.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 14:59:42 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 10:52:23 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_rgb	ft_get_pixel(t_mlx_img img, int x, int y)
{
	t_rgb	rgb;
	int		t;

	if (x < 0 || y < 0 || x >= img.width || y >= img.height)
		return ((t_rgb){0, 0, 0, 0});
	t = y * img.s_l + x * 4;
	rgb.b = img.img[t] + (img.img[t] < 0 ? 256 : 0);
	rgb.g = img.img[t + 1] + (img.img[t + 1] < 0 ? 256 : 0);
	rgb.r = img.img[t + 2] + (img.img[t + 2] < 0 ? 256 : 0);
	rgb.a = img.img[t + 3] + (img.img[t + 3] < 0 ? 256 : 0);
	return (rgb);
}
