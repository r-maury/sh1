# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 17:47:23 by rmaury            #+#    #+#              #
#    Updated: 2015/03/04 16:59:56 by rmaury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1
CCLIB =
CCFLAGS = -Wall -Werror -Wextra
SRCDIR = src
OBJDIR = obj
INCDIR = includes
LIBDIR = libft/libft.a

SRC +=		get_next_line.c
SRC +=		ft_sh1.c
SRC +=		path_finder.c
SRC +=		path_selector.c
SRC +=		env_duplicator.c
SRC +=		exit_shell.c
SRC +=		display_env.c
SRC +=		builtin_check.c
SRC +=		setenv_builtin.c
SRC +=		unsetenv_builtin.c
SRC +=		cd.c
SRC +=		forksh.c
SRC +=		split_trim.c
SRC +=		builtin_exec.c
SRC +=		shlvl.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)
$(NAME): build $(OBJS)
	@make -C libft
	@gcc $(CCFLAGS) -o $(NAME) $(OBJS) $(INCS) $(LIBDIR)
	@echo "Compilation Over"
build:
	@mkdir -p $(OBJDIR)
clean:
	@make -C libft clean
	@rm -f $(OBJS)
fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -rf obj
re: fclean all

dev : all
	@./$(NAME)

.PHONY: clean fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc -c -g $(CCFLAGS) $(INCS) -I libft/includes -o $@ $<