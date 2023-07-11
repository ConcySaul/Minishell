/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:05:45 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/02 12:02:14 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	process_start(char *s, char c)
{
	int	i;

	i = 0;
	while (i < ft_strlen(s) && s[i] != c)
	{	
		if (s[i] == '\'')
			i = process_cpy(s, i);
		if (s[i] == '\"')
			i = process_cpy2(s, i);
		else
			i++;
	}
	return (i);
}

char	*ft_cpy(char *s, char c)
{
	char	*dest;
	int		i;

	i = process_start(s, c);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i] == '\'')
			i = process_cpy3(s, i, dest);
		else if (s[i] == '\"')
			i = process_cpy4(s, i, dest);
		else
		{
			dest[i] = s[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
