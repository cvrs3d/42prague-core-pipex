/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:49:21 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/03 13:06:11 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	if (argc > 5 && ft_strncmp(argv[1], "here_doc", 8) == 0)
		hc_pipex(argc, argv);
	if (argc < 5)
	{
		errno = EINVAL;
		perror("Usage: ./pipex file1 cmd1 cmd2 file2");
		exit (EXIT_FAILURE);
	}
	check_file_rights(argv[1]);
	if (argc == 5)
		pipex(argc, argv);
	return (0);
}
