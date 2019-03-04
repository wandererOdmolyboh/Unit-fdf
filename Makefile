NAME=fillit

FLAGS=-Wall -Wextra -Werror

SRCS_NAME=ft_isalpha.c ft_putchar.c ft_strjoin.c ft_strlen.c try_add.c\
ft_strsub.c ft_putstr.c string.c output.c recursia.c ft_bzero.c check_termino.c\
ft_strdup.c ft_strcpy.c ft_strcat.c main.c error_output.c clear_output.c rename_line.c\
print_map.c ft_memset.c

CC=gcc -g

INC_PATH=./

OBJ_PATH=./objects/

SRCS=$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJ=$(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all:
	$(NAME)

$(NAME):$(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o:$(SRCS_PATH)%.c
	@mkdir -p ./objects
	@$(CC) -c $(FLAGS) -I $(INC_PATH) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -rf $(NAME)

re:	fclean all

.PHONY	: all, clean, fclean, re