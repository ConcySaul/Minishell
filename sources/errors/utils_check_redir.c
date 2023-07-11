/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:08:23 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/02 13:09:44 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	if_slash_simple_quote(char *str, int i)
{
	i++;
	while (str[i] && str[i] != '\'')
		i++;
	return (i);
}

int	if_slash_double_quote(char *str, int i)
{
	i++;
	while (str[i] && str[i] != '\"')
		i++;
	return (i);
}

int	if_redir1(char *str, int i)
{
	if (!put_err1(str, i))
		return (0);
	return (1);
}

int	if_redir2(char *str, int i)
{
	if (!put_err2(str, i))
		return (0);
	return (1);
}
