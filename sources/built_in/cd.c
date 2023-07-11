/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:13:30 by adegadri          #+#    #+#             */
/*   Updated: 2022/03/02 14:41:40 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_take_pwd_in_tab(t_env *env, char *chem, char *pwd)
{
	int	i;

	i = -1;
	while (++i < env->tab_size - 1)
	{
		if (!ft_strcmp(env->tab[i]->args, pwd))
		{
			if (env->tab[i]->val)
			{
				free (env->tab[i]->val);
				env->tab[i]->val = NULL;
			}
			env->tab[i]->val = ft_strdup(chem);
		}
	}
}

int	if_home(t_env *env, char *path)
{
	char	*tmp;

	tmp = ft_strdup(built_in_pwd(env));
	if (chdir(env->home) == -1)
	{
		free (tmp);
		tmp = NULL;
		perror (path);
		return (-1);
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
	return (0);
}

int	if_chdir(t_env *env, char *path)
{
	char	*tmp;

	tmp = ft_strdup(env->pwd);
	if (chdir(path) == -1)
	{
		free (tmp);
		tmp = NULL;
		perror (path);
		return (-1);
	}
	built_in_pwd(env);
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
		ft_take_pwd_in_tab(env, env->oldpwd, "OLDPWD");
		ft_take_pwd_in_tab(env, env->pwd, "PWD");
	}
	return (0);
}

void	if_path(t_env *env, char *path)
{
	char	*chem;

	chem = ft_strjoin(env->path, path);
	if (chdir(chem) == -1)
	{
		free(chem);
		if (chdir(path) == -1)
			perror(path);
		perror(chem);
	}
	free(chem);
}

void	built_in_cd(t_env *env, char *path)
{
	if (env->oldpwd)
		free(env->oldpwd);
	env->oldpwd = ft_strdup(built_in_pwd(env));
	if (!path && env->home)
		if_home(env, path);
	else if (path && (!ft_strcmp(path, "-") || (!ft_strcmp(path, "~"))))
	{
		if (if_home(env, env->oldpwd) == -1)
			perror(env->oldpwd);
		built_in_pwd(env);
		if (!ft_strcmp(path, "-"))
			printf("%s\n", env->oldpwd);
	}
	else if (path && env->path)
		if_path(env, path);
	else
	{
		if (if_chdir(env, path) == -1)
			perror(path);
	}
}
