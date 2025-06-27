/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaltea <amaltea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 03:07:46 by amaltea           #+#    #+#             */
/*   Updated: 2025/06/27 01:47:38 by amaltea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(char **av, char **envp)
{
	int		pipefd[2];
	pid_t	p1;
	pid_t	p2;
	int		wstatus;

	if (pipe(pipefd) == -1)
		error_g(NULL);
	p1 = fork();
	if (p1 == -1)
		error_g(pipefd);
	else if (p1 == 0)
	{
		close(pipefd[0]);
		exec1(av, envp, pipefd[1]);
	}
	close(pipefd[1]);
	p2 = fork();
	if (p2 == -1)
		error_g(pipefd);
	else if (p2 == 0)
		exec2(av, envp, pipefd[0]);
	close(pipefd[0]);
	waitpid(p2, &wstatus, 0);
	waitpid(p1, NULL, 0);
	return (wstatus);
}

int	main(int ac, char **av, char **envp)
{
	int	status;

	if (ac != 5)
		usage_error();
	status = pipex(av, envp);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
