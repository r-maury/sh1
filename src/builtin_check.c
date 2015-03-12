/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:17:48 by rmaury            #+#    #+#             */
/*   Updated: 2015/03/12 14:45:40 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		builtin_check(char **str)
{
	if (ft_strcmp(str[0], "env") == 0)
		return (1);
	if (ft_strcmp(str[0], "cd") == 0)
		return (1);
	if (ft_strcmp(str[0], "unsetenv") == 0)
		return (1);
	if (ft_strcmp(str[0], "setenv") == 0)
		return (1);
	if (ft_strcmp(str[0], "exit") == 0)
		return (1);
	return (0);
}
