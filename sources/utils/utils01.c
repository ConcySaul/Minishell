/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:00:06 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 16:40:42 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strdup(char *str)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!str)
		return (NULL);
	while (str[len])
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (0);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

char	*process_remove_space(char *str, char *dest, int i, int len)
{
	int	j;

	j = 0;
	while (j < len)
	{
		if (str[i] == ' ' && i == len - 1)
			break ;
		dest[j] = str[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*remove_space(char *str)
{
	int		i;
	int		len;
	char	*dest;

	len = ft_strlen(str);
	if (str[len - 1] == ' ')
		len--;
	if (str[0] == ' ')
		len--;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	if (str[0] == ' ')
		i++;
	dest = process_remove_space(str, dest, i, len);
	return (dest);
}

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}
