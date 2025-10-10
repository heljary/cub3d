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

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ $(NAME) compiled!"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@make -C $(MLX_DIR) clean
	@echo "🧹 Object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "🗑️ Executable removed"

re: fclean all

.PHONY: all clean fclean re