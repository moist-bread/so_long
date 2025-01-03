# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2025/01/02 13:36:04 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		\
		ft_printf.c ft_conversions.c \
		\
		get_next_line.c get_next_line_utils.c
		
LST	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
		ft_lstlast.c ft_lstnew.c ft_lstsize.c \
		ft_lstmap.c

OBJ_DIR = obj

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(LST:.c=.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(M_COMOBJS)
	$(M_ARC)
	@ar rcs $(NAME) $(OBJS)

clean:
	$(M_REMOBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	$(M_REM)
	@rm -rf $(NAME)

re:	fclean all
	@echo "Re-Done!!"

bonus: $(OBJS) $(BONUS_OBJS)
	$(M_COMOBJS)
	$(M_COMBONUS)
	$(M_ARCBONUS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS) 

.PHONY: all clean fclean re bonus

# ★☆★-‵,┊( COSMETICS )┊.´-★☆★

#-‵,┊ normal colors
DEF	=	\e[0;39m
GRY	=	\e[0;30m
BLU	=	\e[0;34m
GRN	=	\e[0;32m
YEL =	\e[0;33m

#-‵,┊ bold colors
BYEL	=	\e[1;33m

#-‵,┊ background colors
YELB	=	\e[43m

#-‵,┊ names
PH = placeholder

#-‵,┊ messages
M_COMOBJS = @echo "$(GRY)-->┊$(GRN)  Compiling: $(BYEL) $(NAME)/objs $(GRY)$(DEF)"
M_COMBONUS = @echo "$(GRY)-->┊$(GRN)  Compiling: $(BYEL) $(NAME) bonus objs $(GRY)$(DEF)"
M_ARC = @echo "$(GRY)-->┊$(YEL)  Archiving: $(DEF)$(YELB) $(NAME) $(GRY)$(DEF)"
M_ARCBONUS = @echo "$(GRY)-->┊$(YEL)  Archiving: $(DEF)$(YELB) $(NAME) bonus $(GRY)$(DEF)"
M_REMOBJS = @echo "$(GRY)-->┊$(BLU)  Removing: $(BYEL) $(NAME)/objs $(GRY)$(DEF)"
M_REM = @echo "$(GRY)-->┊$(BLU)  Removing: $(DEF)$(YELB) $(NAME) $(GRY)$(DEF)"

#-‵,┊ tester
test:
	$(M_COMOBJS)
	$(M_COM)
	$(M_COMBONUS)
	$(M_ARC)
	$(M_ARCBONUS)
	$(M_REMOBJS)
	$(M_REM)