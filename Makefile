# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/13 11:56:39 by qpupier      #+#   ##    ##    #+#        #
#    Updated: 2019/06/19 22:07:31 by qpupier     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRC_PATH = sources
SRC_NAME = 	main.c 								\
			display.c 							\
			init/init.c 						\
			init/init_fractals_1.c 				\
			init/init_fractals_2.c 				\
			init/init_buddha_refresh.c 			\
			algo/algo_colors.c 					\
			algo/fractals.c 					\
			algo/fern.c 						\
			algo/newton_fern.c 					\
			algo/pyth_tree.c 					\
			algo/sierpinski_koch.c 				\
			params/legend.c 					\
			params/choice_legend.c 				\
			params/choice_legend2.c 			\
			params/choice_legend3_loading.c 	\
			params/params_infos.c 				\
			params/params_down_left.c 			\
			params/params_down_squares_help.c 	\
			events/event.c 						\
			events/event_iterations.c 			\
			events/event_moves_choices.c 		\
			events/event_zoom_menu.c 			\
			events/event_choice.c 				\
			events/event_changes.c
SRC_SUP = {init,algo,params,events}
OBJ_PATH = .objects
INC_PATH = includes
CPPFLAGS = -I $(INC_PATH)
LDFLAGS = -L libft
LDLIBS = libft/libft.a
MINILIBX = -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL 	\
		-framework AppKit
OPTI_FLAGS = -O3
NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

ERASE = \033[2K\r
BLUE = \033[36m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
END = \033[0m

.PHONY: all, clean, fclean, re

all: lib $(NAME)
	@printf "$(BLUE)> $(NAME) : $(YELLOW)Project ready !$(END)\n"

$(NAME): $(OBJ)
	@$(CC) $(LDFLAGS) $(MINILIBX) $(OPTI_FLAGS) $(LDLIBS) $^ -o $@
	@printf "$(ERASE)$(BLUE)> $@ : $(GREEN)Success !$(END)\n\n"

lib:
	@make -C libft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)/$(SRC_SUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"
clean:
	@make -C libft clean
	@rm -rf $(OBJ_PATH)
	@printf "$(BLUE)> Deleted : $(RED)$(OBJ_PATH)$(END)\n"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@printf "$(BLUE)> Deleted : $(RED)$(NAME)$(END)\n"

re: fclean all

norme:
	@norminette $(SRC) $(INC_PATH)
