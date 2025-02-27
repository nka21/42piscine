# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 14:26:57 by nkojima           #+#    #+#              #
#    Updated: 2025/02/26 16:17:27 by nkojima          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := libft.a
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar rc
RM      := rm -f

SRCDIR  := srcs
OBJDIR  := $(SRCDIR)
INCDIR  := includes

SRCS := \
    srcs/ft_putchar.c \
    srcs/ft_putstr.c \
    srcs/ft_strcmp.c \
    srcs/ft_strlen.c \
    srcs/ft_swap.c

OBJS := $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating $(NAME)..."
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME) created successfully!"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(INCDIR)/ft.h
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	@echo "Removing object files..."
	@$(RM) $(OBJS)
	@echo "Object files removed."

fclean: clean
	@echo "Removing $(NAME)..."
	@$(RM) $(NAME)
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re
