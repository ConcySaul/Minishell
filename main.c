/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:23:11 by adegadri          #+#    #+#             */
/*   Updated: 2022/03/02 14:26:14 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	g_exit = 0;

void	print_new_line(void)
{
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	handler_sigint(int signum)
{
	if (signum == SIGINT)
	{
		g_exit = 130;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
		return ;
}

int	if_main_else(t_env *envi, t_lexer *lexer, char **env, t_free struct_free)
{
	struct_free.buff = add_space_between_redir(struct_free.buff);
	if (!free_struct_inmain(&struct_free))
		return (0);
	add_history(struct_free.buff);
	if (is_only_char(struct_free.buff, ' '))
		free_new_line(&struct_free);
	else
	{
		struct_free.str = ft_split(struct_free.buff, '|');
		take_and_cpy_env(envi, env);
		set_env(envi);
		env = envi->myenv;
		envi->state = 1;
		lexer = init_lexer(struct_free.str, envi);
		lexer->to_free = struct_free;
		if (!lexer)
			if_not_lexer(lexer, envi);
		exec_command(envi, lexer, env);
		free(struct_free.buff);
		free_double_array(struct_free.str);
		free_lexer(lexer);
		free_double_array(envi->myenv);
		envi->myenv = NULL;
	}
	return (1);
}

int	conditions_main(t_free *struct_free, t_env *envi, t_lexer *lexer, \
char **env)
{
	struct_free->buff = readline("Solo_Minishell> ");
	if (!struct_free->buff)
	{
		write(1, "exit\n", 5);
		free_exp_tab(envi);
		free_env(envi);
		exit(g_exit);
	}
	if (!*struct_free->buff)
		free(struct_free->buff);
	else
	{
		if (!if_main_else(envi, lexer, env, *struct_free))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	static t_lexer	*lexer = NULL;
	t_free			struct_free;
	t_env			*envi;

	(void)argc;
	(void)argv;
	(void)env;
	if (!init_tab(&envi))
		return (0);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	struct_free.buff = NULL;
	struct_free.str = NULL;
	while (1)
	{
		signal(SIGINT, handler_sigint);
		if (!conditions_main(&struct_free, envi, lexer, env))
			continue ;
	}
	return (0);
}
