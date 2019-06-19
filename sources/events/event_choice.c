/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_choice.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 23:13:14 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 22:53:50 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_choice_1(t_param *p, int x, int y)
{
	if (y < (HEIGHT - 50) / 2 + 50)
		p->fractal = 0;
	else if (x < DIS / 2 && y < HEIGHT - (HEIGHT - 50) / 4)
		p->fractal = 1;
	else if (y < HEIGHT - (HEIGHT - 50) / 4)
		p->fractal = 2;
	else if (x < DIS / 2)
		p->fractal = 3;
	else
		p->fractal = 4;
}

void	ft_choice_2(t_param *p, int x, int y)
{
	if (y < (HEIGHT - 50) / 3 + 50)
		p->fractal = 5;
	else if (x < DIS / 2 && y < (HEIGHT - 50) / 2 + 50)
		p->fractal = 6;
	else if (y < (HEIGHT - 50) / 2 + 50)
		p->fractal = 7;
	else if (x < DIS / 2 && y < 2 * (HEIGHT - 50) / 3 + 50)
		p->fractal = 8;
	else if (y < 2 * (HEIGHT - 50) / 3 + 50)
		p->fractal = 9;
	else if (x < DIS / 2 && y < 5 * (HEIGHT - 50) / 6 + 50)
		p->fractal = 10;
	else if (y < 5 * (HEIGHT - 50) / 6 + 50)
		p->fractal = 11;
	else if (x < DIS / 2)
		p->fractal = 12;
	else
		p->fractal = 13;
}

void	ft_choice_3(t_param *p, int y)
{
	if (y < (HEIGHT - 50) / 2 + 50)
		p->fractal = 16;
	else
		p->fractal = 17;
}

void	ft_choice_4(t_param *p, int y)
{
	if (y < (HEIGHT - 50) / 2 + 50)
		p->fractal = 18;
	else
		p->fractal = 19;
}

void	ft_choice_5(t_param *p, int y)
{
	if (y < (HEIGHT - 50) / 2 + 50)
		p->fractal = 21;
	else
		p->fractal = 22;
}
