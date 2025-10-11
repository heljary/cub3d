NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
SRCDIR		= .
OBJDIR		= obj
INCDIR		= include

SRCFILES	= main.c raycasting.c \
			
OBJS		= $(SRCFILES:%.c=$(OBJDIR)/%.o)

MLX_DIR		= minilibx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

INCLUDES	= -I$(INCDIR) -I$(MLX_DIR)
NAME = cub3d
SRC = main.c draw_background.c draw_minimap.c hooks.c movement.c raycasting.c mlx_utils.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
MLX = minilibx/libmlx.a -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : re clean fclean