/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:49:53 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 19:38:42 by qpupier     ###    #+. /#+    ###.fr     */
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

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

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

void				ft_putchar(char c);
void				ft_putstr(const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				ft_putnbr(int n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strstr(const char *haystack, const char *needle);
void				ft_putendl(char const *s);
char				*ft_strcat(char *s1, const char *s2);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_atoi(const char *str);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle, 	\
					size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isnumber(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char*));
void				ft_striteri(char *s, void(*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strctrim(char const *s, char c);
char				**ft_strsplit(char const *s, char c);
int					ft_count_words(char *s, char c);
int					ft_strlen_words(const char *s, char c);
char				**ft_strtrimsplit(char **str, char *n, char c);
char				*ft_itoa(long int n);
int					ft_intlen(long int nb);
int					ft_digit_abs(int d);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_strsplit_lst(char const *s, char c);
int					ft_find(char *str, char c);
size_t				ft_strcspn(const char *s, const char *reject);
int					ft_sqrt(int nb);
double				ft_sq(double nb);
int					ft_occur(const char *str, const char c);
char				*ft_stractrim(const char *str, const char c);
void				ft_strncdelete(char *str, char letter, char replace, 	\
					int count);
void				ft_strmap_display(char *str, int l, int h);
void				ft_error(char *str);
int					ft_mod(int a, int b);
void				ft_swap(int *a, int *b);
int					ft_atoi_hexa(const char *str);
double				ft_abs(double nb);
double				ft_deg_to_rad(int nb);
double				ft_average(int nb1, int nb2, double p);
char				*ft_hex_color_complete(char *c);
t_rgb				ft_color_hex_to_rgb(char *color);
t_rgb				ft_color_average(t_rgb c1, t_rgb c2, double p);
int					ft_exit(void);
char				*ft_color_rgb_to_hex(t_rgb rgb);
int					ft_digit_hex_to_int(char c);
int					ft_splitdel(char ***split);
double				ft_cplx_modul_2(t_cplx z);
double				ft_cplx_modul(t_cplx z);
t_cplx				ft_cplx_mult(t_cplx a, t_cplx b);
t_cplx				ft_cplx_pow(t_cplx z, int n);
t_cplx				ft_cplx_add(t_cplx a, t_cplx b);
t_cplx				ft_cplx_remove(t_cplx a, t_cplx b);
t_cplx				ft_cplx_cos(t_cplx z);
t_cplx				ft_cplx_sin(t_cplx z);
t_cplx				ft_cplx_cosh(t_cplx z);
t_cplx				ft_cplx_sinh(t_cplx z);
t_cplx				ft_cplx_div(t_cplx a, t_cplx b);
t_cplx				ft_cplx_ln(t_cplx z);
t_cplx				ft_cplx_exp(t_cplx z);
t_cplx				ft_make_cplx(double rl, double im);
int					ft_cplx_discriminant(t_cplx z);

#endif
