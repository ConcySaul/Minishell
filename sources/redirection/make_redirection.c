/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:50:33 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 20:19:05 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	process_make_redir(int (*fd)[2048][2], int fd_index,
t_command *command, int i)
{
	close((*fd)[fd_index + 1][1]);
	(*fd)[fd_index + 1][1] = open(command->token[i + 1].data, \
	O_RDWR | O_CREAT | O_TRUNC, 0644);
	if ((*fd)[fd_index + 1][1] < 0)
		return (0);
	return (1);
}

int	process_make_redir2(int (*fd)[2048][2], int fd_index,
t_command *command, int i)
{
	close((*fd)[fd_index + 1][1]);
	(*fd)[fd_index + 1][1] = open(command->token[i + 1].data, \
	O_RDWR | O_CREAT | O_APPEND, 0644);
	if ((*fd)[fd_index + 1][1] < 0)
		return (0);
	return (1);
}

int	process_make_redir3(int (*fd)[2048][2], int fd_index,
t_command *command, int i)
{
	if (access(command->token[i + 1].data, R_OK) == 0)
	{
		close((*fd)[fd_index][0]);
		(*fd)[fd_index][0] = open(command->token[i + 1].data, O_RDONLY);
		if ((*fd)[fd_index][0] < 0)
			return (0);
	}
	else
	{
		printf("bash: %s: No such file or directory\n",
			command->token[i + 1].data);
		return (0);
	}
	return (1);
}

void	make_redirection(t_command *command, int (*fd)[2048][2], int fd_index)
{
	int	i;

	i = 0;
	while (i < command->n_token)
	{
		if (command->token[i].type == FILE_OUT)
		{
			if (!process_make_redir(fd, fd_index, command, i))
				return ;
		}
		else if (command->token[i].type == FILE_OUT_SUR)
		{
			if (!process_make_redir2(fd, fd_index, command, i))
				return ;
		}
		else if (command->token[i].type == FILE_IN)
		{
			if (!process_make_redir3(fd, fd_index, command, i))
				return ;
		}
		else if (command->token[i].type == HERE_DOC)
			here_doc(command->token[i + 1].data, fd, fd_index);
		i++;
	}
}
