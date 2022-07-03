NAME = libftprintf.a

SRC = hexadecimal.c ft_printf.c dec_c_str.c ft_itoa_unsigned.c main.c
INCLUDE = -I include
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJ= $(SRC:.c=.o)
CC = gcc
OBJ_DIR = obj

# COLORS
PINK    = \x1b[35m
BLUE    = \x1b[34m
YELLOW  = \x1b[33m
GREEN   = \x1b[32m
RED     = \x1b[31m
MAGENTA = \x1b[35m

RESET   = \x1b[0m

FLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(RED)Done $(GREEN)COM$(YELLOW)PI$(BLUE)LING $(PINK)LIBFT$(RESET) :)"


%.o: %.c
	@mkdir -p $(dir $@)
	gcc $(FLAGS) $(INCLUDE) -c -o $@ $<
	@echo "$(RED)COMPILING $(GREEN)PLEASE $(YELLOW)GI$(BLUE)VE $(PINK)IT A MOMENT$(RESET) :)"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm  -f $(OBJ_FILES)
	@echo "$(RED)CLEANING $(GREEN)IN $(YELLOW)PROCE$(BLUE)SS $(RESET) :)"

fclean: clean
	$(MAKE) -C $(LIBFT_DIR)/ fclean
	rm -rf $(OBJ)
	@echo "$(GREEN)ALL CLEANED $(RESET) :)"

re: fclean all

.PHONY: all clean fclean re
