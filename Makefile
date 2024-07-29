# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 23:21:11 by tfiguero          #+#    #+#              #
#    Updated: 2024/07/29 23:48:17 by tfiguero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########	VARS CONFIG
NAME			= push_swap
BONUS_NAME		= checker
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address
LDFLAGS			= -L./lib/libft -lft
RM				= rm -f
MKDIR_P			= mkdir -p

##########	PATHS
SRCS_PATH		= ./src
OBJS_PATH		= ./objs
INCLUDE_PATH	= ./lib

##########	SOURCE FILES
SRC_FILES		= index_atoi.c movements.c\
				  error.c chunker.c 3_to_5.c aux_func.c \
				  movements2.c 
SRCS			= $(addprefix $(SRCS_PATH)/, $(SRC_FILES))
OBJECTS			= $(SRC_FILES:%.c=$(OBJS_PATH)/%.o)

MAIN_SRC		= main.c
BONUS_SRC		= checker_bonus.c 

##########	RULES
all: $(NAME)

$(NAME): $(OBJECTS) $(MAIN_SRC:%.c=$(OBJS_PATH)/%.o) | libft
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "🔅 $@ is ready to work!"

bonus: $(OBJECTS) $(BONUS_SRC:%.c=$(OBJS_PATH)/%.o) | libft
	@$(CC) $(CFLAGS) $^ -o $(BONUS_NAME) $(LDFLAGS)
	@echo "🔅 $@ is ready to work!"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_PATH)

libft:
	@$(MAKE) -C lib/libft --no-print-directory

$(OBJS_PATH):
	@$(MKDIR_P) $(OBJS_PATH)

clean:
	@$(RM) -r $(OBJS_PATH)
	@echo "🧼 Removed object files."

fclean: clean
	@$(MAKE) -C lib/libft fclean  --no-print-directory
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "🛁 Removed executables."

re: fclean all


# 5 nums max 12 moves
# 100 max 700
# 500 max 5500
test:
	@NUM_QTY=500; \
    MAX_MOVES=5500; \
    ARG=$$(shuf -i 0-5000000 -n $$NUM_QTY); \
    RESULT=$$(./$(NAME) $$ARG | ./checker_linux $$ARG); \
    if [ "$$RESULT" = "OK" ]; then \
        COLOR="\033[0;32m"; \
    else \
        COLOR="\033[0;31m"; \
    fi; \
    echo "󱝿⚙️ Checker verify: $$COLOR$$RESULT\033[0m"; \
    echo -n "🔢 Num of moves:    "; \
    NUM_MOVES=$$(./$(NAME) $$ARG | wc -l); \
    if [ $$NUM_MOVES -lt $$MAX_MOVES ]; then \
        COLOR="\033[0;32m"; \
    else \
        COLOR="\033[0;31m"; \
    fi; \
    echo "$$COLOR$$NUM_MOVES\033[0m"
#fish: for i in (seq 1 10); make test; end
#bash: for i in {1..10}; do make test; done

.PHONY: all clean fclean re libft test