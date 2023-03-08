/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 04:51:13 by jules             #+#    #+#             */
/*   Updated: 2023/03/08 16:48:17 by jvasseur         ###   ########.fr       */
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
# include <stdio.h>

typedef struct s_pipex {
	int file_input;
    int file_output;
    char *path;
    int tube[2];
    char **tab_path;
}				t_pipex;


void	msg_send_error(char *err);
int send_err_message(char *str);

#endif