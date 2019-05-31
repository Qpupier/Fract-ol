/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cplx_cosh.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 07:35:27 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:35:49 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_cplx_cosh(t_cplx z)
{
	t_cplx r;

	r.rl = cos(z.im) * (exp(z.rl) + exp(-z.rl)) / 2;
	r.im = sin(z.im) * (exp(z.rl) - exp(-z.rl)) / 2;
	return (r);
}
