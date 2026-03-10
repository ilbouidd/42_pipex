/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 04:24:10 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/10 11:57:33 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(t_pipex *pipex)
{
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close_all(pipex);
	exec_cmd(pipex->av[2], pipex->env);
	ft_putstr_fd("exec failed child_one\n", 2);
	exit(1);
}

void	child_two(t_pipex *pipex)
{
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close_all(pipex);
	exec_cmd(pipex->av[3], pipex->env);
	ft_putstr_fd("exec failed child_two\n", 2);
	exit(1);
}

void	exec_cmd(char *strcmd, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(strcmd, 32);
	if (ft_strchr(cmd[0], '/'))
		path = cmd[0];
	else
		path = find_path(cmd[0], env);
	if (!path)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putchar_fd('\n', 2);
		if (cmd)
			free_split(cmd);
		exit(1);
	}
	execve(path, cmd, env);
	ft_putstr_fd("Error: execv", 2);
	ft_putstr_fd(cmd[0], 2);
	ft_putchar_fd('\n', 2);
	free_split(cmd);
	free(path);
	exit(1);
}
