/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processexec2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:43:27 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 19:58:21 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	process_redir(t_lexer *lexer, int (*fd)[2048][2])
{
	int	i;

	i = -1;
	while (++i < lexer->n_command)
		make_redirection(&lexer->command[i], fd, i);
}

void	wait_and_close(t_lexer *lexer, int (*fd)[2048][2])
{
	close_fds(fd, lexer->n_command);
	wait_all_pid(lexer->to_free.id_fork, lexer->n_command);
}
