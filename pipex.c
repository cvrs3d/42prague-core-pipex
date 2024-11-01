/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:33:38 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/01 16:22:32 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*set_full_path(char *cmd)
{
    char	*fullpath;

    fullpath = (char *)malloc(ft_strlen("/bin/") + ft_strlen(cmd) + 1);
    if (!fullpath)
        exit(EXIT_FAILURE);
    ft_strcpy(fullpath, "/bin/");
    ft_strcat(fullpath, cmd);
    return (fullpath);
}

static void	free_all(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static void	execute_cmd(char *cmd)
{
	char	*full_path;
	char	**args;

	args = ft_split(cmd, ' ');
	full_path = set_full_path(args[0]);
	printf("Command full path: %s\n", full_path);
	if (execve(full_path, args, NULL) == -1)
	{
	perror("execve failed");
	free(full_path);
	free_all(args);
	exit(EXIT_FAILURE);
	}
	free(full_path);
	free_all(args);
	return ;
}

void	pipex(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	
	// Create a pipe
	if (pipe(fd) == -1)
	{
		perror("pipe failed");
		exit(EXIT_FAILURE);
	}
	// Open the input file for reading
	infile = open(argv[1], O_RDONLY | O_CREAT);
	if (infile < 0)
	{
		perror("open failed");
		exit(EXIT_FAILURE);
	}
	// Open the output file for writing
	outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("open failed");
		exit(EXIT_FAILURE);
	}
	// Create the first child process
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	// ./pipex file1 cm1 cm2 file2
	if (pid1 == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(infile);
		close(fd[1]);
		close(fd[0]);
		execute_cmd(argv[2]);
		exit(EXIT_SUCCESS);
	}
	
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		close(fd[1]);
		close(fd[0]);
		execute_cmd(argv[3]);
		exit(EXIT_SUCCESS);
	}

	close(fd[0]);
	close(fd[1]);
	close(outfile);
	close(infile);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return ;
}
