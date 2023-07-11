/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_built_in2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:36:06 by adegadri          #+#    #+#             */
/*   Updated: 2022/03/01 14:47:12 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	sizetab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char	*check_env(t_env *envi, char *str)
{
	int	i;

	i = 0;
	while (i < envi->tab_size)
	{
		if (ft_strcmp(str, envi->tab[i]->args) == 0)
			return (envi->tab[i]->val);
		i++;
	}
	return (NULL);
}

void	if_only_cd(t_env *env)
{
	char	*tmp;

	tmp = ft_strdup(built_in_pwd(env));
	if (chdir(env->home) == -1)
	{
		free (tmp);
		tmp = NULL;
	}
	if (env->oldpwd)
	{
		free (env->oldpwd);
		env->oldpwd = NULL;
		env->oldpwd = ft_strdup(tmp);
		if (tmp)
		{
			free (tmp);
			tmp = NULL;
		}
	}
	ft_take_pwd_in_tab(env, env->oldpwd, "OLDPWD");
	ft_take_pwd_in_tab(env, env->pwd, "PWD");
}

void	built_in_env_exp(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->tab_size)
	{
		utils_built_in_env_exp(env, i);
		i++;
	}
	i = 0;
	while (i < env->exp_tab_size)
	{
		printf("%s\n", env->exp_tab[i]);
		i++;
	}
}
