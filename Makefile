# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2025/01/13 14:22:46 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ★☆★-‵,┊( NAMES )┊.´-★☆★
NAME = so_long
LIBFT = ./inc/libft/libft.a
MLX = ./inc/minilibx_linux/libmlx.a


# ★☆★-‵,┊( TO DO )┊.´-★☆★
#	windows


# ★☆★-‵,┊( SOURCES AND OBJS )┊.´-★☆★
MAIN    =   so_long_main.c 
SOURCES =	map_parsing.c make_map.c map_full_check.c test.c set_game.c

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(SOURCES))
MAIN_SRC = $(addprefix $(SRCS_DIR)/, $(MAIN))

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))
OBJS_MAIN = $(addprefix $(OBJS_DIR)/, $(MAIN:.c=.o))


# ★☆★-‵,┊( COMMANDS AND FLAGS )┊.´-★☆★
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./inc/minilibx_linux -lmlx_Linux -lX11 -lXext
#-Lminilibx-linux   -lmlx_Linux -lX11 -lXext
#-L ./libs/minilibx -lmlx -Ilmlx -lXext -lX11
#-L/usr/lib         -Imlx_linux -lXext -lX11 -lm -lz


# ★☆★-‵,┊( MAIN RULES )┊.´-★☆★
all: $(NAME)

$(NAME): $(OBJS_MAIN) $(OBJS) $(LIBFT) $(MLX)
	$(M_COM)
	@$(CC) $(CFLAGS) $(OBJS_MAIN) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@make -C ./inc/libft -s

$(MLX):
	$(M_COMMLXOBJS)
	@make -C ./inc/minilibx_linux -s
	$(M_ARCMLX)

exe1: all
	./so_long map1.ber

exe2: all
	./so_long map2.ber

exe3: all
	./so_long map3.ber

# ★☆★-‵,┊( STANDARD RULES )┊.´-★☆★
clean:
	@make clean -C ./inc/libft -s
	$(M_REMMLXOBJS)
	@make clean -C ./inc/minilibx_linux -s
	$(M_REMOBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	$(M_REMLIB)
	@rm -rf $(LIBFT)
	$(M_REMMLX)
	$(M_REM)
	@rm -rf $(NAME)

re:	fclean all
	@echo "Re-Done!!"

.PHONY: all clean fclean re bonus


# ★☆★-‵,┊( COSMETICS )┊.´-★☆★

#-‵,┊ normal colors
DEF	=	\e[0;39m
GRY	=	\e[0;30m
BLU	=	\e[0;34m
GRN	=	\e[0;32m
YEL =	\e[0;33m

#-‵,┊ bold colors
BCYN	=	\e[1;36m
BHMAG	=	\e[1;95m
#-‵,┊ background colors
CYNB	=	\e[46m
YELB	=	\e[43m
MAGHB	=	\e[0;105m

#-‵,┊ names
PH = placeholder

#-‵,┊ messages
M_COMOBJS = @echo "$(GRY)-->┊$(GRN)  Compiling: $(BCYN) $(NAME)/objs $(GRY)$(DEF)"
M_COMLIB = @echo "$(GRY)-->┊$(GRN)  Compiling: $(DEF)$(YELB) libft.a $(GRY)$(DEF)"
M_COM = @echo "$(GRY)-->┊$(GRN)  Compiling: $(DEF)$(CYNB) $(NAME) $(GRY)$(DEF)"
M_COMBONUS = @echo "$(GRY)-->┊$(GRN)  Compiling: $(DEF)$(CYNB) $(NAME)/bonus $(BONUS) $(GRY)$(DEF)"
M_REMOBJS = @echo "$(GRY)-->┊$(BLU)  Removing: $(BCYN) $(NAME)/objs $(GRY)$(DEF)"
M_REMLIB = @echo "$(GRY)-->┊$(BLU)  Removing: $(DEF)$(YELB) libft.a $(GRY)$(DEF)"
M_REM = @echo "$(GRY)-->┊$(BLU)  Removing: $(DEF)$(CYNB) $(NAME) $(GRY)$(DEF)"
M_COMMLXOBJS = @echo "$(GRY)-->┊$(GRN)  Compiling: $(BHMAG) libmlx.a/objs $(GRY)$(DEF)"
M_ARCMLX = @echo "$(GRY)-->┊$(YEL)  Archiving: $(DEF)$(MAGHB) libmlx.a $(GRY)$(DEF)"
M_REMMLX = @echo "$(GRY)-->┊$(BLU)  Removing: $(DEF)$(MAGHB) libmlx.a $(GRY)$(DEF)"
M_REMMLXOBJS = @echo "$(GRY)-->┊$(BLU)  Removing: $(BHMAG) libmlx.a/objs $(GRY)$(DEF)"


#-‵,┊ tester
test:
	$(M_COMOBJS)
	$(M_COMLIB)
	$(M_COM)
	$(M_COMBONUS)
	$(M_REMOBJS)
	$(M_REMLIB)
	$(M_REM)
	$(M_COMMLXOBJS)
	$(M_ARCMLX)
	$(M_REMMLX)
	$(M_REMMLXOBJS)	