/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 01:49:55 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/09 03:53:01 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int open_file(t_pipex *pipex,char **av)
{
    pipex->infile = open(av[1], O_RDONLY);
    if (pipex->infile == -1)
    {
        ft_putstr_fd("Error: open infile\n", 2);
        return ()
    }
    pipex->outfile = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0664);
    if (pipex->outfile == -1)
    {
        close(pipex->infile);
        ft_putstr_fd("Error: open outfile\n", 2);
        exit(1);
    }
    return (0);
}

// int create_pipe(t_pipex *pipex)
// {
//     int fd[2];
    
//     pipe(fd);
//     if (fork() == 0)
//     {
//         close(fd[0]);
        
//     }
// }