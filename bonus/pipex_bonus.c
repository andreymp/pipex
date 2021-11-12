/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:55:23 by jobject           #+#    #+#             */
/*   Updated: 2021/11/12 20:56:37 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h" 

void	child(t_cmd	*cmds, char	**envp, char	*filename
, t_proccess	*proc)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0777);
	if (fd < 0)
		error_cmd("ERROR: Unable to open 'infile'", &cmds);
	if (dup2(fd, STDIN_FILENO) < 0)
		error_cmd("ERROR: Unable to dup infile and STDIN", &cmds);
	if (dup2(proc->fds[1], STDOUT_FILENO) < 0)
		error_cmd("ERROR: Unable to dup fds[1] and STDOUT", &cmds);
	close(proc->fds[0]);
	execve(cmds->cmd_path, cmds->cmd, envp);
	close(fd);
	close(proc->fds[1]);
	exit(EXIT_FAILURE);
}