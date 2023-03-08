/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 04:32:59 by jules             #+#    #+#             */
/*   Updated: 2023/03/08 05:38:48 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *env)
{
	while (ft_strncmp("PATH", env, 4))
		env++;
	return (env);
}

int main(int argc, char **argv)
{

    t_pipex pipex;

    if (argc != 5)
        return (msg_send_error("Input Error, argument number invalid"));
    pipex->file_input = open(argv[1], O_RDONLY);
    if (pipex->file_input == -1)
        send_err_message("Error file input");
    pipex->file_output = open(argv[5], O_RDONLY);
    if (pipex->file_output == -1)
        send_err_message("Error file output");
    if (pipe(pipex->tube) == -1)
		msg_send_error("Error pipe");
    pipex->path = find_path(env);
    pipex->tab_path = ft_split(pipex.paths, ':');


    

}