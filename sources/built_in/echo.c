/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:42:38 by adegadri          #+#    #+#             */
/*   Updated: 2022/03/02 11:30:30 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	if_in_end_echo(t_lexer *lexer, int i)
{
	if (check_n_echo(lexer, i) || lexer->command[i].token[1].n == 1)
		echo_n(i, lexer);
	else
		echo_(i, lexer);
}

void	free_process_echo(t_lexer *lexer, char *temp, char **strs)
{
	free (lexer->command[lexer->i].token[1].data);
	lexer->command[lexer->i].token[1].data = ft_strdup(temp);
	free(temp);
	free_double_array(strs);
}

int	strs_len_count(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	process_of_echo(char **strs, char *temp, char *temp2, t_lexer *lexer)
{
	int	ret;

	ret = check_n_echo2(strs);
	if (ret)
	{
		temp = ft_strdup(strs[ret]);
		ret++;
		while (strs[ret])
		{
			if (ret < strs_len_count(strs))
			{	
				temp2 = ft_strdup(temp);
				free(temp);
				temp = ft_strjoin(temp2, " ");
				free(temp2);
			}
			temp2 = ft_strdup(temp);
			free(temp);
			temp = ft_strjoin(temp2, strs[ret]);
			free(temp2);
			ret++;
		}
		free_process_echo(lexer, temp, strs);
	}
}

void	built_in_echo(int i, t_lexer *lexer)
{
	char	**strs;
	char	*temp;
	char	*temp2;

	temp = NULL;
	temp2 = NULL;
	if (lexer->command[i].n_token > 1)
	{
		if (lexer->command[i].token[1].n == 1)
		{
			strs = ft_split(lexer->command[i].token[1].data, ' ');
			process_of_echo(strs, temp, temp2, lexer);
		}
		if_in_end_echo(lexer, i);
	}
}
