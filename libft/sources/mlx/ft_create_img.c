/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_img.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 14:57:48 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 10:49:53 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_create_img(void *ptr, t_mlx_img *img, int w, int h)
{
	img->ptr = mlx_new_image(ptr, w, h);
	img->img = mlx_get_data_addr(img->ptr, &img->bpp, &img->s_l, &img->endian);
	img->width = w;
	img->height = h;
}
