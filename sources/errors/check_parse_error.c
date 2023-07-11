/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:55:47 by sconcy            #+#    #+#             */
/*   Updated: 2022/02/28 17:57:48 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	process_of_check_parse_error(char *str, int i)
{
	while (str[i])
	{
		i = check_quote_and_skip(str, i);
		if (str[i] == '|')
		{
			i++;
			while (str[i] == ' ')
				i++;
			if (str[i] == '|')
			{
				printf("Error : double pipe\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_parse_error(char *str)
{
	int	i;

	i = 0;
	if (check_quote(str))
	{
		write (1, "unclosed dquote or quote\n", 25);
		return (0);
	}
	if (!check_redirection_error(str))
		return (0);
	i = 0;
	if (str[0] == '|')
	{
		printf("bash: syntax error near unexpected token `|'\n");
		return (0);
	}
	if (str[ft_strlen(str) - 1] == '|')
	{
		printf("bash: syntax error near unexpected token `|'\n");
		return (0);
	}
	if (!process_of_check_parse_error(str, i))
		return (0);
	return (1);
}
