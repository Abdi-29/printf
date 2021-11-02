NAME = libftprintf.a

SRC = hexadecimal.c ft_printf.c dec_c_str.c ft_itoa_unsigned.c
INCLUDE = -Ilibft
OBJ_FILES = $(SRC:.c=.o)

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

$(NAME): $(OBJ_FILES)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ_FILES)
	@echo "$(RED)Done $(GREEN)COM$(YELLOW)PI$(BLUE)LING $(PINK)LIBFT$(RESET) :)"


%.o: %.c
	$(CC) -c $(FLAGS) $(INCLUDE) -o $@ $<
	@echo "$(RED)COMPILING $(GREEN)PLEASE $(YELLOW)GI$(BLUE)VE $(PINK)IT A MOMENT$(RESET) :)"

clean:
	rm  -f $(OBJ_FILES)
	@echo "$(RED)CLEANING $(GREEN)IN $(YELLOW)PROCE$(BLUE)SS $(RESET) :)"

fclean: clean
	rm -f ${NAME}
	@echo "$(GREEN)ALL CLEANED $(RESET) :)"

re: fclean all

.PHONY: all clean fclean re
