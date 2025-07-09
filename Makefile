# =============================== WOLF3D COLORS =============================== #
RESET		= \033[0m
BOLD		= \033[1m
UNDERLINE	= \033[4m

# Wolf3D style colors
DARK		= \033[38;5;236m
GRAY		= \033[38;5;244m
BLUE		= \033[38;5;27m
RED			= \033[38;5;160m
YELLOW		= \033[38;5;220m
WHITE		= \033[97m
CYAN		= \033[36m
GREEN = \033[38;5;46m

# ================================ VARIABLES ================================== #
NAME		= cub3D
CC			= gcc
CFLAGS		= -g3 -Wall -Wextra -Werror
INCLUDES	= -I./include -I./libft
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

LIBS		= -L$(LIBFT_DIR) -lft -lreadline $(MLX_FLAGS)

SRC_DIR		= src
PARSE_DIR = $(SRC_DIR)/parsing
RENDER_DIR	= $(SRC_DIR)/render

FILES = main.c \
        utils3.c \
        key.c \
        is_pressed.c \
        init.c \
        handle_events.c \
        free_n_destroy.c \
		init2.c

PARSE_FILES = check_cnf.c \
                check_path.c \
                fill_stash.c \
                final_map.c \
                utils.c \
                utils2.c \
                utils3.c \
                utils4.c \
				check_all.c \
				v_or_x.c

RENDER_FILES = render.c \
                raycasting.c \
                wall_rendering.c \
                texture_loader.c \
                player_movement.c \
                player_init.c \
                game_loop.c \
                events.c \
                color_utils.c \
                minimap.c \
                render_init.c \
                render_compat.c \
				rotate.c

SRCS		= $(addprefix $(SRC_DIR)/, $(FILES)) \
            $(addprefix $(PARSE_DIR)/, $(PARSE_FILES)) \
            $(addprefix $(RENDER_DIR)/, $(RENDER_FILES))
OBJ_DIR		= obj
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ================================== RULES =================================== #

all:
	@printf "$(GREEN)$(GREEN)"
	@printf "╔═════════════╗\n"
	@printf "║$(GREEN)$(RED)   ██████╗   $(GREEN)║\n"
	@printf "║$(GREEN)$(RED)  ██╔════╝   $(GREEN)║\n"
	@printf "║$(GREEN)$(RED)  ██║        $(GREEN)║\n"
	@printf "║$(GREEN)$(RED)  ██║        $(GREEN)║\n"
	@printf "║$(GREEN)$(RED)  ╚██████╗   $(GREEN)║\n"
	@printf "║$(GREEN)$(RED)   ╚═════╝   $(GREEN)║\n"
	@printf "║$(GREEN)$(BLUE)  ██     ██  $(GREEN)║\n"
	@printf "║$(GREEN)$(BLUE)  ██     ██  $(GREEN)║\n"
	@printf "║$(GREEN)$(BLUE)  ██     ██  $(GREEN)║\n"
	@printf "║$(GREEN)$(BLUE)  ██     ██  $(GREEN)║\n"
	@printf "║$(GREEN)$(BLUE)  ╚██████╔╝  $(GREEN)║\n"
	@printf "║$(GREEN)$(BLUE)   ╚═════╝   $(GREEN)║\n"
	@printf "║$(GREEN)$(YELLOW)   ██████╗   $(GREEN)║\n"
	@printf "║$(GREEN)$(YELLOW)   ██╔══██╗  $(GREEN)║\n"
	@printf "║$(GREEN)$(YELLOW)   ██████╔╝  $(GREEN)║\n"
	@printf "║$(GREEN)$(YELLOW)   ██╔══██╗  $(GREEN)║\n"
	@printf "║$(GREEN)$(YELLOW)   ██████╔╝  $(GREEN)║\n"
	@printf "║$(GREEN)$(YELLOW)   ╚═════╝   $(GREEN)║\n"
	@printf "║$(GREEN)$(CYAN)    ██████╗  $(GREEN)║\n"
	@printf "║$(GREEN)$(CYAN)   ╚════██╗  $(GREEN)║\n"
	@printf "║$(GREEN)$(CYAN)    █████╔╝  $(GREEN)║\n"
	@printf "║$(GREEN)$(CYAN)    ╚═══██╗  $(GREEN)║\n"
	@printf "║$(GREEN)$(CYAN)   ██████╔╝  $(GREEN)║\n"
	@printf "║$(GREEN)$(CYAN)   ╚═════╝   $(GREEN)║\n"
	@printf "║$(GREEN)$(WHITE)   ██████╗   $(GREEN)║\n"
	@printf "║$(GREEN)$(WHITE)   ██╔══██╗  $(GREEN)║\n"
	@printf "║$(GREEN)$(WHITE)   ██║  ██║  $(GREEN)║\n"
	@printf "║$(GREEN)$(WHITE)   ██║  ██║  $(GREEN)║\n"
	@printf "║$(GREEN)$(WHITE)   ██████╔╝  $(GREEN)║\n"
	@printf "║$(GREEN)$(WHITE)   ╚═════╝   $(GREEN)║\n"
	@printf "╚═════════════╝$(RESET)\n"
	@$(MAKE) $(MLX) $(LIBFT) $(NAME) --no-print-directory


$(MLX):
	@printf "$(BLUE)$(BOLD)📦 Building MiniLibX...$(RESET)\n"
	@$(MAKE) -C $(MLX_DIR) --no-print-directory > /dev/null
	@printf "$(GRAY)✅ MiniLibX compiled!$(RESET)\n"

$(NAME): $(OBJS)
	@printf "$(YELLOW)$(BOLD)🔗 Linking $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@printf "$(RED)$(BOLD)🚀 $(NAME) ready to play!$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(GRAY)⚙️  Compiling $(WHITE)$(notdir $<)$(RESET)$(GRAY)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@printf "$(BLUE)$(BOLD)📚 Building libft...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@printf "$(GRAY)✅ Libft compiled!$(RESET)\n"

clean:
	@printf "$(RED)$(BOLD)🧹 Cleaning object files...$(RESET)\n"
	@rm -rf $(OBJ_DIR)
	@printf "$(GRAY)✅ Clean completed!$(RESET)\n"

fclean: clean
	@printf "$(RED)$(BOLD)🗑️  Removing $(NAME)...$(RESET)\n"
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(MLX)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory
	@printf "$(GRAY)✅ Full clean completed!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re

# ================================== INFO ==================================== #
info:
	@printf "$(CYAN)$(BOLD)📋 Project Information:$(RESET)\n"
	@printf "$(WHITE)• Name: $(YELLOW)$(NAME)$(RESET)\n"
	@printf "$(WHITE)• Compiler: $(YELLOW)$(CC)$(RESET)\n"
	@printf "$(WHITE)• Flags: $(YELLOW)$(CFLAGS)$(RESET)\n"
	@printf "$(WHITE)• Sources: $(YELLOW)$(words $(SRCS)) files$(RESET)\n"
	@printf "$(WHITE)• Objects: $(YELLOW)$(OBJ_DIR)/$(RESET)\n"
	@printf "$(WHITE)• Libraries: $(YELLOW)libft, minilibx$(RESET)\n\n"

help:
	@printf "$(CYAN)$(BOLD)🆘 Available targets:$(RESET)\n"
	@printf "$(YELLOW)• all$(RESET)     - Compile the project\n"
	@printf "$(YELLOW)• clean$(RESET)   - Remove object files\n"
	@printf "$(YELLOW)• fclean$(RESET)  - Remove object files and executable\n"
	@printf "$(YELLOW)• re$(RESET)      - Recompile the project\n"
	@printf "$(YELLOW)• info$(RESET)    - Show project information\n"
	@printf "$(YELLOW)• help$(RESET)    - Show this help message\n\n"
