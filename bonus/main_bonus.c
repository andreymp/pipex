/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:47:38 by jobject           #+#    #+#             */
/*   Updated: 2021/11/12 21:21:10 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char	**argv,	char	**envp)
{
	t_cmd		cmds;
	t_proccess	proc;
	int			i;

	if (argc < 5)
		error_message("ERROR: Wrong structure.");
	init_env(envp, &cmds);
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) && argc == 6)
	{
		// << and >>
	}
	else
	{
		i = 2;
		proc.fd1 = read_write(argv[0], "r", &cmds);
		proc.fd2 = read_write(argv[argc - 1], "w", &cmds);
	}
	return (0);	
}
