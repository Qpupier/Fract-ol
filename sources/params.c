/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   params.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 12:48:14 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 20:35:35 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_param_line(t_mlx *mlx, int *n, char *str, long int param)
{
	char	*degree;

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, DIS + 10, *n, WHITE_H, str);
	degree = ft_itoa(param);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, DIS + 10 + 10 * ft_strlen(str), 	\
			*n, WHITE_H, degree);
	free(degree);
	*n += 30;
}

void	ft_param_line_help(t_mlx *mlx, int *n, char *str)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 2 * DIS + 10, *n, WHITE_H, str);
	*n += 30;
}

void	ft_param_line_float(t_param *p, int *n, char *str, double param)
{
	char	*tmp;

	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10, *n, WHITE_H, str);
	tmp = ft_ftoa(param,p->fractal == 24 ? 1 : 3);
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10 + 10 * ft_strlen(str), 	\
			*n, WHITE_H, ft_strcmp(tmp, "-0.000") ? tmp : "0.000");
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
		if (((p->fractal == 23 && p->koch) || (p->fractal == 24 && p->tree_nb == 3) ? i >= size : i <= size) || i == 0 || i == 2 * size - 1)
			while (++j < n + 40)
				ft_pixel_put(p->mlx->param2, i + DIS + 10, j, WHITE);
	}
}

void	ft_params_help(t_param *p)
{
	int	n;

	if (p->fractal >= 14 && p->fractal <= 17)
		return ;
	n = HEIGHT + 15;
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 2 * DIS + 10, n, GREY_H, "Help");
	n += 45;
	ft_param_line_help(p->mlx, &n, "Iterations : - | +");
	if (p->fractal < 21)
	{
		ft_param_line_help(p->mlx, &n, p->fractal == 20 ? "Zoom : Mouse scroll" : "Zoom : Mouse scroll & right click");
		ft_param_line_help(p->mlx, &n, "Coordinates : Arrows & Mouse (Left click)");
		n += 30;
	}
	if (p->fractal < 11)
		ft_param_line_help(p->mlx, &n, "Fractal degree : < | >");
	if (p->fractal == 7 || p->fractal == 9 || p->fractal == 11)
		ft_param_line_help(p->mlx, &n, "Mandelbrot degree : - | + ( _ | = )");
	else if (p->fractal == 18 || p->fractal == 19)
		ft_param_line_help(p->mlx, &n, "Newton degree : < | >");
	else if (p->fractal == 20)
	{
		n += 30;
		ft_param_line_help(p->mlx, &n, "Pythagore tree angle : < | >");
	}
	else if (p->fractal == 24)
	{
		n += 10;
		n+= 40;
		ft_param_line_help(p->mlx, &n, "Left branch degree : 4 | 1");
		if (p->tree_nb == 3)
			ft_param_line_help(p->mlx, &n, "Middle branch degree : 5 | 2");
		ft_param_line_help(p->mlx, &n, "Right branch degree : 6 | 3");
		ft_param_line_help(p->mlx, &n, "Size primary branch : - | + ( _ | = )");
		ft_param_line_help(p->mlx, &n, "Size branch ratio : < | >");
	}
	if (p->fractal < 5)
	{
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 2 * DIS + 10, n, WHITE_H, "Julia variations : Space bar");
		n += 30;
	}
	if (p->fractal < 14)
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 2 * DIS + 10, HEIGHT + PARAM - 30, WHITE_H, "Colors : Left, middle and right mouse click");
	else if (p->fractal == 21 || p->fractal == 24)
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, 2 * DIS + 10, HEIGHT + PARAM - 30, WHITE_H, "Colors : Left and right mouse click");
}

