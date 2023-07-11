/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:15:25 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/02 14:54:43 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	process_exec_command(t_lexer *lexer, t_env *envi, int (*fd)[2048][2], \
char **env)
{
	if (!ft_strcmp(lexer->command[lexer->i].token[0].data, "~"))
		process_cd(lexer, lexer->i, envi);
	else if (!ft_strcmp(lexer->command[lexer->i].token[0].data, "cd"))
		process_cd(lexer, lexer->i, envi);
	else if (!ft_strcmp(lexer->command[lexer->i].token[0].data, "export"))
		process_export(lexer, lexer->i, envi, env);
	else if (!ft_strcmp(lexer->command[lexer->i].token[0].data, "unset")
		&& lexer->command[lexer->i].n_token > 1)
		process_unset(lexer, lexer->i, envi, env);
	else if (!ft_strcmp(lexer->command[lexer->i].token[0].data, "exit"))
		built_in_exit(lexer, fd, envi, lexer->i);
	else
		process_fork(lexer, env, envi, fd);
}

void	exec_command(t_env *envi, t_lexer *lexer,
char **env)
{
	int		fd[2048][2];

	lexer->to_free.id_fork = NULL;
	make_pipe(lexer, &fd);
	lexer->to_free.id_fork = (int *)malloc(sizeof(int) * lexer->n_command);
	process_redir(lexer, &fd);
	lexer->i = -1;
	while (++lexer->i < lexer->n_command)
	{
		lexer->to_free.id_fork[lexer->i] = 42;
		signal(SIGINT, SIG_IGN);
		process_exec_command(lexer, envi, &fd, env);
	}
	wait_and_close(lexer, &fd);
}
