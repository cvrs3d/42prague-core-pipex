/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:50:57 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/02 13:56:22 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strncpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	pipex(int argc, char **argv);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
void	execute_cmd(char *cmd);
void	close_fds(int *fd, int *infile, int *outfile);
int		ft_open(const char *file, int flags);
void	free_all(char **args);
char	*set_full_path(char *cmd);

#endif
