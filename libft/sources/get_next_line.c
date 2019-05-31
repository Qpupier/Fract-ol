/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 13:23:07 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:18:04 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_gnl	*find_file(t_gnl **list, int fd)
{
	t_gnl		*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	tmp->save = ft_strnew(BUFF_SIZE);
	tmp->fd = fd;
	tmp->next = NULL;
	tmp->next = *list;
	*list = tmp;
	return (tmp);
}

static void		ft_del_after_occ(char *s, int c)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			s[i] = 0;
}

static int		process_file(char *s, char **result)
{
	char	*tmp_dup_s;
	char	*tmp_result;

	if (ft_strrchr(s, '\n'))
	{
		tmp_dup_s = ft_strdup(s);
		s = ft_strcpy(s, ft_strchr(s, '\n') + 1);
		ft_del_after_occ(tmp_dup_s, 10);
		tmp_result = *result;
		*result = ft_strjoin(tmp_result, tmp_dup_s);
		free(tmp_dup_s);
		free(tmp_result);
		return (1);
	}
	else
	{
		tmp_result = *result;
		*result = ft_strjoin(tmp_result, s);
		free(tmp_result);
		ft_bzero(s, BUFF_SIZE);
		return (0);
	}
}

int				get_next_line(const int fd, char **line)
{
	int				rd;
	static t_gnl	*lst;
	t_gnl			*file;

	file = find_file(&lst, fd);
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!file->save)
		file->save = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(0);
	if (*file->save)
		if (process_file(file->save, line))
			return (1);
	ft_bzero(file->save, BUFF_SIZE);
	while ((rd = read(fd, file->save, BUFF_SIZE)))
	{
		if (rd < 0)
			return (-1);
		if (process_file(file->save, line))
			return (1);
	}
	return (**line ? 1 : 0);
}
