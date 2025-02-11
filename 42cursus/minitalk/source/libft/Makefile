# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 19:29:35 by diegfern          #+#    #+#              #
#    Updated: 2025/02/09 16:39:23 by diegfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_isdigit.c ft_memmove.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_bzero.c ft_isprint.c ft_memset.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_calloc.c ft_itoa.c ft_print_numbers.c ft_split.c ft_strlcpy.c ft_strtrim.c ft_isalnum.c ft_memchr.c ft_printf.c ft_strchr.c ft_strlen.c  ft_substr.c ft_isalpha.c ft_memcmp.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_isascii.c ft_memcpy.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c

OBJ = $(SRC:.c=.o)

HDR = libft.h

all: $(NAME)

# Creación de la librería
$(NAME): $(OBJ)
	@echo "Creating static library $(NAME)..."
	@ar rcs $(NAME) $(OBJ)
	@echo "Done!"

# Compilación de archivos .c en .o
%.o: %.c $(HDR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -I. -c $< -o $@


# Limpieza de archivos objeto
clean:
	@echo "\nRemoving .o files..."
	@rm -f $(OBJ)
	@echo "\nDone!"


# Limpieza total de la librería y archivos objeto
fclean: clean
	@echo "\nRemoving library $(NAME)..."
	@rm -f $(NAME)
	@echo "\nDone!"

# Recompilación completa
re: fclean all