/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:38:03 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/07 17:36:31 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parent_process(t_data *data)
{
	close(data->save);
	while (waitpid(-1, NULL, 0) != -1)
		;
}

static void	child_processes(t_data *data, char **argv, char **envp)
{
	close(data->pd[0]);
	if (data->i == 2)
		first_cmd(data, argv);
	if ((data->flag == 1) && data->i == 3)
		here_doc(data);
	if (data->save != -1 && dup2(data->save, 0) == -1)
		ft_print_error("Dup2 error or incorrect fd");
	close(data->save);
	if (data->i == data->ac - 2)
		last_cmd(data, argv, envp);
	if (dup2(data->pd[1], 1) == -1)
		ft_print_error("Dup2 error");
	close(data->pd[1]);
	execute(data, argv, envp);
}

static void	middle_process(t_data *data, char **argv, char **envp)
{
	pid_t	pid;

	if (pipe(data->pd) == -1)
		ft_print_error("Pipe error");
	pid = fork();
	if (pid == -1)
		ft_print_error("Fork error");
	if (pid == 0)
		child_processes(data, argv, envp);
	close(data->save);
	data->save = dup(data->pd[0]);
	if (data->save == -1)
		ft_print_error("Dup Error");
	close(data->pd[0]);
	close(data->pd[1]);
}

void	pipex_bonus(t_data *data, char **argv, char **envp)
{
	data->i = 2;
	data->save = -1;
	if (data->flag == 1)
		data->i = 3;
	while (data->i <= data->ac - 2)
	{
		middle_process(data, argv, envp);
		data->i++;
	}
	parent_process(data);
}
