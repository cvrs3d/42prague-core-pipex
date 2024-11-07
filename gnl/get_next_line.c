/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:50:37 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/02 16:10:10 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	set_data(char *buffer, int fd)
{
	ssize_t	byteread;
	int		buflen;

	buflen = ft_strlen(buffer);
	if (buflen > 0)
		return (buflen);
	byteread = read(fd, buffer, BUFFER_SIZE);
	if (byteread < 0)
		return (-1);
	buffer[byteread] = '\0';
	return (byteread);
}

static int	get_data(char *buffer, char **res)
{
	char	*new;
	int		bytes;

	bytes = ft_linelen(buffer);
	if (bytes == 0)
		return (-1);
	new = (char *)malloc(ft_strlen(*res) + bytes + 1);
	if (!new)
		return (-1);
	ft_memmove(new, *res, ft_strlen(*res));
	ft_memmove(new + ft_strlen(*res), buffer, bytes);
	free(*res);
	*res = new;
	ft_memmove(buffer, buffer + bytes, ft_strlen(buffer) - bytes);
	if (ft_isnewline(new))
		return (1);
	return (0);
}

static int	manage_buffer(char *b, char **r, int fd, int err)
{
	int		response;
	ssize_t	read_result;

	if (err == -1)
		return (-1);
	while (1)
	{
		response = get_data(b, r);
		if (response > 0)
			return (1);
		if (response < 0)
			return (-1);
		read_result = set_data(b, fd);
		if (read_result == -1)
			return (-1);
		if (read_result <= 0 && response == 0)
			return (1);
		else if (read_result <= 0)
			return (1);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	int			response;
	int			read_resp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	read_resp = 0;
	if (buffer[0] == '\0')
		read_resp = set_data(buffer, fd);
	if (read_resp == -1)
		return (NULL);
	result = (char *)malloc(BUFFER_SIZE + 1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	response = manage_buffer(buffer, &result, fd, read_resp);
	if (response == -1)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
