/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_color_average.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 16:12:24 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 11:57:46 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_rgb	ft_color_average(t_rgb c1, t_rgb c2, double p)
{
	t_rgb	rgb;

	rgb.r = c1.r + (c2.r - c1.r) * p;
	rgb.g = c1.g + (c2.g - c1.g) * p;
	rgb.b = c1.b + (c2.b - c1.b) * p;
	rgb.a = c1.a + (c2.a - c1.a) * p;
	return (rgb);
}
