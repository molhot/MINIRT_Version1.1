NAME = miniRT
LIBMLX = minilibx-linux/libmlx_Linux.a

SRCS = miniRT_main.c\
			constructer/constructer.c\
				constructer/ready_drawinfs/ready_drawinfs.c\
				constructer/ready_vectors/objarr.c\
				constructer/ready_vectors/ready_eyevector.s\
				constructer/ready_vectors/ready_lgtarr.c\
				constructer/ready_vectors/ready_vectors\
				constructer/ready_vectors/set_vec.c\
			execpart/exec.c\
				execpart/drawfunc/put_pix.c\

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I includes

all: $(NAME)

${NAME}: ${OBJS} ${LIBMLX}
	${CC} ${OBJS} ${LIBMLX} -lm -lX11 -lXext -o $(NAME)

${LIBMLX}:
	make -C minilibx-linux/

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY:			all clean fclean re bonus