/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 16:21:57 by rmaury            #+#    #+#             */
/*   Updated: 2015/03/12 14:47:39 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	display_env(char **env, char **argv)
{
	if (ft_strcmp(argv[0], "env") == 0)
	{
		if (argv[1])
			ft_putendl("Error: Too Many Arguments");
		if (argv[0] && ft_strcmp(argv[0], "env") == 0)
			ft_printtab(env);
	}
}
