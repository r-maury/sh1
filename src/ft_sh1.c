/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 16:59:57 by rmaury            #+#    #+#             */
/*   Updated: 2015/03/16 17:20:37 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		g_prompt = 0;

void	env_check(char **env)
{
	if (!env[0])
		ft_putendl("Warning : No Environnement Set");
}

void	empty_line(char *line)
{
	if (line[0] == 0)
	{
		ft_putstr(">> ");
		g_prompt = 1;
	}
	else
		g_prompt = 0;
}

void	interupt(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\n>> ");
		g_prompt = 1;
	}
}

int		main(int ac, char **av, char **env)
{
	char	*line;
	char	**env_cpy;
	char	**argv;

	(void)ac;
	(void)av;
	env_check(env);
	env_cpy = env_duplicator(env);
	env_cpy = shlvl(env_cpy);
	signal(SIGINT, interupt);
	while (1)
	{
		g_prompt == 1 ? g_prompt = 0 : ft_putstr(">> ");
		if (get_next_line(0, &line) == 0)
			exit_shell("exit");
		empty_line(line);
		argv = split_trim(line);
		if (argv[0] && builtin_check(argv) == 1)
			env_cpy = builtin_exec(env_cpy, argv);
		else if (argv[0])
			forksh(env_cpy, argv);
	}
	return (0);
}
