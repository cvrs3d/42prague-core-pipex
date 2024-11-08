/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:24:21 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/08 16:20:32 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	*process_second(t_data *data, char **argv, char **envp)
{
	char	**cmd;
	char	*path;

	close(data->pd[1]);
	data->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->outfile == -1)
		return (close(data->pd[0]), ft_print_error("Error opening file"), NULL);
	if (dup2(data->outfile, 1) == -1)
		return (close(data->outfile), close(data->pd[0]),
			ft_print_error("Dup2 error"), NULL);
	if (dup2(data->pd[0], 0) == -1)
	{
		close(data->outfile);
		close(data->pd[0]);
		return (ft_print_error("Dup2 error"), NULL);
	}
	close(data->pd[0]);
	cmd = ft_split(argv[3], ' ');
	path = check_path(cmd[0], envp);
	close(data->outfile);
	if (path)
		execve(path, cmd, envp);
	return (free_all(cmd), free(path), path = NULL,
		ft_print_error("Execve failed, wrong cmd"), NULL);
}

static void	*process_first(t_data *data, char **argv, char **envp)
{
	char	**cmd;
	char	*path;

	close(data->pd[0]);
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1)
	{
		close(data->pd[1]);
		return (ft_print_error("Error opening file"), NULL);
	}
	if (dup2(data->infile, 0) == -1)
		return (close(data->infile), close(data->pd[1]),
			ft_print_error("Dup2 failed"), NULL);
	if (dup2(data->pd[1], 1) == -1)
		return (close(data->infile), close(data->pd[1]),
			ft_print_error("Dup2 failed"), NULL);
	close(data->pd[1]);
	cmd = ft_split(argv[2], ' ');
	path = check_path(cmd[0], envp);
	close(data->infile);
	if (path)
		execve(path, cmd, envp);
	return (free_all(cmd), free(path), path = NULL,
		ft_print_error("Execve failed, wrong cmd"), NULL);
}

void	pipex(t_data *data, char **argv, char **envp)
{
	pid_t	child1;
	pid_t	child2;
	int		status;

	if (pipe(data->pd) == -1)
		ft_print_error("Pipe failed");
	child1 = fork();
	if (child1 == -1)
		ft_print_error("Fork failed");
	if (child1 == 0)
		process_first(data, argv, envp);
	child2 = fork();
	if (child2 == -1)
		ft_print_error("Fork failed");
	if (child2 == 0)
		process_second(data, argv, envp);
	close(data->pd[0]);
	close(data->pd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}
