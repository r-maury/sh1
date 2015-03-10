/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 08:37:37 by oror              #+#    #+#             */
/*   Updated: 2015/03/04 18:19:32 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**split_trim(char *line)
{
	int		i;
	char	**argv;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	argv = ft_strsplit(line, ' ');
	i = 0;
	while (argv[i])
	{
		argv[i] = ft_strtrim(argv[i]);
		i++;
	}
	return (argv);
}
