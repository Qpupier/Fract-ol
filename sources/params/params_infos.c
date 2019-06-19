/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   params_infos.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 12:48:14 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 22:53:50 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	ft_params_tmp2(t_param *p, int *n)
{
	char	*tmp;

	tmp = ft_ftoa(p->pos_left[p->fractal].rl + p->zoom[p->fractal], 3);
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 				\
			DIS + 10 * ft_strlen("X coordinates : -X.XXX  ") + 10, 	\
			*n, WHITE_H, ft_strcmp(tmp, "-0.000") ? tmp : "0.000");
	free(tmp);
	ft_param_line_float(p, n, "X coordinates : ", 					\
			p->pos_left[p->fractal].rl);
	tmp = ft_ftoa(p->pos_left[p->fractal].im + p->zoom[p->fractal], 3);
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 				\
			DIS + 10 * ft_strlen("X coordinates : -X.XXX  ") + 10, 	\
			*n, WHITE_H, ft_strcmp(tmp, "-0.000") ? tmp : "0.000");
	free(tmp);
	ft_param_line_float(p, n, "Y coordinates : ", 					\
			p->pos_left[p->fractal].im);
}

static void	ft_params_tmp1(t_param *p, int *n)
{
	char	*tmp;

	tmp = ft_itoa((p->pos_left[p->fractal].rl + 					\
			p->zoom[p->fractal] + 2) * WIDTH * 0.25);
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 				\
			DIS + 10 * ft_strlen("X coordinates : -XXX  ") + 10, 	\
			*n, WHITE_H, tmp);
	free(tmp);
	ft_param_line(p->mlx, n, "X coordinates : ", 					\
			(p->pos_left[p->fractal].rl + 2) * WIDTH * 0.25);
	tmp = ft_itoa((p->pos_left[p->fractal].im + 					\
			p->zoom[p->fractal] + 2) * WIDTH * 0.25);
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 				\
			DIS + 10 * ft_strlen("X coordinates : -XXX  ") + 10, 	\
			*n, WHITE_H, tmp);
	free(tmp);
	ft_param_line(p->mlx, n, "Y coordinates : ", 					\
			(p->pos_left[p->fractal].im + 2) * WIDTH * 0.25);
}

static void	ft_params2_tmp(t_param *p, int *n)
{
	*n += 10;
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10 + 5 * 	\
			ft_strlen(" 2 branches ") - 5 * ft_strlen("2 branches"), 	\
			*n, p->tree_nb == 2 ? BLACK_H : WHITE_H, "2 branches");
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10 + 15 * 	\
			ft_strlen(" 3 branches ") - 5 * ft_strlen("3 branches"), 	\
			*n, p->tree_nb == 3 ? BLACK_H : WHITE_H, "3 branches");
	*n += 40;
	ft_param_line(p->mlx, n, "Left branch degree : ", p->tree_degree[0]);
	if (p->tree_nb == 3)
		ft_param_line(p->mlx, n, "Middle branch degree : ", 			\
				p->tree_degree[1]);
	ft_param_line(p->mlx, n, "Right branch degree : ", p->tree_degree[2]);
	ft_param_line(p->mlx, n, "Size primary branch: ", p->tree_size);
	ft_param_line_float(p, n, "Size branch ratio: ", p->tree_ratio);
}

static void	ft_params2(t_param *p, int *n)
{
	if (p->fractal == 23)
	{
		*n += 10;
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10 + 5 * 	\
				ft_strlen("  Inverted  ") - 5 * ft_strlen("Koch"), *n, 		\
				p->koch ? WHITE_H : BLACK_H, "Koch");
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10 + 15 * 	\
				ft_strlen("  Inverted  ") - 5 * ft_strlen("Inverted"), *n, 	\
				p->koch ? BLACK_H : WHITE_H, "Inverted");
		*n += 40;
	}
	else if (p->fractal == 24)
		ft_params2_tmp(p, n);
}

void		ft_params1(t_param *p, int n)
{
	ft_param_line(p->mlx, &n, "Number of iterations : ", 					\
			p->it[p->fractal] * (p->fractal == 16 || p->fractal == 17 		\
			? 100 : 1) + p->it_tmp[p->fractal]);
	if (!((p->fractal >= 14 && p->fractal <= 17) || p->fractal >= 21))
	{
		ft_param_line(p->mlx, &n, "Zoom : ", p->dis_zoom[p->fractal]);
		p->fractal == 20 ? ft_params_tmp1(p, &n) : ft_params_tmp2(p, &n);
	}
	if (p->fractal < 11)
		ft_param_line(p->mlx, &n, "Fractal degree : ", p->deg[p->fractal]);
	if (p->fractal == 7 || p->fractal == 9 || p->fractal == 11)
		ft_param_line(p->mlx, &n, "Mandelbrot degree : ", 					\
				p->deg_mandelbrot[p->fractal / 2 - 3]);
	else if (p->fractal == 18 || p->fractal == 19)
		ft_param_line(p->mlx, &n, "Newton degree : ", 						\
				p->deg_newton[p->fractal - 18]);
	else if (p->fractal == 20)
	{
		ft_param_line(p->mlx, &n, "Pythagore tree size : ", 				\
				400 / p->zoom[p->fractal]);
		ft_param_line(p->mlx, &n, "Pythagore tree angle : ", p->pyth_angle);
	}
	else
		ft_params2(p, &n);
	ft_params3(p, n);
}
