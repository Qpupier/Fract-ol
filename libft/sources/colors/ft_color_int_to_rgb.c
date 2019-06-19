/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_color_int_to_rgb.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 15:11:21 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 10:42:03 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_rgb	ft_color_int_to_rgb(int nb)
{
	t_rgb	rgb;

	rgb.r = nb / 65536;
	rgb.g = nb / 256 % 256;
	rgb.b = nb % 256;
	rgb.a = 0;
	return (rgb);
}
