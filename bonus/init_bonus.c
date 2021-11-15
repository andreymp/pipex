/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:40:47 by jobject           #+#    #+#             */
/*   Updated: 2021/11/15 20:05:16 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check(char	**argv, int argc)
{
	int	i;

	i = 2;
	while (i < argc - 2)
	{
		while (*argv[2] && *argv[2] == ' ')
			argv[2]++;
		if (!*argv[2])
			error_message("ERROR: cmd doesn't exist");
		i++;
	}
}

static void	init_cmd_path(t_cmd	**cmds)
{
	int		i;

	i = 0;
	while ((*cmds)->mypaths[i])
	{
		(*cmds)->cmd_path = double_join((*cmds)->mypaths[i], (*cmds)->cmd[0]);
		if (!access((*cmds)->cmd_path, F_OK))
			break ;
		free((*cmds)->cmd_path);
		(*cmds)->cmd_path = NULL;
		i++;
	}
}

void	init_env(char	**envp, t_cmd	*cmds)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH", envp[i], ft_strlen("PATH")))
		i++;
	if (envp[i])
		cmds->mypaths = ft_split(envp[i] + 5, ':');
}

void	init_cmd(char	*argv, t_cmd	*cmds)
{
	cmds->cmd = ft_split(argv, ' ');
	init_cmd_path(&cmds);
	if (!cmds->cmd_path)
		error_cmd("ERROR: cmd doesn't exist", &cmds);
}
