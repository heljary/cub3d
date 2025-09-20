# Project name
NAME		= cub3D

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

# Directories
SRCDIR		= .
OBJDIR		= obj
INCDIR		= include

# Source files
SRCFILES	= main.c \
			  raycasting.c

# Object files
OBJS		= $(SRCFILES:%.c=$(OBJDIR)/%.o)

# MLX
MLX_DIR		= minilibx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Includes
INCLUDES	= -I$(INCDIR) -I$(MLX_DIR)

# Rules
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