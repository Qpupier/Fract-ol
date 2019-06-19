# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/13 11:56:39 by qpupier      #+#   ##    ##    #+#        #
#    Updated: 2019/06/19 22:14:11 by qpupier     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRC_PATH = sources
SRC_NAME = 	colors/ft_color_average.c 		ft_occur.c 						\
			colors/ft_color_hex_to_rgb.c 	ft_pow.c 						\
			colors/ft_color_int_to_rgb.c 	ft_splitdel.c 					\
			colors/ft_color_rgb_random.c 	ft_sq.c 						\
			colors/ft_color_rgb_to_hex.c 	ft_sqrt.c 						\
			colors/ft_color_rgb_to_int.c 	ft_swap.c 						\
			cplx/ft_cplx_add.c 				ft_tolower.c 					\
			cplx/ft_cplx_average.c 			ft_toupper.c 					\
			cplx/ft_cplx_cos.c 				get_next_line.c 				\
			cplx/ft_cplx_cosh.c 			line/ft_line.c 					\
			cplx/ft_cplx_discriminant.c 	line/ft_line_horiz.c 			\
			cplx/ft_cplx_div.c 				line/ft_line_straight.c 		\
			cplx/ft_cplx_equ.c 				line/ft_line_straight_horiz.c 	\
			cplx/ft_cplx_exp.c 				line/ft_line_straight_vert.c 	\
			cplx/ft_cplx_ln.c 				line/ft_line_vert.c 			\
			cplx/ft_cplx_modul.c 			memory/ft_memalloc.c 			\
			cplx/ft_cplx_modul_2.c 			memory/ft_memccpy.c 			\
			cplx/ft_cplx_mult.c 			memory/ft_memchr.c 				\
			cplx/ft_cplx_pow.c 				memory/ft_memcmp.c 				\
			cplx/ft_cplx_remove.c 			memory/ft_memcpy.c 				\
			cplx/ft_cplx_sin.c 				memory/ft_memdel.c 				\
			cplx/ft_cplx_sinh.c 			memory/ft_memmove.c 			\
			cplx/ft_cplx_swap.c 			memory/ft_memset.c 				\
			cplx/ft_cplx_to_real.c 			mlx/ft_create_img.c 			\
			cplx/ft_cplx_turn.c 			mlx/ft_img_dark.c 				\
			cplx/ft_make_cplx.c 			mlx/ft_pixel_put.c 				\
			cplx/ft_make_real.c 			mlx/ft_get_pixel.c 				\
			cplx/ft_real_to_cplx.c 			str/ft_stractrim.c 				\
			display/ft_putchar.c 			str/ft_strcat.c 				\
			display/ft_putchar_fd.c 		str/ft_strchr.c 				\
			display/ft_putendl.c 			str/ft_strclr.c 				\
			display/ft_putendl_fd.c 		str/ft_strcmp.c 				\
			display/ft_putnbr.c 			str/ft_strcpy.c 				\
			display/ft_putnbr_fd.c 			str/ft_strcspn.c 				\
			display/ft_putstr.c 			str/ft_strctrim.c 				\
			display/ft_putstr_fd.c 			str/ft_strdel.c 				\
			ft_abs.c 						str/ft_strdup.c 				\
			ft_atoi.c 						str/ft_strequ.c 				\
			ft_atoi_hexa.c 					str/ft_striter.c 				\
			ft_average.c 					str/ft_striteri.c 				\
			ft_bzero.c 						str/ft_strjoin.c 				\
			ft_count_words.c 				str/ft_strlcat.c 				\
			ft_deg_to_rad.c 				str/ft_strlen.c 				\
			ft_digit_abs.c 					str/ft_strlen_words.c 			\
			ft_digit_hex_to_int.c 			str/ft_strmap.c 				\
			ft_error.c 						str/ft_strmap_display.c 		\
			ft_exit.c 						str/ft_strmapi.c 				\
			ft_find.c 						str/ft_strncat.c 				\
			ft_ftoa.c 						str/ft_strncdelete.c 			\
			ft_hex_color_complete.c 		str/ft_strncmp.c 				\
			ft_intlen.c 					str/ft_strncpy.c 				\
			ft_isalnum.c 					str/ft_strnequ.c 				\
			ft_isalpha.c 					str/ft_strnew.c 				\
			ft_isascii.c 					str/ft_strnstr.c 				\
			ft_isdigit.c 					str/ft_strrchr.c 				\
			ft_isnumber.c 					str/ft_strsplit.c 				\
			ft_isprint.c 					str/ft_strstr.c 				\
			ft_itoa.c 						str/ft_strsub.c 				\
			ft_max.c 						str/ft_strtrim.c 				\
			ft_min.c 						str/ft_strtrimsplit.c 				\
			ft_mod.c
SRC_SUP = {colors,cplx,display,line,memory,mlx,str}
OBJ_PATH = .objects
INC_PATH = includes
CPPFLAGS = -I $(INC_PATH)
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

ERASE = \033[2K\r
BLUE = \033[36m
WHITE = \033[37m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
END = \033[0m

.PHONY: all, clean, fclean, re

all: mlx $(NAME)

$(NAME): $(OBJ)
	@ar -rc $@ $^
	@ranlib $@
	@printf "$(ERASE)$(BLUE)> libft : $(GREEN)Success !$(END)\n"

mlx:
	@make -C ../minilibx_macos

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c ../minilibx_macos/libmlx.a
	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)/$(SRC_SUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"

clean:
	@rm -rf $(OBJ_PATH)
	@printf "$(BLUE)> Deleted : $(RED)libft/$(OBJ_PATH)$(END)\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(BLUE)> Deleted : $(RED)$(NAME)$(END)\n"
	@make -C ../minilibx_macos clean

re: fclean all

norme:
	@norminette $(SRC) $(INC_PATH)
