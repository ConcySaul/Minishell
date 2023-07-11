/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:14:18 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 16:17:00 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	treat_slash_double_quote(char *str, int i)
{
	i++;
	while (str[i] != '\"')
		i++;
	if (str[i] == '\"')
		i++;
	return (i);
}

int	treat_slash_simple_quote(char *str, int i)
{
	i++;
	while (str[i] != '\'')
		i++;
	if (str[i] == '\'')
		i++;
	return (i);
}

char	*treat_dollar(char *str, t_env *envi)
{
	int		i;
	char	*dest;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\"')
			i = treat_slash_double_quote(str, i);
		if (str[i] == '\'')
			i = treat_slash_simple_quote(str, i);
		if (str[i] == '$')
		{
			dest = remove_dollar2(str, i, envi);
			return (dest);
		}
		else
			i++;
	}
	return (str);
}
