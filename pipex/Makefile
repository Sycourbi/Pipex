# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 11:06:11 by sycourbi          #+#    #+#              #
#    Updated: 2022/12/20 11:28:04 by sycourbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_B = pipex_b

SRC = ./pipex.c \
	./manip.c \
	./pipex_utils.c \

OBJ = $(SRC:.c=.o)

BONUS = ./Bonus/main_bonus.c \
		./Bonus/heredoc_bonus.c \
		./Bonus/path_bonus.c \
		./Bonus/utils_bonus.c \
		./Bonus/free_bonus.c \
		./Bonus/file_bonus.c \

BONUS_O = $(BONUS:.c=.o)

LIB = ./libft/libft.a

CC = gcc

CFLAG = -Wall -Wextra -Werror -g

all: $(NAME)

HEADER = ./Bonus/pipex_bonus.h

%.o: %.c
	$(CC) -c $(CFLAG) $< -o $@ -I.
# -c sert a creer fichier objet
# -o sert a creer le fichier executable
# -I sert a inclure les header (.h)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(LIB) -I.
	
bonus: $(NAME_B)

$(NAME_B): $(BONUS_O) 
	make -C libft
	$(CC) $(CFLAG) -o $(NAME_B) $(BONUS_O) $(LIB) -I $(HEADER) 
# -o sert a creer l'executable 
# -C sert a indiquer un chemin (va dans le fichier et fais make)

clean:
	cd libft && make clean
	rm -rf $(OBJ) $(BONUS_O)
# -r sert a effacer recursivement les sous repertoires
# -f sert a ne pas demander de confirmation d'effacement, et ne pas renvoyer de code erreur quand le fichier n'existe pas

fclean: clean
	rm -rf $(NAME) $(LIB) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus
