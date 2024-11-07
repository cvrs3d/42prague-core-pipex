/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:53:32 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/07 19:02:32 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_file_name(void)
{
	char	*path;
	int		i;

	i = 0;
	while (i < FOPEN_MAX)
	{
		path = ft_strjoin("/tmp/", ft_itoa(i));
		if (access(path, F_OK) == -1)
			return (path);
		i++;
	}
	return (NULL);
}

void	here_doc(t_data *data)
{
	int	tmp_fd;

	tmp_fd = open(data->filepath, O_RDONLY);
	if (tmp_fd == -1)
		ft_print_error("Open error");
	if (dup2(tmp_fd, 0) == -1)
		ft_print_error("Dup2 error");
	close(tmp_fd);
}

static void	read_lines(t_data *data, char *line, int tmp_fd)
{
	while (1)
	{
		write(1, "here_doc>", 9);
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if ((ft_strncmp(line, data->limiter, ft_strlen(data->limiter)) == 0)
			&& (ft_strlen(line) - 1 == ft_strlen(data->limiter)))
		{
			free(line);
			break ;
		}
		if (write(tmp_fd, line, ft_strlen(line)) == -1)
		{
			free(line);
			close(tmp_fd);
			unlink(data->filepath);
			ft_print_error("Here_doc input failed");
		}
		free(line);
	}
}

void	handle_here_doc(t_data *data, char **argv, char **envp)
{
	char	*line;
	int		tmp_fd;

	line = NULL;
	data->filepath = get_file_name();
	data->limiter = argv[2];
	data->flag = 1;
	tmp_fd = open(data->filepath, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd == -1)
		ft_print_error("Open error");
	read_lines(data, line, tmp_fd);
	close(tmp_fd);
	pipex_bonus(data, argv, envp);
	unlink(data->filepath);
	free(data->filepath);
	data->filepath = NULL;
}
