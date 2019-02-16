NAME :=		fdf

INC_PATH :=	includes/
MLX_PATH :=	minilibx_macos/
LABAF_PATH :=libft/
OBJ_PATH :=	.obj/

CC :=		clang
CFLAGS :=	-g #-Wall -Werror -Wextra
IFLAGS :=	 -I $(MLX_PATH) -I $(LABAF_PATH)
LFLAGS :=	-L $(MLX_PATH) -L $(LABAF_PATH)
LFLAGS +=	-framework OpenGL -framework AppKit
LFLAGS +=	-lm -lmlx 

HDRS :=		fdf.h $(MLX_PATH)mlx.h $(LABAF_PATH)libft.h
FILES :=	error_output.c main.c validator.c 
LIB :=		$(MLX_PATH)libmlx.a $(LABAF_PATH)libft.h

SRCS :=		$(FILES)
OBJS :=		$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))


all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)
$(LIB): 
	make -C $(MLX_PATH)
	make -C $(LIBAF_PATH)


$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@


.PHONY: all clean fclean re mclean mfclean mre
