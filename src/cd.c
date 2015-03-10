/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:15:46 by rmaury            #+#    #+#             */
/*   Updated: 2015/03/09 18:41:36 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	cd_err(char **argv)
{
	if (argv[1] && access(argv[1], F_OK) == 0 && chdir(argv[1]) == -1)
		ft_putendl("Directory access denied");
	else
	{
		if (argv[1])
		{
			ft_putstr("no such file or directory: ");
			ft_putendl(argv[1]);
		}
		else
			ft_putendl("no such file or directory");
	}
}

char	**pwd_modifier(char **env, char **argv, char *path)
{
	int		i;
	int		pwd;

	pwd = ft_strcmp_array("PWD=", env);
	i = ft_strcmp_array("OLDPWD=", env);
	if (argv[1] && (strcmp(argv[1], "..") == 0))
	{
		ft_strclr(ft_strrchr(path, '/'));
		ft_strclr(ft_strrchr(path, '/'));
	}
	if (i >= 0 && pwd >= 0)
	{
		env[i] = ft_strjoin("OLDPWD=", env[pwd] + 4);
		env[pwd] = ft_strjoin("PWD=", path);
	}
	return (env);
}

void	home_opt(char **argv, char **env, char *home, char *path)
{
	if (ft_strcmp_array(argv[1], env) >= 0)
	{
		if (!argv[1] || (ft_strcmp(argv[1], "HOME") == 0))
		{
			if (!chdir(home) && !access(home, F_OK))
				env = pwd_modifier(env, argv, home);
			else
				cd_err(argv);
		}
		else if (argv[1][0] == '~')
		{
			argv[1] = ft_strjoin(home, (argv[1] + 1));
			if (!access(argv[1], F_OK) && !chdir(argv[1]))
				env = pwd_modifier(env, argv, path);
			else
				cd_err(argv);
		}
	}
	else
	{
		ft_putendl("HOME Environement Missing");
		ft_putendl ("To set current directory as HOME \"setenv HOME curdir\"");
	}
}

void	back_opt(char **env, char **argv)
{
	int		i;

	i = 0;
	if (chdir(env[i = ft_strcmp_array("OLDPWD=", env)] + 7) != 0)
		cd_err(argv);
}

void	cd(char **env, char **argv)
{
	int		i;
	char	*home;
	char	*path;
	char	*curdir;

	i = 0;
	curdir = NULL;
	curdir = ft_strjoin(getcwd(curdir, 2048), "/");
	if ((i = ft_strcmp_array("HOME=", env)) >= 0)
	{
		home = ft_strdup(env[i] + 5);
		path = ft_strjoin(home, "/");
	}
	if ((!argv[1] || argv[1][0] == '~' ||
		(ft_strcmp(argv[1], "HOME") == 0)))
		home_opt(argv, env, home, path);
	else if (ft_strcmp(argv[1], "-") == 0)
		back_opt(env, argv);
	else
	{
		if (!chdir(path = ft_strjoin(curdir, argv[1])) && !access(path, F_OK))
			env = pwd_modifier(env, argv, path);
		else
			cd_err(argv);
	}
}
