/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 04:34:04 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/09 03:51:22 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int	fd[2];
	
	if (ac != 5)
		return (ft_putstr_fd("No good argument\n", 2), 1);
	pipex.env = envp;
	if (open_file(&pipex, av) == -1);
}
