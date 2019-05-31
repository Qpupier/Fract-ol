/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit_lst.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/04 13:56:55 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:18:04 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_strsplit_lst(char const *s, char c)
{
	char	**new;
	t_list	*str;
	t_list	*tmp;
	int		i;

	new = ft_strsplit(s, c);
	if (!new)
		return (NULL);
	str = ft_lstnew(new[0], ft_strlen(new[0]));
	tmp = str;
	i = 0;
	while (++i < ft_count_words((char*)s, c))
	{
		tmp->next = ft_lstnew(new[i], ft_strlen(new[i]));
		tmp = tmp->next;
		tmp->content = new[i];
		tmp->content_size = ft_strlen(new[i]);
	}
	tmp = NULL;
	return (str);
}
