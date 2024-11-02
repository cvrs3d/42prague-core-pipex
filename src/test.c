/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:13:06 by yustinov          #+#    #+#             */
/*   Updated: 2024/11/02 15:49:21 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char *cmd = "f.out";

	int response = access(cmd, F_OK | X_OK);
	if (response == 0)
		printf("File can be executed\n");
	else
	{
		perror("Command does not exist or does not have execute permission");
		write(STDERR_FILENO, "Command:", 8);
		write(STDERR_FILENO, cmd, strlen(cmd));
		exit(EXIT_FAILURE);
	}
	return (0);
}
