/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_from_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:41:23 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 17:59:46 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	rmove_dol_process02(t_command *command, t_env *envi, int *i, int *j)
{
	if (command->token[(*i)].data[(*j) + 1] && \
	(command->token[(*i)].data[(*j)] == ' ' || \
	command->token[(*i)].data[(*j)] == '$'))
	{
		command->token[(*i)].data = \
		remove_dollar(command->token[(*i)].data, (*j), \
		envi, &command->token[(*i)]);
		(*j)++;
	}
	else
		command->token[(*i)].data = \
		remove_dollar(command->token[(*i)].data, (*j), \
		envi, &command->token[(*i)]);
}

void	rmove_dol_process03(t_command *command, int *i, int *j)
{
	(*j)++;
	while (command->token[(*i)].data[(*j)] && \
	command->token[(*i)].data[(*j)] != '\'')
		(*j)++;
	if (command->token[(*i)].data[(*j)] == '\'')
		(*j)++;
}

void	rmove_dol_process04(t_command *command, t_env *envi, int *i, int *j)
{
	(*j)++;
	while (command->token[(*i)].data[(*j)] && \
	command->token[(*i)].data[(*j)] != '\"')
	{
		if (command->token[(*i)].data[(*j)] == '$')
		{
			if (command->token[(*i)].data[(*j) + 1] && \
			(command->token[(*i)].data[(*j)] == ' ' || \
			command->token[(*i)].data[(*j)] == '$'))
			{
				command->token[(*i)].data = \
				remove_dollar2(command->token[(*i)].data, (*j), envi);
				(*j)++;
			}
			else
				command->token[(*i)].data = \
				remove_dollar2(command->token[(*i)].data, (*j), envi);
		}
		(*j)++;
	}
	if (command->token[(*i)].data[(*j)] == '\"')
		(*j)++;
}

void	rmove_dol_process01(t_command *command, t_env *envi, int *i, int *j)
{
	while ((*j) < ft_strlen(command->token[(*i)].data) && \
	command->token[(*i)].data[(*j)])
	{
		if (command->token[(*i)].data[(*j)] == '$')
			rmove_dol_process02(command, envi, i, j);
		if (command->token[(*i)].data[(*j)] && \
		command->token[(*i)].data[(*j)] == '\'')
			rmove_dol_process03(command, i, j);
		else if (command->token[(*i)].data[(*j)] && \
		command->token[(*i)].data[(*j)] == '\"')
			rmove_dol_process04(command, envi, i, j);
		(*j)++;
	}
}

void	remove_all_dollar_from_command(t_command *command, t_env *envi)
{
	int		i;
	int		j;
	int		k;

	(void)envi;
	j = 0;
	i = 0;
	k = 0;
	while (i < command->n_token)
	{
		j = 0;
		if (command->token[i].type == ARG || \
		command->token[i].type == OPEN_FILE || \
		command->token[i].type == EXIT_FILE || \
		command->token[i].type == EXIT_FILE_RET)
			rmove_dol_process01(command, envi, &i, &j);
		i++;
	}
}
