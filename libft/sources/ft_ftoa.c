/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ftoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 15:15:43 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/17 15:16:04 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_ftoa(double nb, int p)
{
	char	*s;
	char	*t;

	p = (p < 0 ? 0 : p);
	if (!(s = ft_strnew(ft_intlen(nb) + (p ? p + 1 : p))))
		ft_error("Malloc error");
	if (nb < 0)
	{
		ft_strcat(s, "-");
		nb = -nb;
	}
	nb += 5.0 / ft_pow(10, p + 1);
	t = ft_itoa(nb);
	ft_strcat(s, t);
	ft_strdel(&t);
	if (p)
		ft_strcat(s, ".");
	while (p--)
	{
		nb -= (int)nb;
		t = ft_itoa((nb *= 10));
		ft_strcat(s, t);
		ft_strdel(&t);
	}
	return (s);
}
