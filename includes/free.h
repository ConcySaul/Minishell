/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:44:56 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/02 14:23:36 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

void	free_command(t_command *commands);
void	free_token(t_token *token);
void	free_lexer(t_lexer *lexer);
void	free_env(t_env *env);
void	free_exp_tab(t_env *envi);
void	free_check_if_in_export(char *vadrup, char *check);
void	free_if_lexer1(t_lexer *lexer, t_env *envi, int (*fd)[2048][2]);
int		free_struct_inmain(t_free *struct_free);
void	if_not_lexer(t_lexer *lexer, t_env *envi);
void	free_new_line(t_free *struct_free);
void	free_new_line(t_free *struct_free);

#endif