/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cplx_mult.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 07:31:52 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:32:03 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_cplx_mult(t_cplx a, t_cplx b)
{
	t_cplx r;

	r.rl = a.rl * b.rl - a.im * b.im;
	r.im = a.rl * b.im + a.im * b.rl;
	return (r);
}
