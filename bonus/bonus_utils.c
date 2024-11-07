/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:39:04 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/07 19:08:02 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(t_data *data, char **argv, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv[data->i], ' ');
	path = check_path(cmd[0], envp);
	execve(path, cmd, envp);
	ft_print_error("Execve error");
}

void	first_cmd(t_data *data, char **argv)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1)
		ft_print_error("Open error");
	if (dup2(data->infile, 0) == -1)
		ft_print_error("Dup2 error");
	close(data->infile);
}

void	last_cmd(t_data *data, char **argv, char **envp)
{
	if (data->flag == 1)
		data->outfile = open(argv[data->ac - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		data->outfile = open(argv[data->ac - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->outfile == -1)
		ft_print_error("Open error");
	if (dup2(data->outfile, 1) == -1)
		ft_print_error("Dup2 error");
	close(data->outfile);
	execute(data, argv, envp);
}
