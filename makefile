NAME = fractol

CFILES = src/main.c \
		 src/hooks.c \
		 src/mandlebrot.c \
		 src/julia.c \
		 src/another_fractal.c

LIBS = libmlx.a 

FRAMEWORKS = -framework OpenGL -framework AppKit

HEADERS = inc 

all: $(CFILES) $(LIBS)
	@gcc -Wall -Wextra -Werror -o $(NAME) -I $(HEADERS) $(FRAMEWORKS) $(LIBS) $(CFILES)

clean :
	rm -f minilibx_macos/*.o

fclean : clean
	rm -f fdf

re : fclean all
