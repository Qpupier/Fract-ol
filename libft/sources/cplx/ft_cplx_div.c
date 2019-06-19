/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cplx_div.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 07:36:37 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:36:46 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_cplx_div(t_cplx a, t_cplx b)
{
	t_cplx r;

	r.rl = (a.rl * b.rl + a.im * b.im) / (ft_sq(b.rl) + ft_sq(b.im));
	r.im = (a.im * b.rl - a.rl * b.im) / (ft_sq(b.rl) + ft_sq(b.im));
	return (r);
}
