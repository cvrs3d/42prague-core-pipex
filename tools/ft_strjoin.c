/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:41:56 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/02 16:27:23 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	slen1;
	size_t	slen2;
	char	*joined;
	char	*dummy;

	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	joined = (char *)malloc(slen1 + slen2 + 1);
	if (joined == NULL)
		return (NULL);
	dummy = joined;
	while (*s1)
		*dummy++ = *s1++;
	while (*s2)
		*dummy++ = *s2++;
	*dummy = '\0';
	return (joined);
}
