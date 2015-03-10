/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_selector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 18:33:08 by rmaury            #+#    #+#             */
/*   Updated: 2015/03/09 18:20:54 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	*path_selector(char *str, char *line)
{
	str = ft_strjoin(str, "/");
	str = ft_strjoin(str, line);
	return (str);
}
