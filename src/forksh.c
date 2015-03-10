/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forksh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:30:24 by rmaury            #+#    #+#             */
/*   Updated: 2015/03/10 16:32:05 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		pathexec(char **argv)
{
	if ((ft_strncmp(argv[0], "./", 2) == 0 || ft_strncmp(argv[0], "/", 1) == 0
		|| ft_strncmp(argv[0], "../", 3) == 0) && access(argv[0], X_OK) == 0)
		return (0);
	else
		return (1);
}

void	not_found(char **argv, char *path)
{
	if (access(argv[0], X_OK) == -1 && ft_strncmp(path, "no", 2))
	{
		ft_putstr("sh1: Access denied: ");
		ft_putendl(argv[0]);
	}
	else
	{
		ft_putstr("sh1: command not found: ");
		ft_putendl(argv[0]);
	}
}

void	forksh(char **env, char **argv)
{
	pid_t	pid;
	int		i;
	char	**path;
	char	*tmp;

	i = 0;
	pid = fork();
	if (pid > 0)
		wait(NULL);
	if (pid == 0)
	{
		if (pathexec(argv) == 0)
			execve(argv[0], argv, env);
		path = path_finder(env);
		while (ft_strncmp(path[0], "no", 2) != 0 &&
			path[i] && builtin_check(argv) == 0)
		{
			tmp = path_selector(path[i], argv[0]);
			access(tmp, X_OK) == 0 ? execve(tmp, argv, env) : i++;
		}
		if (builtin_check(argv) == 0)
			not_found(argv, path[0]);
		exit(0);
	}
}
