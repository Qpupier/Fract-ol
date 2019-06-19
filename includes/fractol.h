/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 21:28:31 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 17:28:50 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/includes/libft.h"
# include "keys.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# define DIS 320
# define PARAM 320
# define SIZE 800
# define WIDTH SIZE
# define HEIGHT SIZE
# define MIN SIZE
# define MAX SIZE
# define THREAD_MAX 10
# define THREAD_WIDTH WIDTH / THREAD_MAX
# define NB_FRACTALES 25
# define NB_COLORS 3

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_loading_ptr;
	void		*win_loading_ptr;
	t_mlx_img	win[NB_FRACTALES];
	t_mlx_img	win_fern[2][100];
	t_mlx_img	param;
	t_mlx_img	param2;
	t_mlx_img	param_dark;
	t_mlx_img	param_julia;
	t_mlx_img	param_mandelbrot;
	t_mlx_img	param_fern[100];
	t_mlx_img	param_newton;
	t_mlx_img	param_sierpinski;
}				t_mlx;

typedef struct	s_line
{
	int			x;
	int			y;
	t_rgb		color;
}				t_line;

typedef struct	s_fern
{
	int			p;
	float		mat_2_2[4];
	float		mat_1_2[2];
	int			max;
}				t_fern;

typedef struct	s_param
{
	t_mlx		*mlx;
	t_cplx		c[14];
	int			it[NB_FRACTALES];
	double		it_tmp[NB_FRACTALES];
	long double	zoom[NB_FRACTALES];
	int			dis_zoom[NB_FRACTALES];
	int			stop;
	int			min;
	int			max;
	t_cplx		pos_left[NB_FRACTALES];
	int			fractal;
	int			*buddhabrot;
	t_fern		fern[2][4];
	int			deg[NB_FRACTALES];
	int			deg_mandelbrot[3];
	int			deg_newton[2];
	t_rgb		*colors_newton;
	t_rgb		colors[NB_FRACTALES][NB_COLORS + 1];
	t_rgb		colors_carpet[2];
	t_rgb		colors_tree[2];
	int			pyth_angle;
	int			triangle_init;
	int			koch;
	int			tree_nb;
	int			tree_size;
	int			tree_degree[3];
	double		tree_ratio;
	int			init;
	void		(*init_fractal[NB_FRACTALES])(struct s_param *, int);
	int			vignette;
	int			param;
	int			mouse_l;
	int			mouse_r;
	t_cplx		mouse;
	int			screenshot;
}				t_param;

typedef struct	s_vignette
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_vignette;

typedef struct	s_tree
{
	int			size;
	int			nb;
}				t_tree;

typedef struct	s_pyth
{
	int			nb;
	int			size;
	int			pyth_deg;
	int			side;
}				t_pyth;

void			ft_pixel_put(t_mlx_img img, int x, int y, t_rgb color);
void			ft_create_img(void *ptr, t_mlx_img *img, int w, int h);
t_cplx			ft_cplx_turn(t_cplx a, t_cplx o, double angle);
t_rgb			ft_get_pixel(t_mlx_img img, int x, int y);
void			ft_img_dark(t_mlx_img img);
t_rgb			ft_color_rgb_random(void);
void			ft_cplx_swap(t_cplx *a, t_cplx *b);
void			ft_line(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color);
void			ft_line_vert(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color);
void			ft_line_horiz(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color);
int				ft_line_straight(t_mlx_img img, t_cplx a, t_cplx z, 	\
		t_rgb color);
int				ft_line_straight_vert(t_mlx_img img, t_cplx a, t_cplx z, 	\
		t_rgb color);
int				ft_line_straight_horiz(t_mlx_img img, t_cplx a, t_cplx z, 	\
		t_rgb color);
t_cplx			ft_coord_average(t_cplx a, t_cplx z, double b);
t_real			ft_make_real(int x, int y);
t_rgb			ft_color_int_to_rgb(int nb);
t_real			ft_cplx_to_real(t_cplx z);
t_cplx			ft_real_to_cplx(t_real xy);
int				ft_pow(double nb, int pow);
char			*ft_ftoa(double nb, int p);
double			ft_max(double a, double b);
int				ft_cplx_equ(t_cplx a, t_cplx b);
int				ft_color_rgb_to_int(t_rgb rgb);
double			ft_min(double a, double b);
double			ft_max(double a, double b);

