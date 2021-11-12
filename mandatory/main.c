/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:27:29 by jobject           #+#    #+#             */
/*   Updated: 2021/11/12 19:27:52 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char	**argv, char	**envp)
{
	t_cmd		cmds;
	t_proccess	proc;

	if (argc != 5)
		error_message("ERROR: Wrong structure.");
	if (pipe(proc.fds) == -1)
		error_message("ERROR: Piping failed");
	init_cmd(envp, argv, &cmds);
	pipex(&cmds, &proc, envp, argv);
	return (0);
}
