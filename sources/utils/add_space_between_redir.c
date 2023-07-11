/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space_between_redir.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:05:42 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 16:25:18 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	add_space_btween_redir_process01(char *str, int len)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if ((str[i] != '>' && str[i] != '<')
			&& (str[i + 1] == '>' || str[i + 1] == '<'))
			len++;
		else if ((str[i] == '>' || str[i] == '<') && (str[i + 1] != '>'
				&& str[i + 1] != '<' && str[i + 1] != ' '))
			len++;
		i++;
	}
	return (len);
}

char	*add_space_btween_redir_process02(char *str, int i, int j, char *dest)
{
	while (i < ft_strlen(str))
	{
		if ((str[i] != '>' && str[i] != '<') && (str[i + 1] == '>'
				|| str[i + 1] == '<'))
		{
			dest[j] = str[i];
			j++;
			dest[j] = ' ';
		}
		else if ((str[i] == '>' || str[i] == '<') && (str[i + 1] != '>'
				&& str[i + 1] != '<' && str[i + 1] != ' '))
		{
			dest[j] = str[i];
			j++;
			dest[j] = ' ';
		}
		else
			dest[j] = str[i];
		j++;
		i++;
	}
	free (str);
	dest[j] = '\0';
	return (dest);
}

char	*add_space_between_redir(char *str)
{
	int		len;
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	len = add_space_btween_redir_process01(str, len);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest = add_space_btween_redir_process02(str, i, j, dest);
	return (dest);
}
