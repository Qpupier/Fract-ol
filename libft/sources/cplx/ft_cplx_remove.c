/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cplx_remove.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 07:33:31 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:33:40 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_cplx_remove(t_cplx a, t_cplx b)
{
	t_cplx r;

	r.rl = a.rl - b.rl;
	r.im = a.im - b.im;
	return (r);
}
