/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_color_rgb_random.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 15:01:45 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 10:42:21 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_rgb	ft_color_rgb_random(void)
{
	t_rgb	color;

	color.r = rand() % 255;
	color.g = rand() % 255;
	color.b = rand() % 255;
	color.a = 0;
	return (color);
}
