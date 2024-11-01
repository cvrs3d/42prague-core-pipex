/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:49:21 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/01 14:49:53 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		write(STDOUT_FILENO, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 36);
		exit (1);
	}
	pipex(argc, argv);
	return (0);
}
