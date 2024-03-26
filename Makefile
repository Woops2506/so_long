
NAME = so_long

SRC_DIR := src
OBJ_DIR := obj

SOURCES = $(wildcard $(SRC_DIR)/*.c)

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

CFLAGS = -Wall -Werror -Wextra

LIBDIR = my_libs
LIB = mylibs.a

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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(MLX_LIB) $(LIBDIR)/$(LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) -L$(LIBDIR)/libft -lft -L$(LIBDIR)/ft_printf ./$(LIBDIR)/ft_printf/libftprintf.a -L$(LIBDIR)/get_next_line ./$(LIBDIR)/get_next_line/gnl.a

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(LIBDIR)/$(LIB):
	$(MAKE) -C $(LIBDIR)
	cp $(LIBDIR)/$(LIB) .

clean:
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBDIR) clean
	rm -f $(OBJS)
	rm -r -f $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	rm -f $(NAME)
# $(MAKE) -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
