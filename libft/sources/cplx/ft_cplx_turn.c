/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cplx_turn.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 14:58:54 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 10:49:35 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_cplx_turn(t_cplx a, t_cplx o, double angle)
{
	return (ft_cplx_add(ft_cplx_mult(ft_cplx_remove(a, o), 	\
			ft_make_cplx(cos(angle), sin(angle))), o));
}
