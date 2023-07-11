/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:05:30 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/02 11:46:09 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	process_cpy(char *s, int i)
{
	i++;
	while (s[i] && s[i] != '\'')
		i++;
	if (s[i] == '\'')
		i++;
	return (i);
}

int	process_cpy2(char *s, int i)
{
	i++;
	while (s[i] && s[i] != '\"')
		i++;
	if (s[i] == '\"')
		i++;
	return (i);
}

int	process_cpy3(char *s, int i, char *dest)
{
	dest[i] = s[i];
	i++;
	while (s[i] && s[i] != '\'')
	{
		dest[i] = s[i];
		i++;
	}
	if (s[i] == '\'')
	{
		dest[i] = s[i];
		i++;
	}
	return (i);
}

int	process_cpy4(char *s, int i, char *dest)
{	
	dest[i] = s[i];
	i++;
	while (s[i] && s[i] != '\"')
	{
		dest[i] = s[i];
		i++;
	}
	if (s[i] == '\"')
	{
		dest[i] = s[i];
		i++;
	}
	return (i);
}
