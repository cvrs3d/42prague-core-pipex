/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:33:38 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/03 14:51:06 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("pipe failed");
		exit(EXIT_FAILURE);
	}
}

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	wait_for_children(void)
{
	int	status;

	while (wait(&status) > 0)
	{
		if (WIFEXITED(status))
		{
			continue ;
		}
		else
			perror("Child exited abnormally\n");
	}
}

void	process(int in_fd, int out_fd, char *cmd)
{
	dup2(in_fd, STDIN_FILENO);
	if (out_fd > 0)
	{
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
	close(in_fd);
	execute_cmd(cmd);
	exit(EXIT_SUCCESS);
}

void	pipex(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;

	ft_pipe(fd);
	infile = ft_open(argv[1], O_RDONLY);
	outfile = ft_open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
	pid1 = ft_fork();
	if (pid1 == 0)
	{
		close(fd[0]);
		process(infile, fd[1], argv[2]);
	}
	pid2 = ft_fork();
	if (pid2 == 0)
	{
		close(fd[1]);
		process(fd[0], outfile, argv[argc - 2]);
	}
	close_fds(fd, &infile, &outfile);
	wait_for_children();
	exit(EXIT_SUCCESS);
}
