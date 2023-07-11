/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:46:34 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/02 13:18:18 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define READ 0
# define WRITE 1
# include "lexer.h"
# include "utils.h"
# include "errors.h"
# include "free.h"
# include "test.h"
# include "built_in.h"
# include "exec.h"
# include <stdlib.h>
# include <stdio.h>
# define __USE_GNU 1
# define __USE_POSIX 1
# define __USE_POSIX199309 1
# include <signal.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>

extern int	g_exit;

#endif