/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processexec3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:51:12 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 20:56:22 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	process_builtin(t_lexer *lexer, t_env *envi, int (*fd)[2048][2])
{
	close_fds(fd, lexer->n_command);
	exec_built_in(lexer->i, envi, lexer);
	free(lexer->to_free.id_fork);
	free_exp_tab(envi);
	free(lexer->to_free.buff);
	free_double_array(lexer->to_free.str);
	free_lexer(lexer);
	free_double_array(envi->myenv);
	free_env(envi);
	exit(EXIT_SUCCESS);
}

void	process_fork1(t_lexer *lexer, char **env,
t_env *envi)
{
	if (execve(lexer->command[lexer->i].token[0].data,
			lexer->command[lexer->i].args, env) == -1)
	{	
		ft_putstr_fd("Solo_Minishell: ", 2);
		perror(lexer->command[lexer->i].token[0].data);
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
}

void	process_fork2(t_lexer *lexer, char **env, t_env *envi)
{
	if (execve(lexer->command[lexer->i].path,
			lexer->command[lexer->i].args, env) == -1)
	{
		perror(lexer->command[lexer->i].path);
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
}

void	process_fork3(t_lexer *lexer, t_env *envi)
{
	ft_putstr_fd("Solo_Minishell: ", 2);
	ft_putstr_fd(lexer->command[lexer->i].token[0].data, 2);
	ft_putstr_fd(": command not found\n", 2);
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
