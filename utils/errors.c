/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaltea <amaltea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:02:53 by amaltea           #+#    #+#             */
/*   Updated: 2025/06/27 01:21:30 by amaltea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path_error(void)
{
	errno = ENOENT;
	perror("pipex");
}

void	cmdnf_error(char *cmd)
{
	errno = ENOENT;
	write (2, "pipex: ", 7);
	write (2, cmd, ft_strlen(cmd));
	write (2, ": command not found\n", 20);
}

void error_g(int pipefd[2])
{
	perror("pipex");
	if (pipefd != NULL)
	{
		close(pipefd[0]);
		close(pipefd[1]);
	}
	exit (EXIT_FAILURE);
}

void	usage_error(void)
{
	write (2, "pipex: too few/many arguments\n", 30);
	exit (EXIT_FAILURE);
}
