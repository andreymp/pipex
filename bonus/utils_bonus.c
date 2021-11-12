/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:46:12 by jobject           #+#    #+#             */
/*   Updated: 2021/11/12 21:16:48 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_message(char	*message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

static void	delete_structure(char	**strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	error_cmd(char	*message, t_cmd	**cmds)
{
	if ((*(*cmds)->cmd))
		delete_structure((*cmds)->cmd);
	if ((*(*cmds)->mypaths))
		delete_structure((*cmds)->mypaths);
	if ((*cmds)->cmd_path)
		free((*cmds)->cmd_path);
	error_message(message);
}

int	read_write(char	*filename, char	solution, t_cmd	*cmds)
{
	int	fd;

	if (solution == 'r')
	{
		fd = open(filename, O_RDONLY, 0777);
		if (fd < 0)
			error_cmd("ERROR: Unable to open infile.", &cmds);
	}
	else
	{
		fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if (fd < 0)
			error_cmd("ERROR: Unable to open outfile.", &cmds);
	}
	return (fd);
}

char	*double_join(char	*s1, char	*s2)
{
	char	*temp1;
	char	*res;

	temp1 = ft_strjoin(s1, "/");
	res = ft_strjoin(temp1, s2);
	free(temp1);
	return (res);
}
