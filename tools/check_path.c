/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:57:43 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/08 16:16:13 by yustinov         ###   ########.fr       */
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
	free_all(path);
	return (NULL);
}

char	*check_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	char	*tmp;
	int		i;

	i = 0;
	if (access(cmd, F_OK | X_OK | R_OK) == 0)
		return (cmd);
	paths = get_paths(envp);
	while (paths && paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, F_OK | X_OK | R_OK) == 0)
		{
			free_all(paths);
			return (full_path);
		}
		free(full_path);
		full_path = NULL;
		i++;
	}
	free_all(paths);
	return (NULL);
}
