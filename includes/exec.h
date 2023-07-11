/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:43:40 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/01 20:44:49 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

void	exec_command(t_env *envi, t_lexer *lexer, char **env);
void	treat_fork(t_lexer *lexer, int (*fd)[2048][2], char **env, t_env *envi);
void	ft_putstr_fd(char *str, int fd);
char	*find_bin(t_command *command, t_env *envi);
int		wait_all_pid(int *id_fork, int n_fork);
void	if_cd(t_lexer *lexer, t_env *envi);
char	**if_export(t_lexer *lexer, t_env *envi);
char	**if_unset(t_lexer *lexer, t_env *envi);
void	if_ms(t_lexer *lexer, t_env *envi, \
t_free *struct_free, int (*fd)[2048][2]);
char	*if_find_bin(char **pathes, char *com, char *tmp_path);
void	process_export(t_lexer *lexer, int i, t_env *envi, char **env);
void	process_cd(t_lexer *lexer, int i, t_env *envi);
void	process_unset(t_lexer *lexer, int i, t_env *envi, char **env);
void	make_pipe(t_lexer *lexer, int (*fd)[2048][2]);
void	process_fork(t_lexer *lexer, char **env, \
t_env *envi, int (*fd)[2048][2]);
void	process_redir(t_lexer *lexer, int (*fd)[2048][2]);
void	wait_and_close(t_lexer *lexer, int (*fd)[2048][2]);
void	process_builtin(t_lexer *lexer, t_env *envi, int (*fd)[2048][2]);
void	process_fork1(t_lexer *lexer, char **env, t_env *envi);
void	process_fork2(t_lexer *lexer, char **env, t_env *envi);
void	process_fork3(t_lexer *lexer, t_env *envi);
void	process_heredoc(char *line, int i, int (*fd)[2048][2]);
void	process_heredoc2(char *no_dollar, int i, int (*fd)[2048][2], \
char *line);
void	process_heredoc3(char *line, int i, int (*fd)[2048][2]);
void	free_heredoc(char *line, char *limitor);
char	*set_flag_limitor(int *flag, char *limitor, char *eof);
char	*ret_limitor(int ret, int *flag, char *eof, char *limitor);

#endif