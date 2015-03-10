/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:13:40 by rmaury            #+#    #+#             */
/*   Updated: 2015/03/04 18:19:48 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**shlvl(char **env)
{
	int		i;
	int		lvl;

	if ((i = ft_strcmp_array("SHLVL=", env)) >= 0)
	{
		lvl = ft_atoi(env[i] + 6) + 1;
		env[i] = ft_strjoin("SHLVL=", ft_itoa(lvl));
	}
	return (env);
}
