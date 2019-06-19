/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:49:53 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 19:35:44 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include "get_next_line.h"
# include "../../minilibx_macos/mlx.h"

# define RED_H 0xFF0000
# define GREEN_H 0x00FF00
# define BLUE_H 0x0000FF
# define YELLOW_H 0xFFFF00
# define CYAN_H 0x00FFFF
# define MAGENTA_H 0xFF00FF
# define WHITE_H 0xFFFFFF
# define GREY_H 0xAAAAAA
# define BLACK_H 0x000000
# define BLACK (t_rgb){0, 0, 0, 0}
# define WHITE (t_rgb){255, 255, 255, 0}
# define RED (t_rgb){255, 0, 0, 0}
# define GREEN (t_rgb){0, 255, 0, 0}
# define BLUE (t_rgb){0, 0, 255, 0}
# define GREY (t_rgb){150, 150, 150, 0}
# define BROWN (t_rgb){63, 34, 4, 0}

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_rgb;

typedef struct		s_cplx
{
	double			rl;
	double			im;
}					t_cplx;

typedef struct		s_real
{
	int				x;
	int				y;
}					t_real;

typedef struct		s_mlx_img
{
	void			*ptr;
	char			*img;
	int				width;
	int				height;
	int				bpp;
	int				s_l;
	int				endian;
}					t_mlx_img;

double				ft_abs(double nb);
int					ft_atoi(const char *str);
int					ft_atoi_hexa(const char *str);
double				ft_average(int nb1, int nb2, double p);
void				ft_bzero(void *s, size_t n);
t_rgb				ft_color_average(t_rgb c1, t_rgb c2, double p);
t_rgb				ft_color_hex_to_rgb(char *color);
t_rgb				ft_color_int_to_rgb(int nb);
t_rgb				ft_color_rgb_random(void);
char				*ft_color_rgb_to_hex(t_rgb rgb);
int					ft_color_rgb_to_int(t_rgb rgb);
int					ft_count_words(char *s, char c);
t_cplx				ft_cplx_add(t_cplx a, t_cplx b);
t_cplx				ft_cplx_average(t_cplx a, t_cplx z, double b);
t_cplx				ft_cplx_cos(t_cplx z);
t_cplx				ft_cplx_cosh(t_cplx z);
int					ft_cplx_discriminant(t_cplx z);
t_cplx				ft_cplx_div(t_cplx a, t_cplx b);
int					ft_cplx_equ(t_cplx a, t_cplx b);
t_cplx				ft_cplx_exp(t_cplx z);
t_cplx				ft_cplx_ln(t_cplx z);
double				ft_cplx_modul(t_cplx z);
double				ft_cplx_modul_2(t_cplx z);
t_cplx				ft_cplx_mult(t_cplx a, t_cplx b);
t_cplx				ft_cplx_pow(t_cplx z, int n);
t_cplx				ft_cplx_remove(t_cplx a, t_cplx b);
t_cplx				ft_cplx_sin(t_cplx z);
t_cplx				ft_cplx_sinh(t_cplx z);
void				ft_cplx_swap(t_cplx *a, t_cplx *b);
t_real				ft_cplx_to_real(t_cplx z);
t_cplx				ft_cplx_turn(t_cplx a, t_cplx o, double angle);
void				ft_create_img(void *ptr, t_mlx_img *img, int w, int h);
double				ft_deg_to_rad(int nb);
int					ft_digit_abs(int d);
int					ft_digit_hex_to_int(char c);
void				ft_error(char *str);
int					ft_exit(void);
int					ft_find(char *str, char c);
char				*ft_ftoa(double nb, int p);
t_rgb				ft_get_pixel(t_mlx_img img, int x, int y);
char				*ft_hex_color_complete(char *c);
void				ft_img_dark(t_mlx_img img);
int					ft_intlen(long int nb);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isnumber(int c);
int					ft_isprint(int c);
char				*ft_itoa(long int n);
void				ft_line(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color);
void				ft_line_horiz(t_mlx_img img, t_cplx a, t_cplx z, 		\
		t_rgb color);
int					ft_line_straight(t_mlx_img img, t_cplx a, t_cplx z, 	\
		t_rgb color);
int					ft_line_straight_horiz(t_mlx_img img, t_cplx a, 		\
		t_cplx z, t_rgb color);
int					ft_line_straight_vert(t_mlx_img img, t_cplx a, 			\
		t_cplx z, t_rgb color);
void				ft_line_vert(t_mlx_img img, t_cplx a, t_cplx z, 		\
		t_rgb color);
t_cplx				ft_make_cplx(double rl, double im);
t_real				ft_make_real(int x, int y);
double				ft_max(double a, double b);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
double				ft_min(double a, double b);
int					ft_mod(int a, int b);
int					ft_occur(const char *str, const char c);
void				ft_pixel_put(t_mlx_img img, int x, int y, t_rgb color);
int					ft_pow(double nb, int pow);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(const char *str);
void				ft_putstr_fd(char const *s, int fd);
t_cplx				ft_real_to_cplx(t_real xy);
int					ft_splitdel(char ***split);
double				ft_sq(double nb);
int					ft_sqrt(int nb);
char				*ft_stractrim(const char *str, const char c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strcspn(const char *s, const char *reject);
char				*ft_strctrim(char const *s, char c);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void(*f)(char*));
void				ft_striteri(char *s, void(*f)(unsigned int, char*));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					ft_strlen_words(const char *s, char c);
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_strmap_display(char *str, int l, int h);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
void				ft_strncdelete(char *str, char letter, char replace, 	\
		int count);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack, const char *needle, 	\
		size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strtrimsplit(char **str, char *n, char c);
void				ft_swap(int *a, int *b);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					get_next_line(const int fd, char **line);

#endif
