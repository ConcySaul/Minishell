/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:02:12 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/02 12:20:22 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void	process_split(char *s, char c)
// {

// }

// int	process_split2(char *s, char c, int i)
// {
// }

char	*process_split(char *s, char c)
{		
	while (*s && *s != c)
	{
		if (*s == '\'')
		{
			s++;
			while (*s && *s != '\'')
				s++;
			if (*s == '\'')
				s++;
		}
		else if (*s == '\"')
		{
			s++;
			while (*s && *s != '\"')
				s++;
			if (*s == '\"')
				s++;
		}
		else
			s++;
	}
	return (s);
}

char	**malloc_s(char *s, char c, char **dest)
{
	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!dest)
		return (NULL);
	return (dest);
}

char	**ft_split(char *s, char c)
{
	char	**dest;
	int		i;

	dest = NULL;
	dest = malloc_s(s, c, dest);
	if (!dest)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			dest[i] = ft_cpy(s, c);
			s = process_split(s, c);
			if (dest[i] == NULL)
				clean(dest, i);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	dest[i] = NULL;
	return (dest);
}
