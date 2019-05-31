/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_make_cplx.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 07:38:17 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:38:29 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_make_cplx(double rl, double im)
{
	t_cplx r;

	r.rl = rl;
	r.im = im;
	return (r);
}
