GREEN = /bin/echo -e "\x1b[1;3;32m$1\x1b[0m"
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = 	srcs/normal/main.c \
		srcs/normal/parse_map.c \
		srcs/normal/init_vars.c \
		srcs/normal/check_map.c \
		srcs/normal/put_map.c \
		srcs/normal/play.c \
		srcs/normal/close_win.c \

SRC_BONUS =	srcs/bonus/main_bonus.c \
       		srcs/bonus/parse_map_bonus.c \
       		srcs/bonus/init_vars_bonus.c \
       		srcs/bonus/check_map_bonus.c \
      		srcs/bonus/put_map_bonus.c \
      		srcs/bonus/play_bonus.c \
      		srcs/bonus/close_win_bonus.c \
			srcs/bonus/ft_animation.c \


OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME = srcs/so_long
LIB = libft/libft.a

all:		$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(OBJ) $(LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	$(call GREEN,"Compilation success 😁")

bonus: $(OBJ_BONUS)
	make -C ./libft
	$(CC) $(OBJ_BONUS) $(LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	$(call GREEN,"Compilation success 😁")

clean:
		make clean -C ./libft
		rm -f $(OBJ) $(OBJ_BONUS)
		$(call GREEN,"The .o cleaned up !")

fclean:		clean
		make fclean -C ./libft
		rm -f $(NAME)
		$(call GREEN,"The rest too !")

re:		fclean all

.SILENT:
.PHONY:		all clean fclean re
