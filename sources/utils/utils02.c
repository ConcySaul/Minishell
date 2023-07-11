/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:07:23 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 16:00:36 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_slash_with_quote(char *s, int i)
{
	if (s[i] == '\"')
	{
		i++;
		while (s[i] && s[i] != '\"')
			i++;
		if (s[i] && s[i] == '\"')
			i++;
	}
	if (s[i] == '\'')
	{
		i++;
		while (s[i] && s[i] != '\'')
			i++;
		if (s[i] && s[i] == '\'')
			i++;
	}
	return (i);
}

int	is_dollar(char *s)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (s)
	{
		len = ft_strlen(s);
		while (i < len)
		{
			if (s[i] == '\"')
			{
				i++;
				while (s[i] && s[i] != '\"')
					i++;
				if (s[i] == '\n')
					i++;
			}
			i = is_slash_with_quote(s, i);
			if (s[i] == '$')
				return (1);
			i += 1;
		}
	}
	return (0);
}

int	is_dollar_2(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	if (s)
	{
		len = ft_strlen(s);
		while (++i < len)
		{
			if (s[i] == '\"')
			{
				i++;
				while (i < len && s[i] != '\"')
				{
					if (s[i] == '$')
						return (1);
					i++;
				}
				if (s[i] == '\"')
					i++;
			}
		}
	}
	return (0);
}

char	*ft_join(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(len1 + len2 + 1);
	i = -1;
	while (++i < len1)
		new[i] = s1[i];
	j = 0;
	while (i < len1 + len2)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
