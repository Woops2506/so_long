
NAME = so_long

SRC_DIR := Source
OBJ_DIR := obj

SOURCES = $(wildcard $(SRC_DIR)/*.c)
#so_long.c error.c freemem.c solve_level.c solve_level2.c get_values.c level_check.c start.c keyhandling.c\
	image_handling.c game_handling.c paths.c movement_handling.c
OBJS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -Wall -Werror -Wextra

LIB_FLAGS = libft/libft.a

LIB_DIR = ./libft
LIB_LIB = $(LIB_DIR)/libft.a

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif
 
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: $(MLX_LIB) $(LIB_LIB) $(NAME)
 
#.c.o:
#	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIB_FLAGS)
 
$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIB_LIB):
	@make -C $(LIB_DIR)

clean:
	make clean -C $(MLX_DIR)
	make clean -C $(LIB_DIR)
	rm -f $(OBJS)
	rm -r $(OBJ_DIR)

fclean: clean
	make -C fclean $(LIB_DIR)
	rm -f $(NAME)
# make -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
