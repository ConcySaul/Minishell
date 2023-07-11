/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:57:23 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 17:06:12 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clean(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
	}
	tab = NULL;
}

int	ft_count_word(char const *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			word++;
			while (*s && *s != c)
				s++;
		}
	}
	return (word);
}
