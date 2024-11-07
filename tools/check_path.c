/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:57:43 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/07 16:18:52 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*check_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	int		i;

	i = -1;
	if (access(cmd, F_OK | X_OK | R_OK) == 0)
		return (cmd);
	if (ft_strncmp(cmd, "/", 1) == 0)
	{
		if (access(cmd, F_OK | X_OK | R_OK) == 0)
			return (cmd);
		else
			ft_print_error("Error in cmd path");
	}
	paths = get_paths(envp);
	while (paths && paths[i++])
	{
		full_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(full_path, cmd);
		if (access(full_path, F_OK | X_OK | R_OK) == 0)
			return (full_path);
		free(full_path);
		full_path = NULL;
	}
	return (NULL);
}
