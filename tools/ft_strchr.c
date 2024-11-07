/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:18:13 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/01 14:03:22 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
		{
			return ((char *) s);
		}
		s++;
	}
	if (*s == (char) c)
	{
		return ((char *) s);
	}
	return (NULL);
}
