/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:48:24 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/02 14:25:46 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	if_redir_count(char *str, int *i)
{
	(*i)++;
	while (str[(*i)] && str[(*i)] == ' ')
		(*i)++;
	if (!if_redir1(str, (*i)))
		return (0);
	return (1);
}

int	check_if_space(char *str, int index)
{
	index++;
	while (str[index])
	{
		if (str[index] != ' ')
			return (0);
		index++;
	}
	return (1);
}

int	syntax_err(void)
{
	printf("bash: syntax error near unexpected token `newline'\n");
	return (0);
}

int	check_redirection_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			i = if_slash_simple_quote(str, i);
		if (str[i] == '\"')
			i = if_slash_double_quote(str, i);
		if ((str[i] == '<' || str[i] == '>') && check_if_space(str, i))
			return (syntax_err());
		if (str[i] == '<')
		{
			if (!if_redir1(str, i))
				return (0);
		}
		else if (str[i] == '>')
		{
			if (!if_redir2(str, i))
				return (0);
		}
	}
	return (1);
}
