/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:51:45 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 13:45:22 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_wait_status(int status, int i, int pid, int nb_pid)
{
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
	{
		ft_putstr_error("Quit (core dumped)\n");
		g_exit = 131;
	}
	else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		ft_putstr_error("\n");
		g_exit = 130;
	}
	else if (i + 1 == nb_pid && pid != -1)
		g_exit = WEXITSTATUS(status);
}

int	wait_all_pid(int *id_fork, int n_fork)
{
	int	i;
	int	status;

	i = -1;
	while (++i < n_fork)
	{
		status = 0;
		if (id_fork[i] != -1 && waitpid(id_fork[i], &status, 0) == -1)
		{
			free(id_fork);
			return (0);
		}
		check_wait_status(status, i, id_fork[i], n_fork);
	}
	free(id_fork);
	return (0);
}

char	*zebi(char **pathes, char *com, char *tmp_path)
{
	free_double_array(pathes);
	free (com);
	return (tmp_path);
}

char	*find_bin(t_command *command, t_env *envi)
{
	char	**pathes;
	char	*tmp_path;
	char	*com;
	int		i;

	i = 0;
	tmp_path = check_env(envi, "PATH");
	pathes = ft_split(tmp_path, ':');
	com = ft_join("/", command->token[0].data);
	if (pathes)
	{
		while (pathes[i])
		{
			tmp_path = ft_join(pathes[i], com);
			if (access(tmp_path, F_OK) == 0)
				return (zebi(pathes, com, tmp_path));
			free (tmp_path);
			i++;
		}
	}
	free (com);
	if (pathes)
		free_double_array(pathes);
	return (NULL);
}

void	close_fds(int (*fd)[2048][2], int n_command)
{
	int	i;

	i = 0;
	while (i <= n_command)
	{
		close((*fd)[i][0]);
		close((*fd)[i][1]);
		i++;
	}
}
