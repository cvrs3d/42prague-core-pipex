/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:49:21 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/07 19:13:15 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (!envp)
	{
		ft_print_error("No environment variables found");
	}
	if (argc != 5)
	{
		ft_print_error("Usage: ./pipex file1 cmd1 cmd2 file2");
	}
	pipex(&data, argv, envp);
	return (0);
}
