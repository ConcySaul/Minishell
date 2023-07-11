/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_remove_dollar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:03:28 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 15:43:11 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_rmove(char *str, char *path, char *post_save, char *pre_save)
{
	if (str)
		free(str);
	if (path)
		free(path);
	if (post_save)
		free (post_save);
	if (pre_save)
		free (pre_save);
}

void	if_pre_save(char *pre_save, t_env *envi)
{
	if (pre_save)
	{
		if (envi->tmp)
		{
			envi->tmp2 = ft_strjoin(pre_save, envi->tmp);
			free(envi->tmp);
			envi->tmp = ft_strdup(envi->tmp2);
			free(envi->tmp2);
		}
		else
		{
			free (envi->tmp);
			envi->tmp = ft_strdup(pre_save);
		}
	}
}

void	if_post_save(char *post_save, t_env *envi)
{
	if (post_save)
	{
		if (envi->tmp && ft_strcmp(envi->tmp, " "))
		{
			envi->tmp2 = ft_strjoin(envi->tmp, post_save);
			free(envi->tmp);
			envi->tmp = ft_strdup(envi->tmp2);
			free(envi->tmp2);
		}
		else
		{
			free (envi->tmp);
			envi->tmp = ft_strdup(post_save);
		}
	}
}

char	*cpy_in_path(char *str, char *path, t_env *envi)
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
	return (path);
}

char	*get_post_save(char *str, char *post_save, t_env *envi)
{
	int	j;

	j = envi->j_rm;
	while (str[j] && (str[j] != ' ' && str[j] != '\'' && \
	str[j] != '\"' && str[j] != '$'))
	{
		envi->i_rm++;
		j++;
	}
	if (j < ft_strlen(str) && j > 0)
		post_save = last_save(str, j);
	return (post_save);
}
