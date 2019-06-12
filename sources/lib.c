#include "../includes/fractol.h"

void	ft_pixel_put(t_mlx_img img, int x, int y, t_rgb color)
{
	int t;

	if (x < 0 || y < 0 || x >= img.width || y >= img.height)
		return ;
	t = y * img.s_l + x * 4;
	img.img[t] = (char)(color.b);
	img.img[t + 1] = (char)(color.g);
	img.img[t + 2] = (char)(color.r);
	img.img[t + 3] = (char)(color.a);
}

void	ft_create_img(void *ptr, t_mlx_img *img, int w, int h)
{
	img->ptr = mlx_new_image(ptr, w, h);
	img->img = mlx_get_data_addr(img->ptr, &img->bpp, &img->s_l, &img->endian);
	img->width = w;
	img->height = h;
}

t_cplx	ft_cplx_turn(t_cplx a, t_cplx o, double angle)
{
	return (ft_cplx_add(ft_cplx_mult(ft_cplx_remove(a, o), 	\
			ft_make_cplx(cos(angle), sin(angle))), o));
}

t_rgb	ft_get_pixel(t_mlx_img img, int x, int y)
{
	t_rgb	rgb;
	int		t;

	if (x < 0 || y < 0 || x >= img.width || y >= img.height)
		return ((t_rgb){0, 0, 0, 0});
	t = y * img.s_l + x * 4;
	rgb.b = img.img[t] + (img.img[t] < 0 ? 256 : 0);
	rgb.g = img.img[t + 1] + (img.img[t + 1] < 0 ? 256 : 0);
	rgb.r = img.img[t + 2] + (img.img[t + 2] < 0 ? 256 : 0);
	rgb.a = img.img[t + 3] + (img.img[t + 3] < 0 ? 256 : 0);
	return (rgb);
}

void	ft_img_dark(t_mlx_img img)
{
	int	i;
	int	j;

	j = -1;
	while (++j < img.height)
	{
		i = -1;
		while (++i < img.width)
			ft_pixel_put(img, i, j, BLACK);
	}
}

t_rgb	ft_color_rgb_random(void)
{
	t_rgb	color;

	color.r = rand() % 255;
	color.g = rand() % 255;
	color.b = rand() % 255;
	color.a = 0;
	return (color);
}

void	ft_cplx_swap(t_cplx *a, t_cplx *b)
{
	t_cplx	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_line_horiz(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	double	x1;
	double	y1;
	double	b;
	double	dx;
	double	dy;

	if (a.rl > z.rl)
		ft_cplx_swap(&a, &z);
	x1 = a.rl;
	y1 = a.im;
	dx = z.rl - x1;
	dy = z.im - y1;
	b = y1 - x1 * dy / dx;
	while (z.rl - x1 > 0)
	{
		ft_pixel_put(img, x1, x1 * dy / dx + b, color);
		x1 <= z.rl ? x1++ : x1--;
	}
}

void	ft_line_vert(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	double	x1;
	double	y1;
	double	b;
	double	dx;
	double	dy;

	if (a.im > z.im)
		ft_cplx_swap(&a, &z);
	x1 = a.rl;
	y1 = a.im;
	dx = z.rl - x1;
	dy = z.im - y1;
	b = y1 - x1 * dy / dx;
	while (z.im - y1 > 0)
	{
		ft_pixel_put(img, (y1 - b) * dx / dy, y1, color);
		y1 <= z.im ? y1++ : y1--;
	}
}

int		ft_line_straight_vert(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	int	y1;

	y1 = a.im;
	while (ft_abs(z.im - y1) >= 1)
	{
		ft_pixel_put(img, a.rl, y1, color);
		y1 < z.im ? y1++ : y1--;
	}
	return (1);
}

int		ft_line_straight_horiz(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	int	x1;

	x1 = a.rl;
	while (ft_abs(z.rl - x1) >= 1)
	{
		ft_pixel_put(img, x1, a.im, color);
		x1 < z.rl ? x1++ : x1--;
	}
	return (1);
}

int		ft_line_straight(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	if (a.rl == z.rl)
		return (ft_line_straight_vert(img, a, z, color));
	else if (a.im == z.im)
		return (ft_line_straight_horiz(img, a, z, color));
	return (0);
}

void	ft_line(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	int	dx;
	int	dy;

	if (ft_line_straight(img, a, z, color))
		return ;
	dx = ft_abs(z.rl - a.rl);
	dy = ft_abs(z.im - a.im);
	dx >= dy ? ft_line_horiz(img, a, z, color) : ft_line_vert(img, a, z, color);
}

t_cplx	ft_coord_average(t_cplx a, t_cplx z, double b)
{
	return (ft_make_cplx(a.rl + b * (z.rl - a.rl), a.im + b * (z.im - a.im)));
}

t_real	ft_make_real(int x, int y)
{
	t_real	r;

	r.x = x;
	r.y = y;
	return (r);
}

t_rgb	ft_color_int_to_rgb(int nb)
{
	t_rgb	rgb;

	rgb.r = nb / 65536;
	rgb.g = nb / 256 % 256;
	rgb.b = nb % 256;
	rgb.a = 0;
	return (rgb);
}

t_real	ft_cplx_to_real(t_cplx z)
{
	t_real	r;

	r.x = z.rl;
	r.y = z.im;
	return (r);
}

t_cplx	ft_real_to_cplx(t_real xy)
{
	t_cplx	r;

	r.rl = xy.x;
	r.im = xy.y;
	return (r);
}

int		ft_pow(double nb, int pow)
{
	double	result;

	result = 1;
	while (pow--)
		result *= nb;
	return (result);
}

char	*ft_ftoa(double nb, int p)
{
	char	*s;
	char	*t;

	p = (p < 0 ? 0 : p);
	if (!(s = ft_strnew(ft_intlen(nb) + (p ? p + 1 : p))))
		ft_error("Malloc error");
	if (nb < 0)
	{
		ft_strcat(s, "-");
		nb = -nb;
	}
	nb += 5.0 / ft_pow(10, p + 1);
	t = ft_itoa(nb);
	ft_strcat(s, t);
	ft_strdel(&t);
	if (p)
		ft_strcat(s, ".");
	while (p--)
	{
		nb -= (int)nb;
		t = ft_itoa((nb *= 10));
		ft_strcat(s, t);
		ft_strdel(&t);
	}
	return (s);
}

int		ft_cplx_equ(t_cplx a, t_cplx b)
{
	if (a.rl == b.rl && a.im == b.im)
		return (1);
	return (0);
}

int		ft_color_rgb_to_int(t_rgb rgb)
{
	return ((rgb.r << 16) + (rgb.g << 8) + rgb.b);
}