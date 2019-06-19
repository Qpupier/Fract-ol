/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   params_down_squares_help.c                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 23:01:20 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 19:33:32 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	ft_params_help1(t_param *p, int *n)
{
	if (p->fractal == 7 || p->fractal == 9 || p->fractal == 11)
		ft_param_line_help(p->mlx, n, "Mandelbrot degree : - | + ( _ | = )");
	else if (p->fractal == 18 || p->fractal == 19)
		ft_param_line_help(p->mlx, n, "Newton degree : < | >");
	else if (p->fractal == 20)
	{
		*n += 30;
		ft_param_line_help(p->mlx, n, "Pythagore tree angle : < | >");
	}
	else if (p->fractal == 24)
	{
		*n += 50;
		ft_param_line_help(p->mlx, n, "Left branch degree : 4 | 1");
		if (p->tree_nb == 3)
			ft_param_line_help(p->mlx, n, "Middle branch degree : 5 | 2");
		ft_param_line_help(p->mlx, n, "Right branch degree : 6 | 3");
		ft_param_line_help(p->mlx, n, "Size primary branch : - | + ( _ | = )");
		ft_param_line_help(p->mlx, n, "Size branch ratio : < | >");
	}
}

static void	ft_params_help2(t_param *p, int n)
{
	if (p->fractal < 5)
	{
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 2 * DIS + 10, n, 	\
				WHITE_H, "Julia variations : Space bar");
		n += 30;
	}
	if (p->fractal < 14)
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 2 * DIS + 10, 		\
				HEIGHT + PARAM - 30, WHITE_H, 								\
				"Colors : Left, middle and right mouse click");
	else if (p->fractal == 21 || p->fractal == 24)
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 2 * DIS + 10, 		\
				HEIGHT + PARAM - 30, WHITE_H, 								\
				"Colors : Left and right mouse click");
}

void		ft_params_help(t_param *p)
{
	int	n;

	if (p->fractal >= 14 && p->fractal <= 17)
		return ;
	n = HEIGHT + 15;
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 2 * DIS + 10, n, 		\
			GREY_H, "Help");
	n += 45;
	ft_param_line_help(p->mlx, &n, "Iterations : - | +");
	if (p->fractal < 21)
	{
		ft_param_line_help(p->mlx, &n, p->fractal == 20 					\
				? "Zoom : Mouse scroll" : "Zoom : Mouse scroll & right click");
		ft_param_line_help(p->mlx, &n, 										\
				"Coordinates : Arrows & Mouse (Left click)");
		n += 30;
	}
	if (p->fractal < 11)
		ft_param_line_help(p->mlx, &n, "Fractal degree : < | >");
	ft_params_help1(p, &n);
	ft_params_help2(p, n);
}

static int	ft_colors_squares_tmp(t_param *p, int i)
{
	ft_line_straight_horiz(p->mlx->param2, 					\
			ft_make_cplx(DIS + 79 + i * 50, PARAM - 31), 	\
			ft_make_cplx(DIS + 101 + i * 50, PARAM - 31), WHITE);
	ft_line_straight_horiz(p->mlx->param2, 					\
			ft_make_cplx(DIS + 79 + i * 50, PARAM - 10), 	\
			ft_make_cplx(DIS + 101 + i * 50, PARAM - 10), WHITE);
	ft_line_straight_vert(p->mlx->param2, 					\
			ft_make_cplx(DIS + 79 + i * 50, PARAM - 31), 	\
			ft_make_cplx(DIS + 79 + i * 50, PARAM - 10), WHITE);
	ft_line_straight_vert(p->mlx->param2, 					\
			ft_make_cplx(DIS + 100 + i * 50, PARAM - 31), 	\
			ft_make_cplx(DIS + 100 + i * 50, PARAM - 10), WHITE);
	return (PARAM - 31);
}

void		ft_colors_squares(t_param *p)
{
	int	i;
	int	j;

	i = 0;
	if (p->fractal < 14)
		while (++i <= NB_COLORS)
		{
			j = ft_colors_squares_tmp(p, i);
			while (++j < PARAM - 10)
				ft_line_straight_horiz(p->mlx->param2, 			\
						ft_make_cplx(DIS + 80 + i * 50, j), 	\
						ft_make_cplx(DIS + 100 + i * 50, j), 	\
						p->colors[p->fractal][i]);
		}
	else if (p->fractal == 21 || p->fractal == 24)
		while (++i <= 2)
		{
			j = ft_colors_squares_tmp(p, i);
			while (++j < PARAM - 10)
				ft_line_straight_horiz(p->mlx->param2, 			\
						ft_make_cplx(DIS + 80 + i * 50, j), 	\
						ft_make_cplx(DIS + 100 + i * 50, j), 	\
						p->fractal == 21 						\
						? p->colors_carpet[i - 1] : p->colors_tree[i - 1]);
		}
}
