# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dplesca <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/23 14:31:58 by dplesca           #+#    #+#              #
#    Updated: 2017/01/05 12:58:23 by dplesca          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRCS =	ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_atoi.c \
		ft_islower.c \
		ft_isupper.c \
		ft_isalpha.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_itoa.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_lstnew.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstdelone.c \
		ft_lstmap.c \
		ft_getnbr.c \
		ft_nbrsize.c \
		ft_iswspace.c \
		ft_fputstr.c \
		get_next_line.c \
		util.c\
		format.c \
		format_1.c \
		format_2.c \
		format_3.c \
		printf.c \
		printf_1.c \
		printf_2.c \
		printf_3.c \
		params.c \
        color.c \
		flags_1.c \
		flags_2.c \
		flags_3.c \
		flags_4.c \
		flags_5.c \
		flags_6.c \
		atoi_itoa.c \
		types.c \
		type_1.c \
		ft_itoa_base.c

OB = ft_strcpy.o \
		ft_strncpy.o \
		ft_strcat.o \
		ft_strncat.o \
		ft_strlcat.o \
		ft_strchr.o \
		ft_strrchr.o \
		ft_strstr.o \
		ft_strnstr.o \
		ft_strcmp.o \
		ft_strncmp.o \
		ft_strnew.o \
		ft_strdel.o \
		ft_strclr.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strequ.o \
		ft_strnequ.o \
		ft_strsub.o \
		ft_strjoin.o \
		ft_strtrim.o \
		ft_strsplit.o \
		ft_isdigit.o \
		ft_isascii.o \
		ft_putchar.o \
		ft_putstr.o \
		ft_strdup.o \
		ft_strlen.o \
		ft_atoi.o \
		ft_islower.o \
		ft_isupper.o \
		ft_isalpha.o \
		ft_isalnum.o \
		ft_isprint.o \
		ft_toupper.o \
		ft_tolower.o \
		ft_itoa.o \
		ft_putendl.o \
		ft_putnbr.o \
		ft_putchar_fd.o \
		ft_putstr_fd.o \
		ft_putendl_fd.o \
		ft_putnbr_fd.o \
		ft_memset.o \
		ft_bzero.o \
		ft_memcpy.o \
		ft_memccpy.o \
		ft_memmove.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_memalloc.o \
		ft_memdel.o \
		ft_lstnew.o \
		ft_lstdel.o \
		ft_lstadd.o \
		ft_lstiter.o \
		ft_lstdelone.o \
		ft_lstmap.o \
		ft_getnbr.o \
		ft_nbrsize.o \
		ft_iswspace.o \
		ft_fputstr.o \
		get_next_line.o \
		util.o \
		format.o \
		format_1.o \
		format_2.o \
		format_3.o \
		printf.o \
		printf_1.o \
		printf_2.o \
		printf_3.o \
		params.o \
        color.o \
		flags_1.o \
		flags_2.o \
		flags_3.o \
		flags_4.o \
		flags_5.o \
		flags_6.o \
		atoi_itoa.o \
		types.o \
		type_1.o \
		ft_itoa_base.o

all: $(NAME)

$(NAME):
		gcc $(FLAGS) -c $(SRCS) -I ./includes
		ar rcs $(NAME) $(OB)
		ranlib $(NAME)

clean:
		rm -rf $(OB)

fclean: 
		rm -rf $(OB)
		rm -rf $(NAME)

re: fclean $(NAME)
