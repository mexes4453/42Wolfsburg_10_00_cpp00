# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 15:08:09 by cudoh             #+#    #+#              #
#    Updated: 2023/01/14 19:32:43 by cudoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SRCS:= $(shell ls *.c | grep -v lst | xargs)

SRCS:= main.cpp Contact.cpp PhoneBook.cpp

OBJS:= $(SRCS:.c=.o)

NAME = phonebook

CC = g++
#CFLAGS = -Werror -Wall -Wextra -O3 -g #-fsanitize=address
STD_CPP = c++98
CFLAGS = -Werror -Wall -Wextra -g -pedantic -Wunused -std=$(STD_CPP)
ifeq ($(shell uname), Linux)
# Compilation flag for Linux
	INCLUDES = -I./ 
else
# Compilation flag for MacOS (42 wolfsburg)
	INCLUDES = -I./
endif

NAME : all
all : $(NAME)
$(NAME) : $(OBJS) 
	@echo "\033[1;33mCompiling Executables: $(NAME) \033[0m"
	$(CC) $^ $(CFLAGS) $(INCLUDES) -o $@
	@echo; echo "\033[1;32mCompilation Successful. \033[0m"
	@echo; echo

	
# obj files output
%.o : %.c
	@echo
	@echo "\033[1;33mCompiling OBJ files \033[0m"
	$(CC) -c $^ $(CFLAGS) $(INCLUDES) -o $@
	@echo


# remove all object files
fclean:
	rm -rf *.o

# remove final target files
clean: fclean
	rm -rf $(NAME)

# recompile everything
re: clean all

.PHONY : all fclean clean re 
