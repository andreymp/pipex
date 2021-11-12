/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:40:47 by jobject           #+#    #+#             */
/*   Updated: 2021/11/12 20:50:54 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	init_cmd(char	**envp, char	*argv, t_cmd	*cmds)
{
	cmds->cmd = ft_split(argv, ' ');
	init_cmd_path(&cmds);
	if (!cmds->cmd_path)
		error_cmd("ERROR: cmd doesn't exist", &cmds);
}
