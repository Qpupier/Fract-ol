/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 20:50:33 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:18:04 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int tmp;

	tmp = 0;
	while (*needle && *haystack)
	{
		haystack -= tmp;
		needle -= tmp;
		while (*haystack && *haystack != *needle)
			haystack++;
		if (!*haystack)
			return (NULL);
		tmp = 0;
		while (*haystack && *needle && *haystack++ == *needle)
		{
			tmp++;
			needle++;
		}
	}
	if (!*needle)
		return ((char*)haystack - tmp);
	return (NULL);
}
