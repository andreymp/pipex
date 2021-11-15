/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:47:38 by jobject           #+#    #+#             */
/*   Updated: 2021/11/15 20:05:51 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(char	*filename, char	*lim)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDWR, 0777);
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 2);
		line = get_next_line(0);
		if (!ft_strncmp(line, lim, ft_strlen(lim)))
			break ;
		ft_putstr_fd(line, fd);
		free(line);
	}
	free(line);
	close(fd);
}

void	wait_func(int argc, int count)
{
	int	i;

	i = 0;
	while (i < argc - count)
	{
		waitpid(0, NULL, 0);
		i++;
	}
}

int	choice(t_proccess *proc, t_cmd	*cmds, char	**argv, int argc)
{
	int	i;

	if (argc == 6 && !ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
	{
		i = 3;
		here_doc(argv[1], argv[2]);
		proc->fd1 = read_write(argv[1], 'r', cmds);
		proc->fd2 = read_write(argv[argc - 1], 'a', cmds);
	}
	else
	{
		i = 2;
		proc->fd1 = read_write(argv[1], 'r', cmds);
		proc->fd2 = read_write(argv[argc - 1], 'w', cmds);
	}
	return (i);
}

void	del(t_cmd	*cmds, int i)
{
	if (cmds->cmd)
		delete_structure(cmds->cmd);
	if (cmds->mypaths && i)
		delete_structure(cmds->mypaths);
	if (cmds->cmd_path)
		free(cmds->cmd_path);
}

int	main(int argc, char	**argv,	char	**envp)
{
	t_cmd		cmds;
	t_proccess	proc;
	int			i;

	if (argc < 5)
		error_message("ERROR: Wrong structure.");
	check(argv, argc);
	init_env(envp, &cmds);
	i = choice(&proc, &cmds, argv, argc);
	dup2(proc.fd1, STDIN_FILENO);
	while (i < argc - 2)
	{
		init_cmd(argv[i++], &cmds);
		pipex(&cmds, envp, &proc);
		del(&cmds, 0);
	}
	close(proc.fd1);
	dup2(proc.fd2, STDOUT_FILENO);
	init_cmd(argv[i], &cmds);
	execve(cmds.cmd_path, cmds.cmd, envp);
	del(&cmds, 1);
	total_wait(argv, argc);
	close(proc.fd2);
	return (0);
}
