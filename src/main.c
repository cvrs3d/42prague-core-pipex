/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:49:21 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/02 16:20:58 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	if (argc > 5 && ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		handle_here_doc(argv);
		exit(0);
		return (0);
	}
	if (argc < 5)
	{
		write(STDOUT_FILENO, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 36);
		check_file_rights(argv[1]);
		exit (1);
	}
	pipex(argc, argv);
	return (0);
}
