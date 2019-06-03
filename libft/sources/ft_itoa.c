/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 18:05:31 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/31 20:53:51 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(long int n)
{
	char	*s;
	int		size;

	if (!n)
		return (ft_strdup("0"));
	size = ft_intlen(n);
	if (!(s = ft_strnew(size)))
		ft_error("Malloc error");
	while (size--)
	{
		s[size] = ft_digit_abs(n % 10) + '0';
		n /= 10;
	}
	if (*s == '0')
		*s = '-';
	return (s);
}
