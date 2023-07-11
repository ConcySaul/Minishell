/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:26:20 by adegadri          #+#    #+#             */
/*   Updated: 2022/02/28 17:39:15 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_tabi2(t_env *env)
{
	int	i;

	i = 0;
	while (env->tab[i])
	{
		free(env->tab[i]->args);
		env->tab[i]->args = NULL;
		free(env->tab[i]->val);
		env->tab[i]->val = NULL;
		free(env->tab[i]);
		i++;
	}
	free(env->tab);
	env->tab = NULL;
}

t_tab	*copy_in_tab_unset(t_tab *tab, t_env *env, char *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env->tab[i])
	{
		if (ft_strcmp(env->tab[i]->args, var))
		{
			tab[j].args = ft_strdup(env->tab[i]->args);
			tab[j].val = ft_strdup(env->tab[i]->val);
			j++;
		}
		i++;
	}
	return (tab);
}

int	process_of_unset(t_env *env, t_tab *tab)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < env->tab_size)
	{
		env->tab[j] = malloc(sizeof(t_tab) * 1);
		if (!env->tab[j])
			return (0);
		env->tab[j]->args = ft_strdup(tab[i].args);
		free(tab[i].args);
		env->tab[j]->val = ft_strdup(tab[i].val);
		free(tab[i].val);
		j++;
	}
	free (tab);
	return (1);
}

int	built_in_unset(t_env *env, char *var)
{
	t_tab	*tab;

	env->tab_size -= 1;
	tab = (t_tab *)malloc(sizeof(t_tab) * (env->tab_size));
	if (!tab)
		return (0);
	tab = copy_in_tab_unset(tab, env, var);
	free_tabi2(env);
	env->tab = malloc(sizeof(char *) * (env->tab_size + 1));
	if (!env->tab)
		return (0);
	env->tab[env->tab_size] = NULL;
	if (!process_of_unset(env, tab))
		return (0);
	return (1);
}
