/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cplx_sin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 07:34:56 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:35:09 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_cplx_sin(t_cplx z)
{
	t_cplx r;

	r.rl = sin(z.rl) * (exp(z.im) + exp(-z.im)) / 2;
	r.im = cos(z.rl) * (exp(z.im) - exp(-z.im)) / 2;
	return (r);
}
