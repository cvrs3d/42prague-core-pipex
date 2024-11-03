/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hc_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:49:08 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/03 16:27:04 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	hc_process(int *fd, char **argv)
{
	char	*line;

	line = handle_here_doc(argv);
	close(fd[0]);
	write(fd[1], line, ft_strlen(line));
	close(fd[1]);
	free(line);
	exit(EXIT_SUCCESS);
}

void	hc_pipex(int argc, char **argv)
{
	int		fd[2];
	int		outfile;
	pid_t	pids[3];

	ft_pipe(fd);
	outfile = ft_open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
	pids[0] = ft_fork();
	if (pids[0] == 0)
		hc_process(fd, argv);
	pids[1] = ft_fork();
	if (pids[1] == 0)
	{
		close(fd[1]);
		process(fd[0], -1, argv[3]);
	}
	pids[2] = ft_fork();
	if (pids[2] == 0)
	{
		close(fd[1]);
		process(fd[0], outfile, argv[4]);
	}
	close_fds(fd, &outfile, &outfile);
	wait_for_children();
	exit(EXIT_SUCCESS);
}
