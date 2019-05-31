/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_hexa.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 19:26:40 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:18:04 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi_hexa(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = str[i] == '-' ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || 	\
	(str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F')))
		if (str[i] >= '0' && str[i] <= '9')
			result = 16 * result + str[i++] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			result = 16 * result + str[i++] - 'a' + 10;
		else
			result = 16 * result + str[i++] - 'A' + 10;
	if (result < 0 && sign < 0)
		return (0);
	if (result < 0)
		return (-1);
	return (result * sign);
}
