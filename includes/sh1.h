/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 16:27:14 by rmaury            #+#    #+#             */
/*   Updated: 2015/03/04 16:38:49 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include "libft.h"
# include "get_next_line.h"

char	**path_finder(char **env);
char	*path_selector(char *str, char *line);
char	**env_duplicator(char **env);
void	exit_shell(char *str);
void	display_env(char **env, char **argv);
int		builtin_check(char **str);
char	**setenv_builtin(char **env, char **argv);
char	**create_new(char **env, char **argv);
char	**unsetenv_builtin(char **env, char **argv);
void	cd(char **env, char **argv);
void	forksh(char **env, char **argv);
char	**split_trim(char *line);
char	**builtin_exec(char **env, char **argv);
void	interupt(int sig);
char	**shlvl(char **env);
void	putprompt(void);

#endif
