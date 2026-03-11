/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 02:20:45 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/11 09:16:27 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **env)
{
	char	*path_env;
	char	**paths;
	char	*path_all;

	if (!cmd || !cmd[0])
	{
		ft_putstr_fd("error: command", 2);
		return (free_split(&cmd), NULL);
	}
	path_env = get_path_env(env);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	path_all = find_path_second(paths, cmd);
	if (!path_all)
		free_split(paths);
	free(paths);
	return (path_all);
}

char	*find_path_second(char **paths, char *cmd)
{
	int		i;
	char	*path_tmp;
	char	*path_all;

	i = 0;
	while (paths[i])
	{
		path_tmp = ft_strjoin(paths[i], "/");
		path_all = ft_strjoin(path_tmp, cmd);
		free(path_tmp);
		if (access(path_all, X_OK) == 0)
			return (path_all);
		free(path_all);
		i++;
	}
	return (NULL);
}

char	*get_path_env(char **env)
{
	int	i;

	if (!*env || !env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}
