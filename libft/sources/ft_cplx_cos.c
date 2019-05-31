/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cplx_cos.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 07:34:28 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:34:36 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_cplx_cos(t_cplx z)
{
	t_cplx r;

	r.rl = cos(z.rl) * (exp(z.im) + exp(-z.im)) / 2;
	r.im = -sin(z.rl) * (exp(z.im) - exp(-z.im)) / 2;
	return (r);
}
