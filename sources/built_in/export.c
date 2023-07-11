/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:00:13 by adegadri          #+#    #+#             */
/*   Updated: 2022/02/28 17:37:10 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_tabi(t_env *env)
{
	int	i;

	i = 0;
	while (env->tab[i])
	{
		free (env->tab[i]->args);
		env->tab[i]->args = NULL;
		free (env->tab[i]->val);
		env->tab[i]->val = NULL;
		free(env->tab[i]);
		env->tab[i] = NULL;
		i++;
	}
	free(env->tab);
	env->tab = NULL;
}

int	check_var(char *var)
{
	char	*check;

	check = ft_valdup(var);
	if (!check[0])
		return (1);
	free (check);
	return (0);
}

t_tab	*copy_in_tab_export(t_tab *tab, t_env *env, char *var)
{
	int	i;

	i = 0;
	while (i < env->tab_size - 1)
	{
		tab[i].args = ft_strdup(env->tab[i]->args);
		tab[i].val = ft_strdup(env->tab[i]->val);
		i++;
	}
	tab[i].args = ft_argsdup(var);
	tab[i].val = ft_valdup(var);
	return (tab);
}

void	built_in_export(t_env *envi, char *var)
{
	int		i;
	t_tab	*tab;

	envi->tab_size += 1;
	tab = (t_tab *)malloc(sizeof(t_tab) * (envi->tab_size));
	if (!tab)
		return ;
	tab = copy_in_tab_export(tab, envi, var);
	free_tabi(envi);
	envi->tab = malloc(sizeof(t_tab *) * (envi->tab_size + 1));
	if (!envi->tab)
		return ;
	envi->tab[envi->tab_size] = NULL;
	i = -1;
	while (++i < envi->tab_size)
	{
		envi->tab[i] = malloc(sizeof(t_tab) * 1);
		if (!envi->tab[i])
			return ;
		envi->tab[i]->args = ft_strdup(tab[i].args);
		free(tab[i].args);
		envi->tab[i]->val = ft_strdup(tab[i].val);
		free(tab[i].val);
	}
	free(tab);
}

void	export_error(t_lexer *lexer, int index)
{
	int	i;

	i = 2;
	while (i < lexer->command[index].n_token)
	{
		printf("Solo_Minishell: export: `%s': not a valid identifier\n",
			lexer->command[index].token[i].data);
		i++;
	}
}
