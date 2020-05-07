# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: home <home@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/06 17:51:42 by home              #+#    #+#              #
#    Updated: 2020/05/06 23:49:08 by home             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_g2
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/

SRCS_DIR = srcs/
BINARY_DIR = bin/

DEBUG_NAMES = \
	test \

SRCS_NAMES = \
	main \

FILE_NAMES = \
	$(SRCS_NAMES) \
	$(addprefix debug/, $(DEBUG_NAMES))

OBJ_NAMES = \
	$(addsuffix .o, $(SRCS_NAMES)) \
	$(addsuffix .o, $(DEBUG_NAMES)) \

SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR), $(FILE_NAMES)))

T_OBJS = $(addsuffix .o, $(addprefix $(SRCS_DIR), $(FILE_NAMES)))

OBJS = $(addprefix $(BINARY_DIR), $(OBJ_NAMES))

all: $(NAME)

$(NAME): $(OBJ_NAMES)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

$(OBJS): $(OBJ_NAMES) $(BINARY_DIR)
	gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
	mv $(OBJ_NAMES) $(BINARY_DIR)

$(OBJ_NAMES):
	echo $(SRCS)
	touch $(BINARY_DIR)$@

$(BINARY_DIR):
	mkdir $(BINARY_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)


