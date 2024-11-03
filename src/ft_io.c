/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:12:40 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/03 13:02:00 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file_rights(const char *file1)
{
	if (access(file1, F_OK) == -1)
	{
		perror("File 1 does not exist");
		perror("Usage: ./pipex file1 cmd1 cmd2 file2");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	check_cmd_rights(const char *cmd)
{
	if (access(cmd, F_OK | X_OK) == -1)
	{
		perror("Command does not exist or does not have execute permission");
		write(STDERR_FILENO, "Command:", 8);
		write(STDERR_FILENO, cmd, ft_strlen(cmd));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	return ;
}