void	ft_colors_squares(t_param *p)
{
	int	i;
	int	j;

	i = 0;
	if (p->fractal < 14)
		while (++i <= NB_COLORS)
		{
			ft_line_straight_horiz(p->mlx->param2, ft_make_cplx(DIS + 79 + i * 50, PARAM - 31), ft_make_cplx(DIS + 101 + i * 50, PARAM - 31), WHITE);
			ft_line_straight_horiz(p->mlx->param2, ft_make_cplx(DIS + 79 + i * 50, PARAM - 10), ft_make_cplx(DIS + 101 + i * 50, PARAM - 10), WHITE);
			ft_line_straight_vert(p->mlx->param2, ft_make_cplx(DIS + 79 + i * 50, PARAM - 31), ft_make_cplx(DIS + 79 + i * 50, PARAM - 10), WHITE);
			ft_line_straight_vert(p->mlx->param2, ft_make_cplx(DIS + 100 + i * 50, PARAM - 31), ft_make_cplx(DIS + 100 + i * 50, PARAM - 10), WHITE);
			j = PARAM - 31;
			while (++j < PARAM - 10)
				ft_line_straight_horiz(p->mlx->param2, ft_make_cplx(DIS + 80 + i * 50, j), ft_make_cplx(DIS + 100 + i * 50, j), p->colors[i]);
		}
	else if (p->fractal == 21 || p->fractal == 24)
		while (++i <= 2)
		{
			ft_line_straight_horiz(p->mlx->param2, ft_make_cplx(DIS + 79 + i * 50, PARAM - 31), ft_make_cplx(DIS + 101 + i * 50, PARAM - 31), WHITE);
			ft_line_straight_horiz(p->mlx->param2, ft_make_cplx(DIS + 79 + i * 50, PARAM - 10), ft_make_cplx(DIS + 101 + i * 50, PARAM - 10), WHITE);
			ft_line_straight_vert(p->mlx->param2, ft_make_cplx(DIS + 79 + i * 50, PARAM - 31), ft_make_cplx(DIS + 79 + i * 50, PARAM - 10), WHITE);
			ft_line_straight_vert(p->mlx->param2, ft_make_cplx(DIS + 100 + i * 50, PARAM - 31), ft_make_cplx(DIS + 100 + i * 50, PARAM - 10), WHITE);
			j = PARAM - 31;
			while (++j < PARAM - 10)
				ft_line_straight_horiz(p->mlx->param2, ft_make_cplx(DIS + 80 + i * 50, j), ft_make_cplx(DIS + 100 + i * 50, j), p->fractal == 21 ? p->colors_carpet[i - 1] : p->colors_tree[i - 1]);
		}
}

