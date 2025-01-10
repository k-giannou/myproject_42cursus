# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 15:39:45 by kgiannou          #+#    #+#              #
#    Updated: 2025/01/09 11:42:38 by kgiannou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
FTPRINTF = libft/ft_printf/libftprintf.a

FLAGS = cc -Wall -Wextra -Werror -I./

SRC = push_swap.c \
       check_argc_argv.c \
       utils.c \
       utils2.c \
       stack.c \
       operations.c \
       operations2.c \
       sort.c \
       sort2.c \
       init_nodes.c \
       init_nodes_in_b.c

OBJECT = $(SRC:%.c=%.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJECT) $(LIBFT) $(FTPRINTF)
	$(FLAGS) $(OBJECT) $(LIBFT) $(FTPRINTF) -o $(NAME)
	@echo "\033[32m<<< Ready, start with ./push_swap "....." >>>\033[0m"

$(LIBFT):
	$(MAKE) -s -C ./libft

$(FTPRINTF):
	$(MAKE) -s -C ./libft/ft_printf

info:
	@echo "\033[35m<<< randon numbers: https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php >>>\033[0m\n"
	@echo "\033[35m<<< valgrind --leak-check=full ./push_swap ... >>>\033[0m\n"
	@echo "\033[35m<<< checker: ARG=...; ./push_swap ARG | wc -l >>>\033[0m\n"
	@echo "\033[35m<<< checker: ARG=...; ./push_swap ARG | ./checker_linux ARG >>>\033[0m\n"

clean:
	@make clean -s -C ./libft
	@make clean -s -C ./libft/ft_printf
	@rm -rf $(OBJECT)

fclean: clean
	@make fclean -s -C ./libft
	@make fclean -s -C ./libft/ft_printf
	@rm -rf $(NAME)
	@echo "\033[32m<<< It has been cleaned successfully >>>\033[0m"

re: fclean all
