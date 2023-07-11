/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_space_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:36:38 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 16:43:23 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*process_rmove_space_env(char *str, char *new_char)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		new_char[j] = str[i];
		i++;
		j++;
	}
	new_char[j] = 0;
	free(str);
	return (new_char);
}

char	*process_rmove_space_env2(char *str, char *new_char, int limit)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] && str[i] == ' ')
		i--;
	while (j < limit)
	{
		new_char[j] = str[i];
		i++;
		j++;
	}
	new_char[j] = 0;
	free(str);
	return (new_char);
}

char	*remove_space_from_env(char *str)
{
	int		i;
	int		j;
	char	*new_char;

	i = 0;
	j = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		i++;
		j++;
	}
	new_char = (char *)malloc(j + 1);
	if (!new_char)
		return (NULL);
	new_char = process_rmove_space_env(str, new_char);
	return (new_char);
}

char	*remove_space_from_env2(char *str)
{
	int		i;
	int		j;
	int		limit;
	char	*new_char;

	i = ft_strlen(str) - 1;
	j = 0;
	while (str[i] && str[i] == ' ')
		i--;
	while (i > -1)
	{
		i--;
		j++;
	}
	limit = j;
	new_char = (char *)malloc(j + 1);
	if (!new_char)
		return (NULL);
	new_char = process_rmove_space_env2(str, new_char, limit);
	return (new_char);
}
