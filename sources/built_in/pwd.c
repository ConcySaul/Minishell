/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:10:00 by adegadri          #+#    #+#             */
/*   Updated: 2022/02/15 15:44:25 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*built_in_pwd(t_env *env)
{
	char	cwd[256];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (env->pwd)
		{
			free(env->pwd);
			env->pwd = NULL;
		}
		env->pwd = ft_strdup(cwd);
	}
	return (env->pwd);
}

void	printf_pwd(t_env *env)
{
	built_in_pwd(env);
	printf("%s\n", env->pwd);
}
