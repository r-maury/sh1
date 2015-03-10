/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:02:48 by rmaury            #+#    #+#             */
/*   Updated: 2015/03/09 18:44:21 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**create_new(char **env, char **argv)
{
	int		i;
	char	**env_cpy;

	env_cpy = (char**)malloc(sizeof(char*) * (ft_tabline_count(env) + 2));
	env_cpy[ft_tabline_count(env) + 1] = 0;
	i = 0;
	while (env[i])
	{
		env_cpy[i] = ft_strdup(env[i]);
		i++;
	}
	env_cpy[i] = ft_strjoin(argv[1], "=");
	if (argv[2])
		env_cpy[i] = ft_strjoin(env_cpy[i], argv[2]);
	return (env_cpy);
}

char	**setenv_builtin(char **env, char **argv)
{
	int		i;

	if (!argv[1])
		ft_printtab(env);
	else if (argv[3])
		ft_putendl("setenv: Too many arguments.");
	else if ((i = ft_strcmp_array(argv[1], env)) >= 0)
	{
		ft_strclr(env[i]);
		env[i] = ft_strjoin(argv[1], "=");
		if (argv[2])
			env[i] = ft_strjoin(env[i], argv[2]);
	}
	else
		env = create_new(env, argv);
	return (env);
}
