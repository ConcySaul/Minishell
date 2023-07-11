/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:25:06 by sconcy            #+#    #+#             */
/*   Updated: 2022/02/28 17:55:28 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_quote(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			flag = find_next_quote(str, &i);
		}
		else if (str[i] == '\"')
		{
			i++;
			flag = find_next_dquote(str, &i);
		}
		else
			i++;
	}
	return (flag);
}

int	find_next_quote(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '\'')
		{
			*i += 1;
			return (0);
		}
		*i += 1;
	}
	return (1);
}

int	find_next_dquote(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '\"')
		{
			*i += 1;
			return (0);
		}
		*i += 1;
	}
	return (1);
}
