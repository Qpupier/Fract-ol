/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fern.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/07 19:10:57 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/20 15:55:13 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_fern2_after(t_param *p)
{
	p->fern[1][2].mat_2_2[0] = 0.035;
	p->fern[1][2].mat_2_2[1] = -0.2;
	p->fern[1][2].mat_2_2[2] = 0.16;
	p->fern[1][2].mat_2_2[3] = 0.04;
	p->fern[1][2].mat_1_2[0] = -0.09;
	p->fern[1][2].mat_1_2[1] = 0.02;
	p->fern[1][2].p = 7 + p->fern[1][1].p;
	p->fern[1][2].max = -1;
	p->fern[1][3].mat_2_2[0] = -0.04;
	p->fern[1][3].mat_2_2[1] = 0.2;
	p->fern[1][3].mat_2_2[2] = 0.16;
	p->fern[1][3].mat_2_2[3] = 0.04;
	p->fern[1][3].mat_1_2[0] = 0.083;
	p->fern[1][3].mat_1_2[1] = 0.12;
	p->fern[1][3].p = 7 + p->fern[1][2].p;
	p->fern[1][3].max = 8;
}

void	ft_init_fern2(t_param *p)
{
	p->fern[1][0].mat_2_2[0] = 0;
	p->fern[1][0].mat_2_2[1] = 0;
	p->fern[1][0].mat_2_2[2] = 0;
	p->fern[1][0].mat_2_2[3] = 0.25;
	p->fern[1][0].mat_1_2[0] = 0;
	p->fern[1][0].mat_1_2[1] = -0.4;
	p->fern[1][0].p = 2;
	p->fern[1][0].max = -2;
	p->fern[1][1].mat_2_2[0] = 0.95;
	p->fern[1][1].mat_2_2[1] = 0.005;
	p->fern[1][1].mat_2_2[2] = -0.005;
	p->fern[1][1].mat_2_2[3] = 0.93;
	p->fern[1][1].mat_1_2[0] = -0.002;
	p->fern[1][1].mat_1_2[1] = 0.5;
	p->fern[1][1].p = 84 + p->fern[1][0].p;
	p->fern[1][1].max = 2;
	ft_init_fern2_after(p);
}

void	ft_init_fern_after(t_param *p)
{
	p->fern[0][2].mat_2_2[0] = 0.2;
	p->fern[0][2].mat_2_2[1] = -0.26;
	p->fern[0][2].mat_2_2[2] = 0.23;
	p->fern[0][2].mat_2_2[3] = 0.22;
	p->fern[0][2].mat_1_2[0] = 0;
	p->fern[0][2].mat_1_2[1] = 1.6;
	p->fern[0][2].p = 7 + p->fern[0][1].p;
	p->fern[0][2].max = 0;
	p->fern[0][3].mat_2_2[0] = -0.15;
	p->fern[0][3].mat_2_2[1] = 0.28;
	p->fern[0][3].mat_2_2[2] = 0.26;
	p->fern[0][3].mat_2_2[3] = 0.24;
	p->fern[0][3].mat_1_2[0] = 0;
	p->fern[0][3].mat_1_2[1] = 0.44;
	p->fern[0][3].p = 7 + p->fern[0][2].p;
	p->fern[0][3].max = 10;
	ft_init_fern2(p);
}

void	ft_init_fern_values(t_param *p)
{
	p->fern[0][0].mat_2_2[0] = 0;
	p->fern[0][0].mat_2_2[1] = 0;
	p->fern[0][0].mat_2_2[2] = 0;
	p->fern[0][0].mat_2_2[3] = 0.16;
	p->fern[0][0].mat_1_2[0] = 0;
	p->fern[0][0].mat_1_2[1] = 0;
	p->fern[0][0].p = 1;
	p->fern[0][0].max = -3;
	p->fern[0][1].mat_2_2[0] = 0.85;
	p->fern[0][1].mat_2_2[1] = 0.04;
	p->fern[0][1].mat_2_2[2] = -0.04;
	p->fern[0][1].mat_2_2[3] = 0.85;
	p->fern[0][1].mat_1_2[0] = 0;
	p->fern[0][1].mat_1_2[1] = 1.6;
	p->fern[0][1].p = 85 + p->fern[0][0].p;
	p->fern[0][1].max = 3;
	ft_init_fern_after(p);
}

void	ft_fern(t_mlx_img img, t_fern fern[2][4], int n, int it)
{
	int		nb;
	int		i;
	int		j;
	t_cplx	z;

	z = ft_make_cplx(0, 0);
	i = -1;
	while (++i < it)
	{
		nb = rand() % 100;
		j = 0;
		while (nb >= fern[n][j].p)
			j++;
		nb = j;
		z = ft_make_cplx(fern[n][nb].mat_2_2[0] * z.rl + 					\
			fern[n][nb].mat_2_2[1] * z.im + fern[n][nb].mat_1_2[0], 		\
			fern[n][nb].mat_2_2[2] * z.rl + 								\
			fern[n][nb].mat_2_2[3] * z.im + fern[n][nb].mat_1_2[1]);
		ft_pixel_put(img, 													\
		(z.rl - fern[n][0].max) * MIN / (fern[n][1].max - fern[n][0].max), 	\
		(z.im - fern[n][2].max) * MIN / (fern[n][3].max - fern[n][2].max), 	\
			ft_color_average(BLACK, 										\
			ft_color_hex_to_rgb("0x00FF00FA"), (double)i / it));
	}
}
