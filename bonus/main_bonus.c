/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:31:20 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/07 16:37:30 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc == 1)
		ft_print_error("Usage: ./pipex_bonus file1 cmd1 cmd2 ... cmdn file2");
	if (!envp)
		ft_print_error("Error empty environment");
	if (!ft_strncmp(argv[1], "here_doc", 9) && argc == 6)
	{
		data.ac = argc;
		handle_here_doc(&data, argv, envp);
	}
	else if (argc >= 5)
	{
		data.ac = argc;
		data.flag = 0;
		pipex_bonus(&data, argv, envp);
	}
	else
		ft_print_error("Usage: ./pipex_bonus file1 cmd1 cmd2 ... cmdn file2");
	return (0);
}