void	ft_params(t_param *p)
{
	int		i;
	int		n;
	char	*tmp;

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
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS / 2 - 5 * (int)ft_strlen("No colors available"), HEIGHT + PARAM / 2 - 30, GREY_H, "No colors available");
	n = HEIGHT + 15;
	mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10, n, GREY_H, "Informations");
	n += 45;
	ft_param_line(p->mlx, &n, "Number of iterations : ", p->it[p->fractal] * (p->fractal == 16 || p->fractal == 17 ? 100 : 1) + p->it_tmp[p->fractal]);
	if (!((p->fractal >= 14 && p->fractal <= 17) || p->fractal >= 21))
	{
		ft_param_line(p->mlx, &n, "Zoom : ", p->dis_zoom[p->fractal]);
		if (p->fractal == 20)
		{
			tmp = ft_itoa((p->pos_left[p->fractal].rl + p->zoom[p->fractal] + 2) * WIDTH * 0.25);
			mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10 * ft_strlen("X coordinates : -XXX  ") + 10, n, WHITE_H, tmp);
			free(tmp);
			ft_param_line(p->mlx, &n, "X coordinates : ", (p->pos_left[p->fractal].rl + 2) * WIDTH * 0.25);
			tmp = ft_itoa((p->pos_left[p->fractal].im + p->zoom[p->fractal] + 2) * WIDTH * 0.25);
			mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10 * ft_strlen("X coordinates : -XXX  ") + 10, n, WHITE_H, tmp);
			free(tmp);
			ft_param_line(p->mlx, &n, "Y coordinates : ", (p->pos_left[p->fractal].im + 2) * WIDTH * 0.25);
		}
		else
		{
			tmp = ft_ftoa(p->pos_left[p->fractal].rl + p->zoom[p->fractal], 3);
			mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10 * ft_strlen("X coordinates : -X.XXX  ") + 10, n, WHITE_H, ft_strcmp(tmp, "-0.000") ? tmp : "0.000");
			free(tmp);
			ft_param_line_float(p, &n, "X coordinates : ", p->pos_left[p->fractal].rl);
			tmp = ft_ftoa(p->pos_left[p->fractal].im + p->zoom[p->fractal], 3);
			mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10 * ft_strlen("X coordinates : -X.XXX  ") + 10, n, WHITE_H, ft_strcmp(tmp, "-0.000") ? tmp : "0.000");
			free(tmp);
			ft_param_line_float(p, &n, "Y coordinates : ", p->pos_left[p->fractal].im);
		}
	}
	if (p->fractal < 11)
		ft_param_line(p->mlx, &n, "Fractal degree : ", p->deg[p->fractal]);
	if (p->fractal == 7 || p->fractal == 9 || p->fractal == 11)
		ft_param_line(p->mlx, &n, "Mandelbrot degree : ", p->deg_mandelbrot[p->fractal / 2 - 3]);
	else if (p->fractal == 18 || p->fractal == 19)
		ft_param_line(p->mlx, &n, "Newton degree : ", p->deg_newton[p->fractal - 18]);
	else if (p->fractal == 20)
	{
		ft_param_line(p->mlx, &n, "Pythagore tree size : ", 400 / p->zoom[p->fractal]);
		ft_param_line(p->mlx, &n, "Pythagore tree angle : ", p->pyth_angle);
	}
	else if (p->fractal == 23)
	{
		n += 10;
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10 + 5 * ft_strlen("  Inverted  ") - 5 * ft_strlen("Koch"), n, p->koch ? WHITE_H : BLACK_H, "Koch");
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10 + 15 * ft_strlen("  Inverted  ") - 5 * ft_strlen("Inverted"), n, p->koch ? BLACK_H : WHITE_H, "Inverted");
		n+= 40;
	}
	else if (p->fractal == 24)
	{
		n += 10;
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10 + 5 * ft_strlen(" 2 branches ") - 5 * ft_strlen("2 branches"), n, p->tree_nb == 2 ? BLACK_H : WHITE_H, "2 branches");
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10 + 15 * ft_strlen(" 3 branches ") - 5 * ft_strlen("3 branches"), n, p->tree_nb == 3 ? BLACK_H : WHITE_H, "3 branches");
		n+= 40;
		ft_param_line(p->mlx, &n, "Left branch degree : ", p->tree_degree[0]);
		if (p->tree_nb == 3)
			ft_param_line(p->mlx, &n, "Middle branch degree : ", p->tree_degree[1]);
		ft_param_line(p->mlx, &n, "Right branch degree : ", p->tree_degree[2]);
		ft_param_line(p->mlx, &n, "Size primary branch: ", p->tree_size);
		ft_param_line_float(p, &n, "Size branch ratio: ", p->tree_ratio);
	}
	if (p->fractal < 5)
	{
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10, n, WHITE_H, p->stop ? "Julia variations : Disable" : "Julia variations : Enable");
		n += 30;
	}
	if (p->fractal < 14)
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10, HEIGHT + PARAM - 30, WHITE_H, "3 colors : ");
	else if (p->fractal == 21 || p->fractal == 24)
		mlx_string_put(p->mlx->mlx_ptr, p->mlx->win_ptr, DIS + 10, HEIGHT + PARAM - 30, WHITE_H, "2 colors : ");
	ft_params_help(p);
}
