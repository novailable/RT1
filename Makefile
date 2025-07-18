#OS detection
UNAME := $(shell uname)

# Paths and Files
ifeq ($(UNAME), Darwin)
	MLX_PATH = ./mlx_metal
	MLX_LIB = $(MLX_PATH)/libmlx.dylib
	MLX_REPO = https://github.com/novailable/minilibx_metal.git
	MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework Metal -framework AppKit
else ifeq ($(UNAME), Linux)
	MLX_PATH = ./mlx
	MLX_LIB = $(MLX_PATH)/libmlx.a
	MLX_REPO = https://github.com/42Paris/minilibx-linux.git
	MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 
else
	$(error $(shell printf "\033[31mUnsupported OS: $(UNAME)\033[0m"))
endif

# Compiler
CC := cc

# Executable name
NAME := rt1

INCLUDES := -Iinc -Isrc/gnl

LIBFT_PATH := ./libft
LIBFT := $(LIBFT_PATH)/libft.a

CFLAGS := $(INCLUDES) #-Wall -Wextra -Werror 

SRC_DIR := src
SRCS := $(shell find $(SRC_DIR) -type f -name '*.c')
SRCS += main.c
OBJS := $(SRCS:.c=.o)

# Rules
all: $(NAME)
	 @echo "\033[32m[$(NAME) is ready for use]\033[0m"

$(NAME): $(MLX_LIB) $(OBJS) $(LIBFT)
	@echo "$(NAME) compiling..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_PATH) $(LIBFT) $(MLX_LIB) -lm -o $(NAME)

# Clone and compile the MiniLibX library
$(MLX_LIB):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		echo "\033[33m[Cloning MiniLibX...]\033[0m"; \
		git clone $(MLX_REPO) $(MLX_PATH); \
	fi
	@$(MAKE) -C $(MLX_PATH)

# Compile .o files
%.o: %.c
	@$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(LIBFT_PATH) -c $< -o $@

# Compile the libft library
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

# Clean object files
clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean
	@echo "$(NAME) cleaning..."
	@rm -f $(OBJS)
	@echo "\033[35m[Cleaned up]\033[0m"

# Clean object files and executable
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
ifeq ($(UNAME), Darwin)
	@$(MAKE) -C $(MLX_PATH) fclean
endif
	@echo "\033[35m[Fully cleaned up]\033[0m"

header: clean ${OBJS}
	@echo "$(NAME) compiling..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_PATH) $(LIBFT) $(MLX_LIB) -lm -o $(NAME)
	@echo "\033[32m[$(NAME) is ready for use]\033[0m"

# Recompile everything
re: fclean all

.PHONY: all clean fclean re header
