/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 04:35:00 by jules             #+#    #+#             */
/*   Updated: 2023/03/08 16:47:52 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_send_error(char *err)
{
	perror(err);
	exit (1);
}

int send_err_message(char *str)
{
    write(2, str, ft_strlen(str));
    return (1);
}