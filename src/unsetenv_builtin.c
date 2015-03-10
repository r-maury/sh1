/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 16:53:47 by rmaury            #+#    #+#             */
/*   Updated: 2015/03/04 14:08:45 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**new_env(char **env, char **env_cpy)
{
	int		i;
	int		ac;

	i = 0;
	ac = 0;
	while (env[i + ac])
	{
		if (env[i + ac][0] == 0)
			i++;
		else
		{
			env_cpy[ac] = ft_strdup(env[i + ac]);
			ac++;
		}
	}
	return (env_cpy);
}

char	**env_alloc(char **env, int ac)
{
	int		i;
	char	**env_cpy;

	i = ft_tabline_count(env) - ac;
	if (!(env_cpy = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	env_cpy[i] = 0;
	return (env_cpy);
}

char	**unsetenv_builtin(char **env, char **argv)
{
	int		i;
	int		ret;
	int		ac;
	char	**env_cpy;

	i = 1;
	ac = 0;
	while (argv[i])
	{
		argv[i] = ft_strjoin(argv[i], "=");
		if ((ret = ft_strcmp_array(argv[i], env)) >= 0)
		{
			ft_strclr(env[ret]);
			ac++;
		}
		i++;
	}
	if (ac == 0)
		return (env);
	env_cpy = env_alloc(env, ac);
	env_cpy = new_env(env, env_cpy);
	return (env_cpy);
}
