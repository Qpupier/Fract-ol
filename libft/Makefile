# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 16:44:21 by qpupier      #+#   ##    ##    #+#        #
#    Updated: 2019/05/11 15:01:06 by qpupier     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a
INCLUDES = includes/*.h
DIR = objects
SOURCES = sources
FLAGS = -Wall -Wextra -Werror
FILES = $(DIR)/ft_strncpy.o				\
		$(DIR)/ft_putchar.o				\
		$(DIR)/ft_putstr.o				\
		$(DIR)/ft_putnbr.o				\
		$(DIR)/ft_strcmp.o				\
		$(DIR)/ft_strcpy.o				\
		$(DIR)/ft_strlen.o				\
		$(DIR)/ft_strdup.o				\
		$(DIR)/ft_strstr.o				\
		$(DIR)/ft_putendl.o				\
		$(DIR)/ft_strcat.o				\
		$(DIR)/ft_memset.o				\
		$(DIR)/ft_bzero.o				\
		$(DIR)/ft_memcpy.o				\
		$(DIR)/ft_memccpy.o				\
		$(DIR)/ft_atoi.o				\
		$(DIR)/ft_memmove.o				\
		$(DIR)/ft_memchr.o				\
		$(DIR)/ft_memcmp.o				\
		$(DIR)/ft_strncat.o				\
		$(DIR)/ft_strlcat.o				\
		$(DIR)/ft_strchr.o				\
		$(DIR)/ft_strrchr.o				\
		$(DIR)/ft_strnstr.o				\
		$(DIR)/ft_strncmp.o				\
		$(DIR)/ft_isalpha.o				\
		$(DIR)/ft_isdigit.o				\
		$(DIR)/ft_isnumber.o			\
		$(DIR)/ft_isalnum.o				\
		$(DIR)/ft_isascii.o				\
		$(DIR)/ft_isprint.o				\
		$(DIR)/ft_toupper.o				\
		$(DIR)/ft_tolower.o				\
		$(DIR)/ft_memalloc.o			\
		$(DIR)/ft_memdel.o				\
		$(DIR)/ft_strnew.o				\
		$(DIR)/ft_strdel.o				\
		$(DIR)/ft_strclr.o				\
		$(DIR)/ft_striter.o				\
		$(DIR)/ft_striteri.o			\
		$(DIR)/ft_strmap.o				\
		$(DIR)/ft_strmapi.o				\
		$(DIR)/ft_strequ.o				\
		$(DIR)/ft_strnequ.o				\
		$(DIR)/ft_strsub.o				\
		$(DIR)/ft_strjoin.o				\
		$(DIR)/ft_strtrim.o				\
		$(DIR)/ft_putchar_fd.o			\
		$(DIR)/ft_putstr_fd.o			\
		$(DIR)/ft_putendl_fd.o			\
		$(DIR)/ft_putnbr_fd.o			\
		$(DIR)/ft_strctrim.o			\
		$(DIR)/ft_strsplit.o			\
		$(DIR)/ft_count_words.o			\
		$(DIR)/ft_strlen_words.o		\
		$(DIR)/ft_strtrimsplit.o		\
		$(DIR)/ft_itoa.o				\
		$(DIR)/ft_intlen.o				\
		$(DIR)/ft_digit_abs.o			\
		$(DIR)/ft_lstnew.o				\
		$(DIR)/ft_lstdelone.o			\
		$(DIR)/ft_lstdel.o				\
		$(DIR)/ft_lstadd.o				\
		$(DIR)/ft_lstiter.o				\
		$(DIR)/ft_lstmap.o				\
		$(DIR)/ft_strsplit_lst.o		\
		$(DIR)/ft_find.o				\
		$(DIR)/ft_strcspn.o				\
		$(DIR)/ft_sqrt.o				\
		$(DIR)/ft_sq.o					\
		$(DIR)/ft_occur.o				\
		$(DIR)/ft_stractrim.o			\
		$(DIR)/ft_strncdelete.o			\
		$(DIR)/ft_strmap_display.o 		\
		$(DIR)/ft_error.o				\
		$(DIR)/ft_mod.o					\
		$(DIR)/ft_swap.o				\
		$(DIR)/get_next_line.o			\
		$(DIR)/ft_atoi_hexa.o			\
		$(DIR)/ft_abs.o					\
		$(DIR)/ft_deg_to_rad.o			\
		$(DIR)/ft_average.o 			\
		$(DIR)/ft_exit.o 				\
		$(DIR)/ft_hex_color_complete.o 	\
		$(DIR)/ft_digit_hex_to_int.o 	\
		$(DIR)/ft_color_average.o 		\
		$(DIR)/ft_color_hex_to_rgb.o 	\
		$(DIR)/ft_color_rgb_to_hex.o 	\
		$(DIR)/ft_splitdel.o 			\
		$(DIR)/ft_cplx_modul_2.o 		\
		$(DIR)/ft_cplx_modul.o 			\
		$(DIR)/ft_cplx_mult.o 			\
		$(DIR)/ft_cplx_pow.o 			\
		$(DIR)/ft_cplx_add.o 			\
		$(DIR)/ft_cplx_remove.o 		\
		$(DIR)/ft_cplx_cos.o 			\
		$(DIR)/ft_cplx_sin.o 			\
		$(DIR)/ft_cplx_cosh.o 			\
		$(DIR)/ft_cplx_sinh.o 			\
		$(DIR)/ft_cplx_div.o 			\
		$(DIR)/ft_cplx_ln.o 			\
		$(DIR)/ft_cplx_exp.o 			\
		$(DIR)/ft_make_cplx.o 			\
		$(DIR)/ft_cplx_discriminant.o

all: $(NAME)

ERASE	= \033[2K\r
BLUE	= \033[36m
WHITE	= \033[37m
END		= \033[0m
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m

$(NAME): $(DIR) $(FILES)
	@ar rc $(NAME) $(FILES)
	@ranlib $(NAME)
	@rm -rf $(INCLUDES).gch
	@rm -rf $(NAME).dSYM
	@rm -rf .vscode
	@printf "$(ERASE)$(BLUE)> $(NAME): $(GREEN) success !$(END)"
	@printf "\n"

$(DIR)/%.o: $(SOURCES)/%.c $(INCLUDES)
	@cd $(DIR) ; gcc $(FLAGS) -I ../$(INCLUDES) -c ../$<
	@printf "$(ERASE)$(BLUE)> Compiling: $(WHITE)$<$(END)"

$(DIR):
	@mkdir $(DIR)

clean: supp
	@rm -rf $(DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

supp:
	@rm -rf $(INCLUDES).gch
	@rm -rf $(NAME).dSYM
	@rm -rf .vscode
