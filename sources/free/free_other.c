/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:29:23 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/02 14:23:26 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_check_if_in_export(char *vardup, char *check)
{
	if (vardup)
	{
		free (vardup);
		vardup = NULL;
	}
	if (check)
	{
		free (check);
		check = NULL;
	}
}

void	free_if_lexer1(t_lexer *lexer, t_env *envi, int (*fd)[2048][2])
{
	close_fds(fd, lexer->n_command);
	free(lexer->to_free.buff);
	free(lexer->to_free.id_fork);
	free(lexer->to_free.str);
	free_lexer(lexer);
	free_exp_tab(envi);
	if (envi->myenv)
		free_double_array(envi->myenv);
	free_env(envi);
	printf("exit\n");
	exit (g_exit);
}

int	free_struct_inmain(t_free *struct_free)
{
	if (!check_parse_error(struct_free->buff))
	{
		if (struct_free->buff)
			free(struct_free->buff);
		return (0);
	}
	return (1);
}

void	if_not_lexer(t_lexer *lexer, t_env *envi)
{
	print_and_free_exp_tab(envi);
	free_double_array(envi->myenv);
	if (lexer->to_free.id_fork)
		free(lexer->to_free.id_fork);
	free_env(envi);
	exit(0);
}

void	free_new_line(t_free *struct_free)
{
	free(struct_free->buff);
	print_new_line();
}
