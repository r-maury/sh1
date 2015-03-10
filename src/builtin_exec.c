/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 16:48:19 by oror              #+#    #+#             */
/*   Updated: 2015/03/09 19:03:29 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**builtin_exec(char **env, char **argv)
{
	char	*curdir;

	curdir = NULL;
	display_env(env, argv);
	exit_shell(argv[0]);
	if (strcmp(argv[0], "cd") == 0)
		cd(env, argv);
	else if (strcmp(argv[0], "setenv") == 0)
	{
		if (argv[2] && !strcmp(argv[2], "curdir") && !strcmp(argv[1], "HOME"))
			argv[2] = ft_strdup(getcwd(curdir, 2048));
		env = setenv_builtin(env, argv);
	}
	else if (strcmp(argv[0], "unsetenv") == 0)
	{
		if (!argv[1])
			ft_putendl("unsetenv: Too few argument.");
		else
			env = unsetenv_builtin(env, argv);
	}
	return (env);
}
