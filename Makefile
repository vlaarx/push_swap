# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: screight <screight@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/26 21:15:02 by screight          #+#    #+#              #
#    Updated: 2019/11/14 16:47:32 by screight         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re all

PUSH = push_swap
CHECK = checker

LIBNAME = libft.a
LIBDIR = libftprintf/libft
LIBPRNAME = libftprintf.a
LIBPRDIR = libftprintf/
FLAGS = -Wall -Werror -Wextra
HEADER = -I headers/ -I libftprintf/headers -I libftprintf/libft/headers

OBJ_DIR = objectives/
PUSH_DIR = sources/push_swap/
CHECK_DIR = sources/checker/
COMMON_DIR = sources/shared/

PUSH_SRC =	push_swap.c algorithm.c find_index.c minialg.c split_stack.c get_to_top.c

CHECK_SRC = checker.c visualise.c do_operations.c

SHARE_SRC =	 handle_stacks.c operations.c shared.c validation.c put_color.c

PUSH_OBJS 	= $(addprefix $(OBJ_DIR), $(PUSH_SRC:.c=.o))
CHECK_OBJS 	= $(addprefix $(OBJ_DIR), $(CHECK_SRC:.c=.o))
SHARE_OBJS 	= $(addprefix $(OBJ_DIR), $(SHARE_SRC:.c=.o))

all: $(PUSH) $(CHECK)

$(PUSH): $(PUSH_OBJS) $(SHARE_OBJS)
	@make -C $(LIBPRDIR) --no-print-directory
	@echo "compiling push_swap"
	@gcc $(FLAGS) $(HEADER) $(PUSH_OBJS) $(SHARE_OBJS) -L./libftprintf/ -lftprintf -o push_swap
	@echo "done!"

$(CHECK): $(CHECK_OBJS) $(SHARE_OBJS)
	@echo "compiling checker"
	@gcc $(FLAGS) $(HEADER) $(CHECK_OBJS) $(SHARE_OBJS) -L./libftprintf/ -lftprintf -o checker
	@echo "done!"

$(PUSH_OBJS) :	$(OBJ_DIR)%.o: $(PUSH_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@ $(HEADER)

$(CHECK_OBJS) :	$(OBJ_DIR)%.o: $(CHECK_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@ $(HEADER)

$(SHARE_OBJS) :	$(OBJ_DIR)%.o: $(COMMON_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@ $(HEADER)

clean:
			@/bin/rm -f $(PUSH_OBJS) $(CHECK_OBJS) $(SHARE_OBJS)
			@rm -rf $(OBJ_DIR)
			@make clean -C $(LIBPRDIR) --no-print-directory

fclean: 	clean
			@/bin/rm -f $(PUSH) $(CHECK)
			@make fclean -C $(LIBPRDIR) --no-print-directory

re: 		fclean all