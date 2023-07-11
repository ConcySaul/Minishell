/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:29:04 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/02 11:28:21 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_only_n(char *str)
{
	int	i;
	int	len;
	int	count;

	count = 0;
	len = ft_strlen(str);
	i = 1;
	if (str[0] == '-')
	{
		count++;
		while (str[i])
		{
			if (str[i] == 'n')
				count++;
			i++;
		}
	}
	if (count == len)
		return (1);
	else
		return (0);
}

int	check_n_echo(t_lexer *lexer, int i)
{
	int	j;
	int	flag;

	j = 1;
	flag = 0;
	while (j < lexer->command[i].n_token)
	{
		if (is_only_n(lexer->command[i].token[j].data))
		{
			flag += 1;
			j++;
		}
		else
			break ;
	}
	return (flag);
}

int	check_n_echo2(char **strs)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (strs[i])
	{
		if (is_only_n(strs[i]))
		{
			flag += 1;
			i++;
		}
		else
			break ;
	}
	return (flag);
}

void	echo_n(int i, t_lexer *lexer)
{
	int	j;

	j = check_n_echo(lexer, i) + 1;
	while (j < lexer->command[i].n_token)
	{
		if (lexer->command[i].token[j].type == 1)
		{
			printf("%s", lexer->command[i].token[j].data);
			if (j < lexer->command[i].n_token - 1)
				printf("%c", ' ');
		}
		j++;
	}
}

void	echo_(int i, t_lexer *lexer)
{
	int		j;

	j = 1;
	while (j < lexer->command[i].n_token)
	{
		if (lexer->command[i].token[j].type == 1)
		{
			printf("%s", lexer->command[i].token[j].data);
			if (j < lexer->command[i].n_token - 1)
				printf("%c", ' ');
		}
		j++;
	}
	printf("\n");
}
