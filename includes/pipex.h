/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaltea <amaltea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 02:54:21 by amaltea           #+#    #+#             */
/*   Updated: 2025/06/27 01:21:14 by amaltea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

// utils
// errors
void	path_error(void);
void	cmdnf_error(char *cmd);
void	error_g(int pipefd[2]);
void	usage_error(void);
// exec
int		exec_cmd(char *cmd, char **envp, int fd_in, int fd_out);
void	exec1(char **av, char **envp, int pipe_in);
void	exec2(char **av, char **envp, int pipe_out);
// get_path
char	*get_path(char **envp);
void	free_split(char **splttd);
char	*join_path(char *fpdir, char *cmd);
char	*find_cmd(char *cmd, char **envp);

// pipex
int		pipex(char **av, char **envp);

#endif
