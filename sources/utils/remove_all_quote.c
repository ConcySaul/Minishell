/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_all_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:28:40 by adegadri          #+#    #+#             */
/*   Updated: 2022/03/01 17:27:28 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	process_rmove_quote(char *str, int i, int *count)
{
	i++;
	while (str[i] && str[i] != '\'')
	{
		i++;
		(*count)++;
	}
	if (str[i] == '\'')
		i++;
	return (i);
}

int	process_rmove_quote2(char *str, int i, int *count, char *dest)
{
	i++;
	while (str[i] != '\'')
	{
		dest[(*count)] = str[i];
		i++;
		(*count)++;
	}
	if (str[i] == '\'')
		i++;
	return (i);
}

int	rmove_quote1(char *str, int i, int count)
{
	while (str[i])
	{
		if (str[i] == '\'')
			i = process_rmove_quote(str, i, &count);
		else if (str[i] == '\"')
		{
			i++;
			while (i < ft_strlen(str) && str[i] != '\"')
			{
				i++;
				count++;
			}
			if (str[i] == '\"')
				i++;
		}
		else
		{
			i++;
			count++;
		}
	}
	return (count);
}

char	*rmove_quote2(char *str, int i, int count, char *dest)
{
	while (str[i])
	{
		if (str[i] == '\'')
			i = process_rmove_quote2(str, i, &count, dest);
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\"')
			{
				dest[count] = str[i];
				i++;
				count++;
			}
			if (str[i] == '\"')
				i++;
		}
		else
			dest[count++] = str[i++];
	}
	dest[count] = '\0';
	free(str);
	return (dest);
}
