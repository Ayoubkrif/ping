# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 12:32:52 by aykrifa           #+#    #+#              #
#                                                                              #
# **************************************************************************** #

############################   CONFIGURATION ZONE   #############################
# Directorie in which src will be found
SRC_DIR   = sources

# Directorie in which obj will be built
OBJ_DIR   = build

# Source files listing
SRC_FILES = \
			main.c \
			check_flags.c \

# Include directories listing
INC_DIR = \
	includes \

NAME		= ft_ping
CC			= cc
PFLAGS		=
CFLAGS 		= -Wall -Wextra -Werror -MMD -MP -g3
LFLAGS		= -lcap
##################################################################################

SOURCES = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
INCLUDES	= $(addprefix -I, $(INC_DIR))

OBJS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)
.PHONY: all

# LINK
$(NAME): $(OBJS)
	$(CC) $(OBJS) \
		$(LFLAGS) \
		-o $@

#compilation
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $(INCLUDES) \
		$< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)
.PHONY: clean

fclean: clean
	rm -f $(NAME)
.PHONY: fclean

re: fclean
	make all
.PHONY: re

bear:
	bear -- make re
.PHONY: bear
