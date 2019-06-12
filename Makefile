# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/13 11:56:39 by qpupier      #+#   ##    ##    #+#        #
#    Updated: 2019/06/12 14:46:49 by qpupier     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fractol
INCLUDES = includes/*.h
DIR = objects
SOURCES = sources
MINILIBX = -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror -O3 -ggdb
FILES = $(DIR)/main.o 													\
		$(DIR)/event.o 													\
		$(DIR)/pyth_tree.o 												\
		$(DIR)/legend.o 												\
		$(DIR)/init.o 													\
		$(DIR)/fern.o 													\
		$(DIR)/sierpinsky_koch.o 										\
		$(DIR)/newton.o 												\
		$(DIR)/fractals.o 												\
		$(DIR)/lib.o 													\
		$(DIR)/choice_legend.o 											\
		$(DIR)/choice_legend2.o 										\
		$(DIR)/choice_legend3.o 										\
		$(DIR)/params.o 												\
		$(DIR)/colors.o 												\
		$(DIR)/algo.o

all: $(NAME)

ERASE	= \033[2K\r
BLUE	= \033[36m
WHITE	= \033[37m
END		= \033[0m
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m

$(NAME): $(DIR) $(FILES)
	@make -C libft
	@gcc $(FLAGS) $(MINILIBX) libft/libft.a $(FILES) -o $(NAME)
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
	@make clean -C libft
	@rm -rf $(DIR)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

supp:
	@rm -rf $(INCLUDES).gch
	@rm -rf $(NAME).dSYM
	@rm -rf .vscode
