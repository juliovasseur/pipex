/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 04:32:59 by jules             #+#    #+#             */
/*   Updated: 2023/03/08 17:42:34 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env)
{
	while (ft_strncmp("PATH=/nfs", *env, 9))
		(*env)++;
	return (*env + 5);
}

void    create_tab_env(char **s)
{
    int i;
    int j;
    char **str;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (s[i][j])
            j++;
        str[i] = malloc(j + 1);
        i++;
    }
    str = s;
    i = 0;
    while (str[i])
    {
                
    }
    j = 0;
    


    while (str[i])
    {
        j = 0;
        while (str[i][j])
            j++;
        str[i][j] = '/';
        i++;
    }
}    

int main(int argc, char **argv, char **envp)
{

    t_pipex pipex;

    if (argc != 5)
        msg_send_error("Input Error, argument number invalid");
    pipex.file_input = open(argv[1], O_RDONLY);
    if (pipex.file_input == -1)
        send_err_message("Error file input");
    pipex.file_output = open(argv[4], O_RDONLY);
    if (pipex.file_output == -1)
        send_err_message("Error file output");
    if (pipe(pipex.tube) == -1)
		msg_send_error("Error pipe");
    pipex.path = find_path(envp);
    pipex.tab_path = ft_split(pipex.path, ':');
    create_tab_env(pipex.tab_path);
    int j = 0;
    while (pipex.tab_path[j])
    {
        printf("%s\n", pipex.tab_path[j]);
        j++;
    }
    
}