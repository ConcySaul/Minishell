/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_remove_dollar1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:03:40 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 15:02:36 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_i(char *str, t_env *envi)
{
	int	i;
	int	j;

	i = 0;
	j = envi->j_rm;
	while (str[j] && (str[j] != ' ' && str[j] != '\'' && \
	str[j] != '\"' && str[j] != '$'))
	{
		j++;
		i++;
	}
	return (i);
}

void	if_tmp(t_env *envi, t_token *token)
{
	if (envi->tmp)
	{
		envi->tmp = remove_space_from_env(envi->tmp);
		envi->tmp = remove_space_from_env2(envi->tmp);
		if (has_n(envi->tmp))
			token->n = 1;
	}
	if (!envi->tmp)
		envi->tmp = ft_strdup(" ");
}

char	*check_tmp(char *str, char *path, t_env *envi)
{
	int	i;
	int	j;

	i = 0;
	j = envi->j_rm;
	while (str[j] && (str[j] != ' ' && str[j] != '\'' && \
	str[j] != '\"' && str[j] != '$'))
	{
		path[i] = str[j];
		j++;
		i++;
	}
	path[i] = 0;
	if (!ft_strcmp(path, "?"))
		envi->tmp = ft_itoa(g_exit);
	else if (i == 0)
		envi->tmp = ft_strdup("$");
	else
	{
		envi->tmp = ft_strdup(check_env(envi, path));
	}
	return (path);
}

char	*get_path(char *str, t_env *envi, char *path)
{
	int	j;
	int	i;

	j = envi->j_rm;
	i = 0;
	while (str[j] && (str[j] != ' ' && str[j] != '\'' && \
	str[j] != '\"' && str[j] != '$'))
	{
		i++;
		j++;
	}
	path = (char *)malloc(sizeof(char) * (i + 1));
	if (!path)
		return (NULL);
	return (path);
}
