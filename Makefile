NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit

SRCS = ./cub.c \
	./cub_utils.c \
	./moves/moves_utils.c \
	./moves/moves.c \
	./scene/scene.c \
	./keys/mouse.c \
	./keys/arrows.c \
	./init/init_2.c \
	./init/init.c \
	./minimap/minimap.c \
	./minimap/minimap_utils.c \
	./minimap/minimap_utils2.c \
	./doors/doors.c \
	./doors/doors_utils.c \
	./doors/doors_h_intersections.c \
	./doors/doors_v_intersections.c \
	./ray_casting/rays.c \
	./drawing/drawing.c \
	./drawing/animations.c \
	./drawing/drawing_utils.c \
	./drawing/drawing_utils_2.c \
	./ray_casting/horizontal_intersections.c \
	./ray_casting/vertical_intersections.c \
	./exit/exit.c \
	./utils/utils.c \
	./utils/utils2.c \
	./utils/utils3.c \
	./utils/free.c \
	./utils/ft_split.c \
	./utils/get_next_line.c \
	./parsing/directions.c \
	./parsing/colors.c \
	./parsing/check2.c \
	./parsing/check3.c \
	./parsing/check4.c \
	./parsing/check5.c \
	./parsing/check6.c \
	./parsing/check7.c \
	./parsing/check.c

OBJS = $(SRCS:.c=.o)

BLUE=\033[0;34m
NC=\033[0m

all: $(NAME)

	@echo "$(BLUE)"
	@echo "                                         "		
	@echo " ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ "
	@echo "██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗"
	@echo "██║     ██║   ██║██████╔╝ █████╔╝██║  ██║"
	@echo "██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║"
	@echo "╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝"
	@echo " ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ "
	@echo "                                         "
	@echo "$(NC)"

$(NAME): $(OBJS) ./cub.h
	@echo "$(BLUE)"
	@echo "Creating object files"
	@echo "$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib" $(MLXFLAGS)


%.o: %.c ./cub.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)"
	@echo "Cleaning up ..."
	@echo "$(NC)"
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
