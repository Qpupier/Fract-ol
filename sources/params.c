/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   params.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 12:48:14 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/03 10:27:17 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_param_line(t_mlx *mlx, int *n, char *str, long int param)
{
	char	*degree;

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, *n, WHITE_H, str);
	degree = ft_itoa(param);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10 + 10 * ft_strlen(str), 	\
			*n, WHITE_H, degree);
	free(degree);
	*n += 30;
}

void	ft_param_line_float(t_mlx *mlx, int *n, char *str, double param)
{
	char	*tmp;

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, *n, WHITE_H, str);
	tmp = ft_ftoa(param, 3);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10 + 10 * ft_strlen(str), 	\
			*n, WHITE_H, ft_strcmp(tmp, "-0.000") ? tmp : "0.000");
	free(tmp);
	*n += 30;
}

void	ft_param_button(t_param *p, int n)
{
	int	i;
	int	j;
	int	size;

	ft_img_dark(&p->mlx->param2);
	n += 30;
	size = 10 * ft_strlen("  Inverted  ");
	i = DIS / 2 - size - 1;
	while (++i < DIS / 2 + size)
	{
		ft_pixel_put(p->mlx->param2, i, n, WHITE);
		ft_pixel_put(p->mlx->param2, i, n + 40, WHITE);
		j = n - 1;
		if (((p->fractal == 23 && p->koch) || (p->fractal == 24 && p->tree_nb == 3) ? i >= DIS / 2 : i <= DIS / 2) || i == DIS / 2 - size || i == DIS / 2 + size - 1)
			while (++j < n + 40)
				ft_pixel_put(p->mlx->param2, i, j, WHITE);
	}
}

void	ft_params(t_param *p)
{
	int		i;
	int		n;
	char	*tmp;

	p->fractal >= 23 ? ft_param_button(p, 15) : ft_img_dark(&p->mlx->param2);
	i = -1;
	while (++i < DIS + WIDTH)
		ft_pixel_put(p->mlx->param2, i, 0, WHITE);
	i = -1;
	while (++i < PARAM)
		ft_pixel_put(p->mlx->param2, DIS - 1, i, WHITE);
	mlx_put_image_to_window(p->mlx->mlx_ptr, p->mlx->win_ptr, 	\
			p->mlx->param2.ptr, 0, HEIGHT);
	n = HEIGHT + 15;
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 10, n, GREY_H, "Informations");
	n += 30;
	if (p->fractal < 11)
		ft_param_line(p->mlx, &n, "Fractal degree : ", p->deg[p->fractal]);
	if (p->fractal == 7 || p->fractal == 9 || p->fractal == 11)
		ft_param_line(p->mlx, &n, "Mandelbrot degree : ", p->deg_mandelbrot[p->fractal / 2 - 3]);
	else if (p->fractal == 18 || p->fractal == 19)
		ft_param_line(p->mlx, &n, "Newton degree : ", p->deg_newton[p->fractal - 18]);
	else if (p->fractal == 20)
	{
		ft_param_line(p->mlx, &n, "Pythagore tree size : ", p->pyth_size);
		ft_param_line(p->mlx, &n, "Pythagore tree angle : ", p->pyth_angle);
	}
	else if (p->fractal == 23)
	{
		n += 10;
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS / 2 - 10 * ft_strlen("  Inverted  ") / 2 - 5 * ft_strlen("Koch"), n, p->koch ? WHITE_H : BLACK_H, "Koch");
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS / 2 + 10 * ft_strlen("  Inverted  ") / 2 - 5 * ft_strlen("Inverted"), n, p->koch ? BLACK_H : WHITE_H, "Inverted");
		n+= 40;
	}
	else if (p->fractal == 24)
	{
		n += 10;
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS / 2 - 10 * ft_strlen(" 2 branches ") / 2 - 5 * ft_strlen("2 branches"), n, p->tree_nb == 2 ? BLACK_H : WHITE_H, "2 branches");
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS / 2 + 10 * ft_strlen(" 3 branches ") / 2 - 5 * ft_strlen("3 branches"), n, p->tree_nb == 3 ? BLACK_H : WHITE_H, "3 branches");
		n+= 40;
		ft_param_line(p->mlx, &n, "Left branch degree : ", p->tree_degree[0]);
		if (p->tree_nb == 3)
			ft_param_line(p->mlx, &n, "Middle branch degree : ", p->tree_degree[1]);
		ft_param_line(p->mlx, &n, "Right branch degree : ", p->tree_degree[2]);
	}
	n = HEIGHT + PARAM - 120;
	tmp = ft_ftoa(p->pos_left[p->fractal].rl + p->zoom[p->fractal], 3);
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 10 * ft_strlen("X coordonates : -X.XXX  ") + 10, n, 0xFFFFFF, ft_strcmp(tmp, "-0.000") ? tmp : "0.000");
	free(tmp);
	ft_param_line_float(p->mlx, &n, "X coordonates : ", p->pos_left[p->fractal].rl);
	tmp = ft_ftoa(p->pos_left[p->fractal].im + p->zoom[p->fractal], 3);
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 10 * ft_strlen("X coordonates : -X.XXX  ") + 10, n, 0xFFFFFF, ft_strcmp(tmp, "-0.000") ? tmp : "0.000");
	free(tmp);
	ft_param_line_float(p->mlx, &n, "Y coordonates : ", p->pos_left[p->fractal].im);
	ft_param_line(p->mlx, &n, "Zoom : ", p->dis_zoom[p->fractal]);
	ft_param_line(p->mlx, &n, "Number of iterations : ", p->it[p->fractal]);
}
