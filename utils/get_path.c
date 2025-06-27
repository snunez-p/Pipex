/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaltea <amaltea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:36:38 by amaltea           #+#    #+#             */
/*   Updated: 2025/06/26 22:09:32 by amaltea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int	i;
	int	diff;

	i = 0;
	while (envp && envp[i])
	{
		diff = ft_strncmp(envp[i], "PATH=", 5);
		if (diff != 0)
			i++;
		else
			return (envp[i] + 5);
	}
	return (NULL);
}

void	free_split(char **splttd)
{
	int	j;

	j = 0;
	while (splttd[j] != NULL)
	{
		free(splttd[j]);
		j++;
	}
	free(splttd);
}

char	*join_path(char *fpdir, char *cmd)
{
	char	*dir;
	char	*fdir;

	dir = ft_strjoin(fpdir, "/");
	if (dir == NULL)
		return (NULL);
	fdir = ft_strjoin(dir, cmd);
	free(dir);
	if (fdir == NULL)
		return (NULL);
	return (fdir);
}

char	*find_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**splttd_path;
	char	*fdir;
	int		i;

	if (ft_strchr(cmd, '/') != NULL)
		return (cmd);
	path = get_path(envp);
	if (path == NULL)
		return (path_error(), NULL);
	splttd_path = ft_split(path, ':');
	if (splttd_path == NULL)
		return (perror("pipex: malloc"), NULL);
	i = 0;
	while (splttd_path[i])
	{
		fdir = join_path(splttd_path[i], cmd);
		if (fdir == NULL)
			return (perror("pipex: malloc"), free_split(splttd_path), NULL);
		if (access(fdir, F_OK) == 0)
			return (free_split(splttd_path), fdir);
		free(fdir);
		i++;
	}
	return (free_split(splttd_path), cmdnf_error(cmd), NULL);
}
