/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cplx_sinh.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 07:36:10 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:36:20 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_cplx_sinh(t_cplx z)
{
	t_cplx r;

	r.rl = cos(z.im) * (exp(z.rl) - exp(-z.rl)) / 2;
	r.im = sin(z.im) * (exp(z.rl) + exp(-z.rl)) / 2;
	return (r);
}
