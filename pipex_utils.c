/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:53:54 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/02 13:56:02 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*set_full_path(char *cmd)
{
	char	*fullpath;

	fullpath = (char *)malloc(ft_strlen("/bin/") + ft_strlen(cmd) + 1);
	if (!fullpath)
		exit(EXIT_FAILURE);
	ft_strcpy(fullpath, "/bin/");
	ft_strcat(fullpath, cmd);
	return (fullpath);
}

void	free_all(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	ft_open(const char *file, int flags)
{
	int	fd;

	fd = open(file, flags, 0644);
	if (fd < 0)
	{
		perror("open failed");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	close_fds(int *fd, int *infile, int *outfile)
{
	close(fd[0]);
	close(fd[1]);
	close(*infile);
	close(*outfile);
}

void	execute_cmd(char *cmd)
{
	char	*full_path;
	char	**args;

	args = ft_split(cmd, ' ');
	full_path = set_full_path(args[0]);
	printf("Command full path: %s\n", full_path);
	if (execve(full_path, args, NULL) == -1)
	{
		perror("execve failed");
		free(full_path);
		free_all(args);
		exit(EXIT_FAILURE);
	}
	free(full_path);
	free_all(args);
	return ;
}
