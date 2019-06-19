/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cplx_exp.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 07:37:42 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:37:52 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_cplx_exp(t_cplx z)
{
	t_cplx r;

	r.rl = exp(z.rl) * cos(z.im);
	r.im = exp(z.rl) * sin(z.im);
	return (r);
}
