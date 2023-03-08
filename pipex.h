/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 04:51:13 by jules             #+#    #+#             */
/*   Updated: 2023/03/08 05:29:02 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<string.h>
# include<stdlib.h>
# include<unistd.h>
# include<stddef.h>
# include<limits.h>
# include<fcntl.h>
# include "Libft/libft.h"

typedef struct s_pipex {
	int file_input;
    int file_output;
    char *path;
    int tube[2];
    char **tab_path;
}				t_pipex;

#endif