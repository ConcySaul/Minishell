/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:01:44 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 20:56:33 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	if_is_built_in(t_lexer *lexer, int (*fd)[2048][2], t_env *envi, \
int i)
{
	close_fds(fd, lexer->n_command);
	exec_built_in(i, envi, lexer);
	free(lexer->to_free.id_fork);
	free_exp_tab(envi);
	free(lexer->to_free.buff);
	free_double_array(lexer->to_free.str);
	free_lexer(lexer);
	free_double_array(envi->myenv);
	free_env(envi);
	exit(EXIT_SUCCESS);
}

void	if_execve1(t_lexer *lexer, t_env *envi, \
int i)
{				
	ft_putstr_fd("Solo_Minishell: ", 2);
	perror(lexer->command[i].token[0].data);
	free_exp_tab(envi);
	free(lexer->to_free.buff);
	free_double_array(lexer->to_free.str);
	free(lexer->to_free.id_fork);
	free_double_array(envi->myenv);
	free_lexer(lexer);
	free_env(envi);
	g_exit = 127;
	exit(g_exit);
}

void	if_execve2(t_lexer *lexer, t_env *envi, \
int i)
{
	perror(lexer->command[i].path);
	free_exp_tab(envi);
	free(lexer->to_free.buff);
	free_double_array(lexer->to_free.str);
	free(lexer->to_free.id_fork);
	free_double_array(envi->myenv);
	free_lexer(lexer);
	free_env(envi);
	g_exit = 127;
	exit(g_exit);
}

void	if_else(t_lexer *lexer, t_env *envi, \
int i)
{
	ft_putstr_fd("Solo_Minishell: ", 2);
	ft_putstr_fd(lexer->command[i].token[0].data, 2);
	ft_putstr_fd(": command not found\n", 2);
	free_exp_tab(envi);
	free(lexer->to_free.buff);
	free_double_array(lexer->to_free.str);
	free(lexer->to_free.id_fork);
	free_double_array(envi->myenv);
	free_env(envi);
	free_lexer(lexer);
	g_exit = 127;
	exit(g_exit);
}

void	treat_fork(t_lexer *lexer, int (*fd)[2048][2], char **env,
t_env *envi)
{
	treat_redirection(lexer, fd, lexer->i, lexer->n_command);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	if (is_built_in(lexer->command[lexer->i].token[0].data) == 1)
		if_is_built_in(lexer, fd, envi, lexer->i);
	else
	{
		close_fds(fd, lexer->n_command);
		lexer->command[lexer->i].path = \
		find_bin(&lexer->command[lexer->i], envi);
		if (has_slash(lexer->command[lexer->i].token[0].data))
		{
			if (execve(lexer->command[lexer->i].token[0].data,
					lexer->command[lexer->i].args, env) == -1)
				if_execve1(lexer, envi, lexer->i);
		}
		else if (lexer->command[lexer->i].path)
		{
			if (execve(lexer->command[lexer->i].path,
					lexer->command[lexer->i].args, env) == -1)
				if_execve2(lexer, envi, lexer->i);
		}
		else
			if_else(lexer, envi, lexer->i);
	}
}
