/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:50:57 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/07 19:06:40 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	int		infile;
	int		outfile;
	int		pd[2];
	int		ac;
	int		i;
	int		save;
	int		flag;
	char	*limiter;
	char	*filepath;
}	t_data;

int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strncpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	pipex(t_data *data, char **argv, char **envp);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
void	free_all(char **matrix);
void	ft_print_error(char *msg);
char	*check_path(char *cmd, char **envp);
char	**get_paths(char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
int		ft_isnewline(char *str);
void	ft_memmove(char *dst, char *src, int n);
int		ft_linelen(char *str);
void	pipex_bonus(t_data *data, char **argv, char **envp);
void	execute(t_data *data, char **argv, char **envp);
void	first_cmd(t_data *data, char **argv);
void	last_cmd(t_data *data, char **argv, char **envp);
void	handle_here_doc(t_data *data, char **argv, char **envp);
void	here_doc(t_data *data);
char	*ft_itoa(int n);

# define BUFFER_SIZE 10

#endif
