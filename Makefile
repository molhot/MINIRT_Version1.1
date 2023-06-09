NAME = miniRT
LIBMLX = minilibx-linux/libmlx_Linux.a

SRCS = miniRT_main.c\
			constructer/constructer.c\
				constructer/ready_drawinfs/ready_drawinfs.c\
				constructer/ready_vectors/ready_vectors.c\
					constructer/ready_vectors/ready_samevec/objarr.c\
					constructer/ready_vectors/ready_samevec/ready_eyevector.c\
					constructer/ready_vectors/ready_samevec/ready_lgtarr.c\
					constructer/ready_vectors/set_vec/set_vec.c\
			execpart/exec.c\
				execpart/render_ready/render_ready.c\
				execpart/render_ready/render_readyball.c\
				execpart/render_ready/render_readyplane.c\
				execpart/render_ready/renderready_cylinder.c\
					execpart/render_ready/check_itsexist/its_ch.c\
					execpart/render_ready/check_itsexist/itsch_cylinder.c\
					execpart/render_ready/check_itsexist/shade_itsch.c\
					execpart/render_ready/check_itsexist/itsch_plane.c\
					execpart/render_ready/scale_change/scale_change.c\
				execpart/render_ready/judge_mapitem.c\
				execpart/drawfunc/put_pix.c\
				execpart/setvec_fordraw/setvec_d.c\
				execpart/vector_calc/vectorArithmetic.c\
				execpart/vector_calc/Scal_veccalc.c\
				execpart/vector_calc/calc_itsvect.c\
				execpart/obtain_shapetype/obtain_shapetype.c

OBJS = $(SRCS:.c=.o)

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror -I includes

ifdef TEST
	CFLAGS += -D TEST
endif

test:
	make all TEST=1

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