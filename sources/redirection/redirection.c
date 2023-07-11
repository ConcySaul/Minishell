/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:46:40 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 20:34:35 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	process_treat_redirection(t_lexer *lexer, int (*fd)[2048][2], \
int fd_index, int i)
{
	t_command	*command;

	command = &lexer->command[fd_index];
	while (i < command->n_token)
	{
		if (command->token[i].type == FILE_OUT || \
		command->token[i].type == FILE_OUT_SUR)
		{
			lexer->ret_1 = 1;
			dup2((*fd)[fd_index + 1][1], STDOUT_FILENO);
		}
		else if (command->token[i].type == FILE_IN || \
		command->token[i].type == HERE_DOC)
		{
			lexer->ret_2 = 1;
			dup2((*fd)[fd_index][0], STDIN_FILENO);
		}
		i++;
	}
}

int	treat_redirection(t_lexer *lexer, int (*fd)[2048][2], \
int fd_index, int n_command)
{
	t_command	*command;
	int			i;

	i = 0;
	command = &lexer->command[fd_index];
	process_treat_redirection(lexer, fd, fd_index, i);
	if (fd_index + 1 < n_command && !lexer->ret_1)
		dup2((*fd)[fd_index + 1][1], STDOUT_FILENO);
	if (fd_index > 0 && !lexer->ret_2)
		dup2((*fd)[fd_index][0], STDIN_FILENO);
	if (!lexer->ret_1 && (fd_index < n_command - 1) && \
	has_heredoc(&lexer->command[fd_index + 1]))
		return (1);
	return (0);
}

int	has_heredoc(t_command *command)
{
	int	i;

	i = 0;
	while (i < command->n_token)
	{
		if (command->token[i].type == HERE_DOC)
			return (1);
		i++;
	}
	return (0);
}

char	*ret_limitor(int ret, int *flag, char *eof, char *limitor)
{
	if (ret)
		limitor = set_flag_limitor(flag, limitor, eof);
	else
		limitor = ft_strdup(eof);
	return (limitor);
}

void	here_doc(char *eof, int (*fd)[2048][2], int i)
{
	char	*line;
	char	*limitor;
	char	*no_dollar;
	int		ret;
	int		flag;

	flag = 0;
	limitor = NULL;
	no_dollar = NULL;
	ret = has_quote(eof);
	limitor = ret_limitor(ret, &flag, eof, limitor);
	line = readline("> ");
	while (line && ft_strcmp(line, limitor) != 0)
	{
		if (line[0] == '$' && flag == 1)
			process_heredoc(line, i, fd);
		else if (line[0] == '$' && flag == 0)
			process_heredoc2(no_dollar, i, fd, line);
		else
			process_heredoc3(line, i, fd);
		line = readline("> ");
	}
	free_heredoc(line, limitor);
}
