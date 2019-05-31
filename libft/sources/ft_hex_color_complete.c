/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hex_color_complete.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 16:09:18 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 11:58:49 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_hex_color_complete(char *c)
{
	int		i;
	char	*color;
	char	tmp;

	if (!c)
		return (ft_strdup("0xFFFFFF00"));
	if (!(color = (char*)malloc(sizeof(*color) * 11)))
		ft_error("Malloc error");
	i = -1;
	while (++i < 10 && c[i])
		color[i] = c[i];
	tmp = c[--i];
	while (++i < 10)
		color[i] = i < 8 ? tmp : '0';
	color[i] = '\0';
	return (color);
}
