/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:01:06 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/02 13:43:35 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*first_save(char *str, int index)
{
	int		i;
	char	*save;

	i = 0;
	while (str[i] && i < index)
		i++;
	save = (char *)malloc(i + 1);
	if (!save)
		return (NULL);
	i = 0;
	while (str[i] && i < index)
	{
		save[i] = str[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}

char	*last_save(char *str, int i)
{
	int		j;
	int		temp;
	char	*save;

	temp = i;
	j = 0;
	while (str[i])
	{
		i++;
		j++;
	}
	save = (char *)malloc(j + 1);
	if (!save)
		return (NULL);
	j = 0;
	i = temp;
	while (str[i])
	{
		save[j] = str[i];
		i++;
		j++;
	}
	save[j] = 0;
	return (save);
}

int	skip_slash(char *str, int i)
{
	i++;
	while (str[i] != '\'')
		i++;
	if (str[i] == '\'')
		i++;
	return (i);
}

char	*treat_dollar_in_dquote(char *str, t_env *envi, t_token *token)
{
	int		i;
	char	*dest;

	i = -1;
	while (++i < ft_strlen(str))
	{
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"')
			{
				if (str[i] == '$')
				{
					dest = remove_dollar(str, i, envi, token);
					return (dest);
				}
				i++;
			}
			if (str[i] == '\"')
				i++;
		}
		if (str[i] == '\'')
			i = skip_slash(str, i);
	}
	return (str);
}

int	is_only_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
			return (0);
	}
	return (1);
}
