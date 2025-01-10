# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/22 16:33:40 by kgiannou          #+#    #+#              #
#    Updated: 2024/12/25 13:22:46 by kgiannou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
FTPRINTF = libft/ft_printf/libftprintf.a

FLAGS = cc -Wall -Wextra -Werror

SRCC = client.c
SRCC_BONUS = client_bonus.c
SRCS = server.c
SRCS_BONUS = server_bonus.c
SERVER = server
SERVER_BONUS = server_bonus
CLIENT = client
CLIENT_BONUS = client_bonus

OBJECTC = $(SRCC:.c=.o)
OBJECTC_BONUS = $(SRCC_BONUS:.c=.o)
OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = $(SERVER) $(CLIENT)

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTC) $(LIBFT) $(FTPRINTF)
	$(FLAGS) $(OBJECTS) $(LIBFT) $(FTPRINTF) -o $(SERVER)
	$(FLAGS) $(OBJECTC) $(LIBFT) $(FTPRINTF) -o $(CLIENT)
	@echo "\033[32m<<< Server and Client are ready, start with ./server >>>\033[0m"

$(LIBFT):
	$(MAKE) -s -C ./libft

$(FTPRINTF):
	$(MAKE) -s -C ./libft/ft_printf

bonus: $(OBJECTS_BONUS) $(OBJECTC_BONUS) $(LIBFT) $(FTPRINTF)
	$(FLAGS) $(OBJECTS_BONUS) $(LIBFT) $(FTPRINTF) -o $(SERVER)
	$(FLAGS) $(OBJECTC_BONUS) $(LIBFT) $(FTPRINTF) -o $(CLIENT)
	@echo "\033[32m<<< Server and Client BONUS are ready, start with ./server >>>\033[0m"
	@echo "\033[33m<<< You can use emojis like 🥰🤬😂🙈🙉🙊🐒🐔🐧🐦🐤🐣🐥🦆🦅🦉🦇🐺🐗🐴🦄🐝🪱🐛🦋🐌🐞🐜🪰🪲🪳🦟🦗🕷🕸🦂🐢🦎🦖🦕🐙🦑🦐🦞🦀🪼🪸🐡🐠🐟🐬🐳🐋🦈🐊🐅🐆🦓🫏🦍🦧🦣🐘😓 >>>\033[0m"
	@echo "\033[35m<<<Make a loop with -> while true; do ./client ........ $(python3 -c 'import random, string; emojis = "😀😁😂🤣😃😄😅😆😉😊😋😎😍😘🥰🤗🤔🤨🙃🙂🤩🥳😜😝😛😌😏🙄😒😔😢😭"; chars = string.ascii_letters + string.digits + emojis; print("".join(random.choices(chars, k=random.randint(10, 100))))'); done >>>\033[0m"

clean:
	@make clean -s -C ./libft
	@make clean -s -C ./libft/ft_printf
	@rm -rf $(OBJECTS) $(OBJECTC) $(OBJECTS_BONUS) $(OBJECTC_BONUS)

fclean: clean
	@make fclean -s -C ./libft
	@make fclean -s -C ./libft/ft_printf
	@rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "\033[32m<<< Server and Client have been cleaned successfully >>>\033[0m"

re: fclean all
