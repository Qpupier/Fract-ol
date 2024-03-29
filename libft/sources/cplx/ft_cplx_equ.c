/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cplx_equ.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 15:20:35 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 10:47:41 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_cplx_equ(t_cplx a, t_cplx b)
{
	if (a.rl == b.rl && a.im == b.im)
		return (1);
	return (0);
}
