/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   legend.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/29 09:12:28 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/22 14:48:00 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_vignette(t_mlx_img param, int pos, int max, t_mlx_img img)
{
	int			i;
	int			j;
	t_vignette	r;

	r = (t_vignette){0, 0, 0, 0};
	if (max == NB_FRACTALES)
		r = (t_vignette){pos % 2, pos / 2, 								\
				DIS / 2, (HEIGHT - (max == 10 ? 50 : 0)) / 5};
	else if (max == 9 && !pos)
		r = (t_vignette){0, 0, DIS, (HEIGHT - 50) / 3};
	else if (max == 9)
		r = (t_vignette){(pos + 3) % 2, (pos + 3) / 2, 					\
				DIS / 2, (HEIGHT - 50) / 6};
	else if (max == 5 && !pos)
		r = (t_vignette){0, 0, DIS, (HEIGHT - 50) / 2};
	else if (max == 5)
		r = (t_vignette){(pos + 3) % 2, (pos + 3) / 2, 					\
				DIS / 2, (HEIGHT - 50) / 4};
	else if (max == 2)
		r = (t_vignette){0, pos, DIS, (HEIGHT - 50) / 2};
	j = -1;
	while (++j < r.h)
	{
		i = -1;
		while (++i < r.w)
			ft_pixel_put(param, i + r.x * r.w, 							\
					j + r.y * r.h + (max != NB_FRACTALES ? 50 : 0), 	\
					ft_get_pixel(img, i * WIDTH / r.w, j * HEIGHT / r.h));
	}
}

void	ft_legend(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 5, 5, WHITE_H, "JULIA");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 	\
			5 + DIS / 2, 5, WHITE_H, "MANDELBROT");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 	\
			5, 5 + HEIGHT / 5, WHITE_H, "BUDDHABROT");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 	\
			5 + DIS / 2, 5 + HEIGHT / 5, WHITE_H, "BUBBLEBROT");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 	\
			5, 5 + 2 * HEIGHT / 5, WHITE_H, "FERN");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 	\
			5 + DIS / 2, 5 + 2 * HEIGHT / 5, WHITE_H, "NEWTON");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 	\
			5, 5 + 3 * HEIGHT / 5, WHITE_H, "PYTHAGORE");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 	\
			5 + DIS / 2, 5 + 3 * HEIGHT / 5, WHITE_H, "SIERPINSKI");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 	\
			5, 5 + 4 * HEIGHT / 5, WHITE_H, "KOCH FLAKE");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 	\
			5 + DIS / 2, 5 + 4 * HEIGHT / 5, WHITE_H, "TREE");
}

void	ft_miniatures_hide(t_param *p)
{
	int	i;

	ft_vignette(p->mlx->param_julia, 0, 5, p->mlx->win[0]);
	ft_vignette(p->mlx->param_julia, 1, 5, p->mlx->win[1]);
	ft_vignette(p->mlx->param_julia, 2, 5, p->mlx->win[2]);
	ft_vignette(p->mlx->param_julia, 3, 5, p->mlx->win[3]);
	ft_vignette(p->mlx->param_julia, 4, 5, p->mlx->win[4]);
	ft_vignette(p->mlx->param_mandelbrot, 0, 9, p->mlx->win[5]);
	ft_vignette(p->mlx->param_mandelbrot, 1, 9, p->mlx->win[6]);
	ft_vignette(p->mlx->param_mandelbrot, 2, 9, p->mlx->win[7]);
	ft_vignette(p->mlx->param_mandelbrot, 3, 9, p->mlx->win[8]);
	ft_vignette(p->mlx->param_mandelbrot, 4, 9, p->mlx->win[9]);
	ft_vignette(p->mlx->param_mandelbrot, 5, 9, p->mlx->win[10]);
	ft_vignette(p->mlx->param_mandelbrot, 6, 9, p->mlx->win[11]);
	ft_vignette(p->mlx->param_mandelbrot, 7, 9, p->mlx->win[12]);
	ft_vignette(p->mlx->param_mandelbrot, 8, 9, p->mlx->win[13]);
	i = 100;
	while (i--)
	{
		ft_vignette(p->mlx->param_fern[i], 0, 2, p->mlx->win_fern[0][16]);
		ft_vignette(p->mlx->param_fern[i], 1, 2, p->mlx->win_fern[1][17]);
	}
	ft_vignette(p->mlx->param_newton, 0, 2, p->mlx->win[18]);
	ft_vignette(p->mlx->param_newton, 1, 2, p->mlx->win[19]);
	ft_vignette(p->mlx->param_sierpinsky, 0, 2, p->mlx->win[21]);
	ft_vignette(p->mlx->param_sierpinsky, 1, 2, p->mlx->win[22]);
}

void	ft_miniatures(t_param *p)
{
	ft_img_dark(&p->mlx->param_dark);
	p->vignette = 1;
	ft_vignette(p->mlx->param, 0, NB_FRACTALES, p->mlx->win[0]);
	ft_button(p->mlx->param, 0, 0);
	ft_vignette(p->mlx->param, 1, NB_FRACTALES, p->mlx->win[5]);
	ft_button(p->mlx->param, DIS / 2, 0);
	ft_vignette(p->mlx->param, 2, NB_FRACTALES, p->mlx->win[14]);
	ft_vignette(p->mlx->param, 3, NB_FRACTALES, p->mlx->win[15]);
	ft_vignette(p->mlx->param, 4, NB_FRACTALES, p->mlx->win_fern[0][16]);
	ft_button(p->mlx->param, 0, 2 * HEIGHT / 5);
	ft_vignette(p->mlx->param, 5, NB_FRACTALES, p->mlx->win[18]);
	ft_button(p->mlx->param, DIS / 2, 2 * HEIGHT / 5);
	ft_vignette(p->mlx->param, 6, NB_FRACTALES, p->mlx->win[20]);
	ft_vignette(p->mlx->param, 7, NB_FRACTALES, p->mlx->win[21]);
	ft_button(p->mlx->param, DIS / 2, 3 * HEIGHT / 5);
	ft_size_koch(p, ft_make_cplx(0, 4 * HEIGHT / 5), DIS / 2, HEIGHT / 5);
	ft_tree(p, ft_make_cplx(3 * DIS / 4, HEIGHT - HEIGHT / 50), 0, 	\
			(t_tree){HEIGHT / 25, 0});
	ft_miniatures_hide(p);
	ft_init_params(p);
	p->vignette = 0;
}

void	ft_trace_borders(void *mlx_ptr, void *win_ptr, int fractal)
{
	int	i;
	int	j;

	mlx_clear_window(mlx_ptr, win_ptr);
	i = 34;
	while (++i < 65)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 10, i, WHITE_H);
		mlx_pixel_put(mlx_ptr, win_ptr, 290, i, WHITE_H);
	}
	i = 9;
	while (++i < 290)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, 35, WHITE_H);
		mlx_pixel_put(mlx_ptr, win_ptr, i, 65, WHITE_H);
	}
	j = 35;
	while (++j < 65)
	{
		i = 10;
		while (++i < (fractal + 1) * 280 / (double)NB_FRACTALES + 10)
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, GREEN_H);
	}
}
