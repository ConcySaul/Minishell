/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:52:25 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 14:58:54 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*remove_dollar(char *str, int index, t_env *envi, t_token *token)
{
	int		j;
	char	*pre_save;
	char	*post_save;
	char	*path;

	path = NULL;
	pre_save = NULL;
	post_save = NULL;
	j = index + 1;
	envi->j_rm = index + 1;
	if (index != 0)
		pre_save = first_save(str, index);
	post_save = get_post_save(str, post_save, envi);
	path = get_path(str, envi, path);
	path = check_tmp(str, path, envi);
	if_tmp(envi, token);
	if_pre_save(pre_save, envi);
	if_post_save(post_save, envi);
	free_rmove(str, path, post_save, pre_save);
	return (envi->tmp);
}
