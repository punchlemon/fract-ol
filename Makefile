NAME								=	fractol
INC_DIR								=	inc

SRC_DIR								=	src
OBJ_DIR								=	obj

FILES								=	 \
										main \
										color \

CC									=	gcc
XFLAGS								=	-L./mlx -lmlx_Linux -lXext -lX11 -lm
CFLAGS								=	#-Wall -Werror -Wextra
IFLAGS								=	-I$(INC_DIR)

OBJ_EXIST							=	.obj

SRCS								=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJS								=	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

$(OBJ_DIR)/%.o:							$(SRC_DIR)/%.c | $(OBJ_EXIST)
										@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_EXIST):
										@mkdir -p $(OBJ_DIR)

all:									$(NAME)

$(NAME):								$(OBJS)
										@$(CC) $(OBJS) $(CFLAGS) $(IFLAGS) $(XFLAGS) -o $(NAME)

clean:
										@$(RM) -rf $(OBJ_DIR)

fclean:									clean
										@$(RM) $(NAME)

re:										fclean all

.PHONY:									all clean fclean re