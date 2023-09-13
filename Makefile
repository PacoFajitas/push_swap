# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 20:46:00 by tfiguero          #+#    #+#              #
#    Updated: 2023/09/13 21:30:05 by tfiguero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = lib/push_swap.h

SRC = 3_to_5.c \
       movements.c \
       movements2.c \
       push_swap.c \
	   indexer.c \
	   error.c \
	   chunker.c \

OBJS	= 	$(SRC:.c=.o)

CC	= 	cc
RM	= 	rm -f
FLAGS	= 	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):: ${OBJS} ${HEADER}
	$(CC) $(FLAGS) $(OBJS) -o ${NAME}

$(NAME):: 
	@echo "Hello, $(NAME) already compiled 🌚"
	
%.o:%.c $(HEADER) Makefile
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}



fclean: clean
	$(RM) $(NAME) 

clean:
	$(RM) $(OBJS) 

re: fclean all

.PHONY: all clean fclean re .c.o