/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:40:42 by adegadri          #+#    #+#             */
/*   Updated: 2022/03/01 20:56:49 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_lexer	*init_lexer(char **str, t_env *envi)
{
	t_lexer	*lexer;

	lexer = (t_lexer *)malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->command = init_command_struct(str, lexer, envi);
	lexer->i = 0;
	lexer->ret_1 = 0;
	lexer->ret_2 = 0;
	return (lexer);
}

int	init_tab(t_env **envi)
{
	*envi = malloc(sizeof(t_env));
	if (!*envi)
		return (0);
	(*envi)->tab = NULL;
	(*envi)->pwd = NULL;
	(*envi)->shlvl = NULL;
	(*envi)->oldpwd = NULL;
	(*envi)->home = NULL;
	(*envi)->path = NULL;
	(*envi)->myenv = NULL;
	(*envi)->j_rm = 0;
	(*envi)->i_rm = 0;
	(*envi)->tmp = NULL;
	(*envi)->tmp2 = NULL;
	(*envi)->tab_size = 0;
	(*envi)->exp_tab_size = 0;
	(*envi)->state = 0;
	return (1);
}
