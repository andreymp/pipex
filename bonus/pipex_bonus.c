/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:55:23 by jobject           #+#    #+#             */
/*   Updated: 2021/11/15 15:42:52 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h" 

static void	child(t_cmd	*cmds, char	**envp, t_proccess	**proc)
{
	if (dup2((*proc)->fds[1], STDOUT_FILENO) < 0)
		error_cmd("ERROR: dup2 failed", &cmds);
	close((*proc)->fds[0]);
	close((*proc)->fds[1]);
	execve(cmds->cmd_path, cmds->cmd, envp);
	exit(EXIT_FAILURE);
}

static void	parents(t_cmd	*cmds, t_proccess	**proc)
{
	if (dup2((*proc)->fds[0], STDIN_FILENO) < 0)
		error_cmd("ERROR: dup2 failed", &cmds);
	close((*proc)->fds[1]);
	close((*proc)->fds[0]);
}

void	pipex(t_cmd	*cmds, char	**envp, t_proccess	*proc)
{
	if (pipe(proc->fds) == -1)
		error_cmd("ERROR: Piping failed", &cmds);
	proc->parent = fork();
	if (proc->parent < 0)
		error_cmd("ERROR: Forking failed", &cmds);
	if (!proc->parent)
		child(cmds, envp, &proc);
	else
		parents(cmds, &proc);
}
