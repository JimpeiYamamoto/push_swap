# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 13:03:51 by yjimpei           #+#    #+#              #
#    Updated: 2021/12/28 16:07:50 by yjimpei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_S = push_swap
CC = gcc
RM = rm -f
#CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I.
LIBFT = ./lib/libft/libft.a

MAIN_SRC	=	srcs/Main/main.c \
				srcs/Main/check_input.c \
				srcs/Main/few_sort.c \
				srcs/Main/middle_sort.c \
				srcs/Main/many_sort.c \
				srcs/Main/push_utils.c \
				srcs/Main/push_utils2.c \
				srcs/Main/reduce_ans.c

RULE_SRC	=	srcs/Rule/operation_rule1.c \
				srcs/Rule/operation_rule2.c \
				srcs/Rule/operation_rule3.c
VECTOR_SRC	=	srcs/Vector/vec_lib.c \
				srcs/Vector/vec_put.c

SRC_DIRS = ${dir ${MAIN_SRC}} ${dir ${VECTOR_SRC}} ${dir ${RULE_SRC}}
OBJ_DIR = ./obj
BIN_DIRS = ${addprefix ${OBJ_DIR}/, ${SRC_DIRS}}
MAIN_OBJS = ${addprefix ${OBJ_DIR}/, ${MAIN_SRC:.c=.o}}
VECTOR_OBJS = ${addprefix ${OBJ_DIR}/, ${VECTOR_SRC:.c=.o}}
RULE_OBJS = ${addprefix ${OBJ_DIR}/, ${RULE_SRC:.c=.o}}

all:	${P_S}

${P_S}:	${MAIN_OBJS} ${VECTOR_OBJS} ${RULE_OBJS} ${LIBFT}
	${CC} -g ${CFLAGS} $^ ${INCLUDES} -o $@

${LIBFT}:
	${MAKE} bonus -C ./lib/libft

${OBJ_DIR}/%.o: %.c
	@mkdir -p ${BIN_DIRS}
	${CC} -g ${CFLAGS} ${INCLUDES} -o $@ -c $<

clean:
	$(MAKE) clean -C ./lib/libft
	${RM} -r ${OBJ_DIR}

fclean:clean
	${MAKE} fclean -C ./lib/libft
	${RM} ${P_S}

re: fclean all

.PHONY: all clean fclean re
