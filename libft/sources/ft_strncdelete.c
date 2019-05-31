/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncdelete.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 16:59:14 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:18:04 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strncdelete(char *str, char letter, char replace, int count)
{
	int	i;

	i = -1;
	while (str[++i] && count)
		if (str[i] == letter)
		{
			str[i] = replace;
			count--;
		}
}
