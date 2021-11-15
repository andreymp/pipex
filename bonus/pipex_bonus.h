/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:45:16 by jobject           #+#    #+#             */
/*   Updated: 2021/11/15 20:05:40 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_cmd
{
	char	**cmd;
	char	**mypaths;
	char	*cmd_path;
}				t_cmd;

typedef struct s_proccess
{
	int		fds[2];
	int		fd1;
	int		fd2;
	pid_t	parent;
}				t_proccess;

void	error_message(char	*message);
void	error_cmd(char	*message, t_cmd	**cmds);
void	init_env(char	**envp, t_cmd	*cmds);
char	*double_join(char	*s1, char	*s2);
void	init_cmd(char	*argv, t_cmd	*cmds);
int		read_write(char	*filename, char solution, t_cmd	*cmds);
void	pipex(t_cmd	*cmds, char	**envp, t_proccess	*proc);
void	delete_structure(char	**strs);
void	wait_func(int argc, int count);
void	total_wait(char	**argv, int argc);
void	check(char	**argv, int argc);

#endif