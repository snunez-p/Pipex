/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaltea <amaltea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:14:06 by amaltea           #+#    #+#             */
/*   Updated: 2025/06/27 01:38:12 by amaltea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_cmd(char *cmd, char **envp, int fd_in, int fd_out)
{
	char	**a_split;
	char	*full_cmd;

	a_split = ft_split(cmd, ' ');
	if (a_split == NULL)
		return (perror("pipex"), close(fd_in), close(fd_out), -1);
	full_cmd = find_cmd(a_split[0], envp);
	if (full_cmd == NULL)
		return (free_split(a_split), close(fd_in), close(fd_out), -1);
	if (dup2(fd_in, STDIN_FILENO) == -1)
		return (perror("pipex"), free_split(a_split), free(full_cmd),
			close(fd_in), close(fd_out), -1);
	close(fd_in);
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		return (perror("pipex"), free_split(a_split), free(full_cmd),
			close(fd_out), -1);
	close(fd_out);
	execve(full_cmd, a_split, envp);
	free_split(a_split);
	free(full_cmd);
	return (-1);
}

void	exec1(char **av, char **envp, int pipe_in)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("pipex");
		close(pipe_in);
	}
	else
		exec_cmd(av[2], envp, fd, pipe_in);
	exit(EXIT_FAILURE);
}

void	exec2(char **av, char **envp, int pipe_out)
{
	int		fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("pipex");
		close(pipe_out);
	}
	else
		exec_cmd(av[3], envp, pipe_out, fd);
	exit(EXIT_FAILURE);
}
