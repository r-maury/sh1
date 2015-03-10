/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_duplicator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 18:45:07 by rmaury            #+#    #+#             */
/*   Updated: 2015/02/19 16:30:54 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**env_duplicator(char **env)
{
	char	**env_cpy;
	int		i;

	i = ft_tabline_count(env);
	env_cpy = (char**)malloc(sizeof(char*) * i + 1);
	env[i] = 0;
	i = 0;
	while (env[i])
	{
		env_cpy[i] = ft_strdup(env[i]);
		i++;
	}
	return (env_cpy);
}
