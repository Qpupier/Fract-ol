/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   params_down_left.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/14 22:59:29 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 22:53:50 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_param_line(t_mlx *mlx, int *n, char *str, long int param)
{
	char	*degree;

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, DIS + 10, *n, WHITE_H, str);
	degree = ft_itoa(param);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 	\
			DIS + 10 + 10 * ft_strlen(str), *n, WHITE_H, degree);
	free(degree);
	*n += 30;
}

void	ft_param_line_help(t_mlx *mlx, int *n, char *str)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 	\
			2 * DIS + 10, *n, WHITE_H, str);
	*n += 30;
}

void	ft_param_line_float(t_param *p, int *n, char *str, double param)
{
	char	*tmp;

	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 		\
			DIS + 10, *n, WHITE_H, str);
	tmp = ft_ftoa(param, p->fractal == 24 ? 1 : 3);
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 		\
			DIS + 10 + 10 * ft_strlen(str), *n, WHITE_H, 	\
			ft_strcmp(tmp, "-0.000") ? tmp : "0.000");
	free(tmp);
	*n += 30;
}

void	ft_param_button(t_param *p, int n)
{
	int	i;
	int	j;
	int	size;

	ft_img_dark(p->mlx->param2);
	n += 75;
	size = 10 * ft_strlen("  Inverted  ");
	i = -1;
	while (++i < 2 * size)
	{
		ft_pixel_put(p->mlx->param2, i + DIS + 10, n, WHITE);
		ft_pixel_put(p->mlx->param2, i + DIS + 10, n + 40, WHITE);
		j = n - 1;
		if (((p->fractal == 23 && p->koch) 					\
				|| (p->fractal == 24 && p->tree_nb == 3) 	\
				? i >= size : i <= size) || i == 0 || i == 2 * size - 1)
			while (++j < n + 40)
				ft_pixel_put(p->mlx->param2, i + DIS + 10, j, WHITE);
	}
}

void	ft_params(t_param *p)
{
	int		i;
	int		n;

	p->fractal >= 23 ? ft_param_button(p, 15) : ft_img_dark(p->mlx->param2);
	i = -1;
	while (++i < DIS + WIDTH)
		ft_pixel_put(p->mlx->param2, i, 0, WHITE);
	i = -1;
	while (++i < PARAM)
		ft_pixel_put(p->mlx->param2, DIS - 1, i, WHITE);
	if (p->fractal < 14 || p->fractal == 21 || p->fractal == 24)
		ft_colors(p);
	ft_colors_squares(p);
	mlx_put_image_to_window(p->mlx->mlx_ptr, p->mlx->win_ptr, 	\
			p->mlx->param2.ptr, 0, HEIGHT);
	if (p->fractal >= 14 && p->fractal != 21 && p->fractal != 24)
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 					\
				DIS / 2 - 5 * (int)ft_strlen("No colors available"), 		\
				HEIGHT + PARAM / 2 - 30, GREY_H, "No colors available");
	n = HEIGHT + 15;
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10, n, GREY_H, 	\
			"Informations");
	n += 45;
	ft_params1(p, n);
}
