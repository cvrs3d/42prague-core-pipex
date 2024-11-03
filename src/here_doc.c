/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:59:36 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/03 15:55:34 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*pipex_heredoc(char *limiter)
{
	char	*line;
	char	*tmp;
	char	*buf;

	line = ft_strdup("");
	while (1)
	{
		write(STDOUT_FILENO, "pipex heredoc> ", 15);
		buf = get_next_line(STDIN_FILENO);
		if (!buf)
			continue ;
		if (ft_strncmp(buf, limiter, ft_strlen(limiter)) == 0)
		{
			free(buf);
			break ;
		}
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
		free(buf);
		tmp = line;
		line = ft_strjoin(line, "\n");
		free(tmp);
	}
	return (line);
}

char	*handle_here_doc(char **argv)
{
	char	*line;
	char	*limiter;

	limiter = argv[2];
	line = pipex_heredoc(limiter);
	if (!line)
	{
		perror("heredoc failed");
		exit(EXIT_FAILURE);
	}
	return (line);
}
