/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:54:35 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/02 16:18:52 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_isnewline(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

void	ft_memmove(char *d, char *s, int n)
{
	char	*dst;
	char	*src;

	dst = d;
	src = s;
	if (dst == src)
		return ;
	if (dst < src || dst >= src + n)
	{
		while (n--)
			*dst++ = *src++;
		*dst = '\0';
	}
	else
	{
		dst += n;
		src += n;
		while (n--)
			*(--dst) = *(--src);
		*dst = '\0';
	}
	return ;
}

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}
