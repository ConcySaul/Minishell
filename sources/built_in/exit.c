/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:56:28 by adegadri          #+#    #+#             */
/*   Updated: 2022/03/01 13:30:25 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	is_charspe(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == '<' && str[i + 1] == '<') || \
		(str[i] == '>' && str[i + 1] == '>'))
		{
			if (str[i] == '<')
				printf("%s\n", "bash: syntax error near unexpected token '<<'");
			else
				printf("%s\n", "bash: syntax error near unexpected token '>>'");
			return (1);
		}
		else if ((str[i] == '<' && str[i + 1] != '<') || \
		(str[i] == '>' && str[i + 1] != '>'))
		{
			if (str[i] == '<')
				printf("%s\n", "bash: syntax error near unexpected token '<'");
			else
				printf("%s\n", "bash: syntax error near unexpected token '>'");
			return (2);
		}
	}
	return (0);
}

int	is_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/' && str[i + 1] != '/')
		{
			printf("%s\n", "bash: syntax error near unexpected token '<'");
			return (1);
		}
		else if (str[i] == '>' && str[i + 1] != '>')
		{
			printf("%s\n", "bash: syntax error near unexpected token '>'");
			return (1);
		}
		i++;
	}
	return (0);
}

void	built_in_exit(t_lexer *lexer,
int (*fd)[2048][2], t_env *envi, int i)
{
	if (lexer->command[i].n_token > 1
		&& !is_str_num(lexer->command[i].token[1].data))
	{
		g_exit = 2;
		ft_putstr_error("SoloMinishell: exit: ");
		ft_putstr_error(lexer->command[i].token[1].data);
		ft_putstr_error(": numeric argument required\n");
	}
	else if (lexer->command[i].n_token > 2)
	{
		ft_putstr_error("SoloMinishell: exit: too many arguments\n");
		g_exit = 1;
	}
	else if (lexer->command[i].n_token == 2)
	{
		g_exit = ft_atoi(lexer->command[i].token[1].data);
		if (g_exit < 0)
			g_exit = (g_exit % -256) + 256;
		else
			g_exit = g_exit % 256;
	}
	if (lexer->n_command == 1)
		free_if_lexer1(lexer, envi, fd);
}
