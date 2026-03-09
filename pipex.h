/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 04:16:51 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/09 02:17:23 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"

typedef struct s_pipex
{
    char **env;
    int infile;
    int outfile;
    
}   t_pipex;

int open_file(t_pipex *pipex,char **av);
int create_pipe(t_pipex *pipex);


#endif