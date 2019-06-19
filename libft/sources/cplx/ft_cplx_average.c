/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cplx_average.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 15:09:33 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 10:45:59 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_cplx_average(t_cplx a, t_cplx z, double b)
{
	return (ft_make_cplx(a.rl + b * (z.rl - a.rl), a.im + b * (z.im - a.im)));
}
