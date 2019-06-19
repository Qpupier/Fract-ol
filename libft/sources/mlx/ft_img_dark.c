/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_img_dark.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 15:00:17 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 19:36:04 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_img_dark(t_mlx_img img)
{
	int	i;
	int	j;

	j = -1;
	while (++j < img.height)
	{
		i = -1;
		while (++i < img.width)
			ft_pixel_put(img, i, j, BLACK);
	}
}
