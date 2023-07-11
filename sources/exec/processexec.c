/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processexec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:56:31 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 20:56:07 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	process_export(t_lexer *lexer, int i, t_env *envi, char **env)
{
	if (lexer->command[i].n_token == 1)
		built_in_env_exp(envi);
	else if (lexer->command[i].token[1].data
		&& check_name_var(lexer->command[i].token[1].data))
		printf("export: not an identifier: %s\n",
			lexer->command[i].token[1].data);
	if (lexer->command[i].n_token > 2)
		export_error(lexer, i);
	else if (lexer->command[i].n_token == 2)
	{
		if (check_if_equal(lexer->command[i].token[1].data))
		{
			if (!check_if_in_env(envi, lexer->command[i].token[1].data))
				built_in_export(envi, lexer->command[i].token[1].data);
			else
				change_val(envi, lexer->command[i].token[1].data);
		}
		else
		{
			add_to_export(envi, lexer->command[i].token[1].data);
		}
	}
	set_env(envi);
	env = envi->myenv;
}

void	process_cd(t_lexer *lexer, int i, t_env *envi)
{
	if (lexer->command[i].n_token > 1)
		built_in_cd(envi, lexer->command[i].token[1].data);
	else
		if_only_cd(envi);
}

void	process_unset(t_lexer *lexer, int i, t_env *envi, char **env)
{
	int	j;

	j = 1;
	while (j < lexer->command[i].n_token)
	{
		if (check_if_in_env(envi, lexer->command[i].token[j].data))
			built_in_unset(envi, lexer->command[i].token[j].data);
		else
		{
			j++;
			continue ;
		}
	}
	set_env(envi);
	env = envi->myenv;
}

void	make_pipe(t_lexer *lexer, int (*fd)[2048][2])
{
	int	i;

	i = 0;
	while (i <= lexer->n_command)
	{
		if (pipe((*fd)[i]) == -1)
			return ;
		i++;
	}
}

void	process_fork(t_lexer *lexer, char **env, t_env *envi,
int (*fd)[2048][2])
{
	if (!ft_strcmp(lexer->command[lexer->i].token[0].data, "./minishell"))
		set_lvl(env, envi);
	lexer->to_free.id_fork[lexer->i] = fork();
	if (lexer->to_free.id_fork[lexer->i] < 0)
		return ;
	else if (lexer->to_free.id_fork[lexer->i] == 0)
		treat_fork(lexer, fd, env, envi);
}
