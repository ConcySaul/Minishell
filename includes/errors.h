/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:43:30 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/02 13:09:42 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

int		check_quote(char *str);
int		find_next_quote(char *str, int *i);
int		find_next_dquote(char *str, int *i);
int		check_redirection_error(char *str);
int		check_parse_error(char *str);
int		put_err1(char *str, int i);
int		put_err2(char *str, int i);
int		check_quote_and_skip(char *str, int i);
int		if_slash_simple_quote(char *str, int i);
int		if_slash_double_quote(char *str, int i);
int		if_redir1(char *str, int i);
int		if_redir2(char *str, int i);

#endif