void			ft_display2(t_param *p, double max);
int				ft_buddha(t_param *p);
void			ft_miniatures(t_param *p);
void			ft_init(t_param *p);
void			ft_create_window(t_param *p);
void			ft_init_fern_values(t_param *p);
void			ft_fern(t_mlx_img img, t_fern fern[2][4], int n, int it);
int				ft_deal_key(int key, t_param *param);
int				ft_mouse_move(int x, int y, t_param *p);
int				ft_mouse_event_scroll(int key, int x, int y, t_param *p);
int				ft_deal_key_release(int key, int x, int y, t_param *p);
void			*ft_display(void *t);
void			ft_multithreading(t_param *p);
void			ft_pythagore(t_param *p, t_cplx xy, t_pyth deg);
void			ft_tree(t_param *p, t_cplx xy, double tree_angle, t_tree t);
void			ft_vignette(t_mlx_img param, int x, int y, t_mlx_img img);
void			ft_fractol(t_param *p);
void			ft_legend(t_mlx *mlx);
void			ft_init_params(t_param *p);
void			ft_sierpinski_carpet(t_param *p, t_real o, t_real coord, 	\
		int nb);
void			ft_sierpinski_triangle(t_param *p, t_real o, int size, int nb);
void			ft_size_koch(t_param *p, t_cplx o, int w, int h);
void			ft_fractal_newton(t_param *p, double x, double y);
t_cplx			ft_iter(t_param *p, t_cplx z);
t_cplx			ft_result(t_param *p, t_cplx z, t_cplx c);
void			ft_algo(t_param *p, double x, double y);
void			ft_put_image(t_param *p);
void			ft_trace_borders(void *mlx_ptr, void *win_ptr, int fractal);
void			ft_choice_julia(t_param *p);
void			ft_choice_mandelbrot(t_param *p);
void			ft_choice_fern(t_param *p);
void			ft_choice_newton(t_param *p);
void			ft_choice_sierpinski(t_param *p);
void			ft_return_button(t_mlx_img img);
void			ft_button(t_mlx_img img, int x, int y);
void			ft_params(t_param *p);
void			ft_colors(t_param *p);
void			ft_loading(t_param *p);
t_rgb			ft_sierpinski_color(t_param *p, int nb);
void			ft_refresh(t_param *p);
void			ft_img_fern(t_param *p);
void			ft_display_result(t_param *p, double i, double x, double y);
t_cplx			ft_scale_coords(t_param *p, double x, double y);
t_cplx			ft_inverse_coords(t_param *p, double x, double y);
void			ft_legend_julia(void *mlx_ptr, void *win_ptr);
void			ft_legend_mandelbrot(void *mlx_ptr, void *win_ptr);
void			ft_legend_newton(void *mlx_ptr, void *win_ptr);
void			ft_legend_fern(void *mlx_ptr, void *win_ptr);
void			ft_legend_sierpinski(void *mlx_ptr, void *win_ptr);
void			ft_usage(void);
void			ft_init_fractal(t_param *p, char *fractal);
void			ft_init_triangle(t_param *p, int fractal);
void			ft_init_koch(t_param *p, int fractal);
void			ft_init_fern(t_param *p, int fractal);
void			ft_init_newton(t_param *p, int fractal);
void			ft_init_pythagore(t_param *p, int fractal);
void			ft_init_carpet(t_param *p, int fractal);
void			ft_init_others(t_param *p, int fractal);
void			ft_init_mandelbrot(t_param *p, int fractal);
void			ft_init_julia(t_param *p, int fractal);
void			ft_init_tree(t_param *p, int fractal);
void			ft_param_line(t_mlx *mlx, int *n, char *str, long int param);
void			ft_param_line_float(t_param *p, int *n, char *str, 	\
		double param);
void			ft_param_button(t_param *p, int n);
void			ft_params_help(t_param *p);
void			ft_params1(t_param *p, int n);
void			ft_colors_squares(t_param *p);
void			ft_param_line_help(t_mlx *mlx, int *n, char *str);
void			ft_it_less(t_param *p, int tmp);
void			ft_it_more(t_param *p, int tmp);
void			ft_it_inf(t_param *p);
void			ft_it_sup(t_param *p);
void			ft_choice_1(t_param *p, int x, int y);
void			ft_choice_2(t_param *p, int x, int y);
void			ft_choice_3(t_param *p, int y);
void			ft_choice_4(t_param *p, int y);
void			ft_choice_5(t_param *p, int y);
void			ft_top_less(t_param *p);
void			ft_top_more(t_param *p);
void			ft_event_tree(t_param *p, int key);
void			ft_event_moves(t_param *p, int key);
void			ft_event_display(t_param *p, int key);
void			ft_choice_param(t_param *p, int x, int y);
int				ft_button_degraded(t_param *p, int key, double x, double y);
void			ft_mouse_zoom(t_param *p, int key, int x, int y);
void			ft_left_click(t_param *p, int x, int y);
void			ft_mouse_event_win(t_param *p, int key, int x, int y);
void			ft_refresh_1(t_param *p, int x, int y);
void			ft_refresh_2(t_param *p, int x, int y);
void			ft_find_zoom(t_param *p, double prev, double after);
void			ft_params3(t_param *p, int n);

#endif
