##########  VARS CONFIG
NAME          = libft.a
HEADER_FILE   = libft.h
CC            = gcc
FLAGS         = -Wall -Wextra -Werror -g -fsanitize=address
AR            = ar rcs
OBJ_DIR       = ./obj
GNL_DIR		  = get_next_line
GNL_HEADER    = $(GNL_DIR)/get_next_line.h
##########  VARS FILES
SRC_FILES	=	ft_atoi.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c	\
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memchr.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strcmp.c \

SRC_BNS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
                ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJECTS       = $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(SRC_FILES)))
OBJECTS_BNS   = $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(SRC_BNS_FILES)))

GNL_FILES	  = get_next_line.c get_next_line_utils.c
GNL_FILES     := $(addprefix $(GNL_DIR)/, $(GNL_FILES))
GNL_OBJECTS   := $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(GNL_FILES)))
##########  RULES
all:  $(NAME)
		

prueba:
	@echo $(GNL_FILES)
	@echo $(GNL_OBJECTS)

$(NAME): $(OBJECTS)  $(HEADER_FILE) Makefile
	@$(AR) $(NAME) $(OBJECTS)
	@echo "📚 Library created!"

bonus: $(OBJECTS) $(OBJECTS_BNS) $(HEADER_FILE) $(GNL_FILES) $(GNL_OBJECTS) Makefile
	@$(AR) $(NAME) $(OBJECTS) $(OBJECTS_BNS) $(GNL_OBJECTS)
	@echo "📚 Libft with bonus & GNL created!"
	@touch bonus

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/$(GNL_DIR)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "🛠  $(@F:.o=) object created!"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧼 Removed object files from libft!"

fclean: clean
	@rm -f $(NAME) bonus
	@echo "🧼 Removed $(NAME) file!"

re: fclean all

.PHONY: all clean fclean re