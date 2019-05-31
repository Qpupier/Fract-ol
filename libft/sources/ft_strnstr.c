/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 14:42:01 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:18:04 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	if (!*needle)
		return ((char*)haystack);
	i = 0;
	j = -1;
	while (haystack[++j] && len)
	{
		len += i;
		i = 0;
		while (len-- && haystack[j + i] && needle[i] && 	\
				haystack[j + i] == needle[i])
			i++;
		if (!needle[i])
			return ((char*)haystack + j);
		if (!haystack[j + i])
			return (NULL);
	}
	return (NULL);
}
