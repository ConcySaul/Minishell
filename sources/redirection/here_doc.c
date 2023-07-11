/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:47:48 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 20:20:17 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	process_heredoc(char *line, int i, int (*fd)[2048][2])
{
	write((*fd)[i][1], line, ft_strlen(line));
	write((*fd)[i][1], "\n", 1);
	free(line);
}

void	process_heredoc2(char *no_dollar, int i, int (*fd)[2048][2], char *line)
{
	char	*var;

	no_dollar = remove_dollar_from_string(line);
	var = getenv(no_dollar);
	write((*fd)[i][1], var, ft_strlen(var));
	write((*fd)[i][1], "\n", 1);
	free(no_dollar);
	free(line);
}

void	process_heredoc3(char *line, int i, int (*fd)[2048][2])
{
	write((*fd)[i][1], line, ft_strlen(line));
	write((*fd)[i][1], "\n", 1);
	free(line);
}

void	free_heredoc(char *line, char *limitor)
{
	if (line)
		free(line);
	if (limitor)
		free(limitor);
}

char	*set_flag_limitor(int *flag, char *limitor, char *eof)
{
	*flag = 1;
	limitor = remove_quote_from_limitor(eof);
	return (limitor);
}
