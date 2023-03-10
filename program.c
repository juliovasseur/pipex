/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:26:41 by jules             #+#    #+#             */
/*   Updated: 2023/03/12 03:20:40 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->arg_cmd[i])
	{
		free(pipex->arg_cmd[i]);
		i++;
	}
	free(pipex->arg_cmd);
	free(pipex->cmd);
}

char	*cmd(char **path, char *command)
{
    int     i;
	char	*cmd;

    i = 0;
	while (path[i])
	{
		cmd = ft_strjoin(path[i], command);
        if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}

void    child_prog(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->tube[1], STDOUT_FILENO);
	dup2(pipex->file_input, STDIN_FILENO);
    pipex->arg_cmd = ft_split(argv[2], ' ');
	pipex->cmd = cmd(pipex->tab_path, pipex->arg_cmd[0]);
	if (!pipex->cmd)
	{
		child_free(pipex);
		close(pipex->tube[0]);
		msg_write_error("Error cmd");
		exit(1);
	}
	close(pipex->tube[0]);
	execve(pipex->cmd, pipex->arg_cmd, envp);
}

void	second_child_prog(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->tube[0], STDIN_FILENO);
	dup2(pipex->file_output, STDOUT_FILENO);
    pipex->arg_cmd = ft_split(argv[3], ' ');
	pipex->cmd = cmd(pipex->tab_path, pipex->arg_cmd[0]);
	if (!pipex->cmd)
	{
		child_free(pipex);
		close(pipex->tube[1]);
		msg_write_error("Error cmd");
		exit(1);
	}
	close(pipex->tube[1]);
	execve(pipex->cmd, pipex->arg_cmd, envp);
}
