/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 17:15:50 by rmaury            #+#    #+#             */
/*   Updated: 2015/03/12 14:43:56 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**path_finder(char **env)
{
	char	**path;
	int		i;

	path = NULL;
	if ((i = ft_strcmp_array("PATH=", env)) >= 0)
		path = ft_strsplit(env[i] + 5, ':');
	if (i == -1 || path[0] == NULL)
	{
		path = (char**)malloc(sizeof(char*) * 2);
		path[0] = ft_strdup("no");
		path[1] = '\0';
	}
	return (path);
}
