/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconcy <sconcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:47:21 by sconcy            #+#    #+#             */
/*   Updated: 2022/03/02 13:53:34 by sconcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

char	**ft_split(char *s, char c);
char	*ft_strdup(char *str);
char	*remove_space(char *str);
char	*ft_cpy(char *s, char c);
int		ft_strlen(char *str);
char	*ft_cpy_quoted(char *s, char c);
char	*add_space_between_redir(char *str);
void	free_double_array(char **array);
char	*ft_join(char *s1, char *s2);
int		print_error(char *str);
void	ft_putstr(char *str);
char	*ft_strchr(const char *s, int c);
char	*treat_dollar(char *str, t_env *envi);
char	*treat_dollar_in_dquote(char *str, t_env *envi, t_token *token);
char	*remove_dollar(char *str, int index, t_env *envi, t_token *token);
char	*remove_dollar2(char *str, int index, t_env *envi);
int		is_dollar(char *s);
int		is_dollar_2(char *s);
void	remove_all_dollar_from_command(t_command *command, t_env *envi);
void	remove_all_dollar_from_command2(char **str, t_env *envi);
void	remove_all_quote_from_command(t_command *command);
char	*remove_all_quote(char *str);
int		is_dollar_sep(char c);
int		ft_strcmp(char *s1, char *s2);
char	*remove_quote_from_limitor(char *limitor);
int		has_quote(char *limitor);
char	*remove_dollar_from_string(char *string);
int		has_slash(char *str);
int		ft_putstr_error(char *str);
int		is_str_num(char *str);
char	*check_env(t_env *envi, char *str);
int		rmove_quote1(char *str, int i, int count);
char	*rmove_quote2(char *str, int i, int count, char *dest);
char	*remove_space_from_env(char *str);
char	*remove_space_from_env2(char *str);
char	*remove_n_from_env(char *str);
int		has_n(char *str);
int		check_n_echo2(char **strs);
char	*last_save(char *str, int i);
char	*first_save(char *str, int index);
void	free_rmove(char *str, char *path, char *post_save, char *pre_save);
char	*get_post_save(char *str, char *post_save, t_env *envi);
int		get_i(char *str, t_env *envi);
void	if_tmp(t_env *envi, t_token *token);
char	*check_tmp(char *str, char *path, t_env *envi);
void	free_rmove(char *str, char *path, char *post_save, char *pre_save);
void	if_pre_save(char *pre_save, t_env *envi);
void	if_post_save(char *post_save, t_env *envi);
char	*cpy_in_path(char *str, char *path, t_env *envi);
char	*get_post_save(char *str, char *post_save, t_env *envi);
char	*get_path(char *str, t_env *envi, char *path);
int		process_cpy(char *s, int i);
int		process_cpy2(char *s, int i);
int		process_cpy3(char *s, int i, char *dest);
int		process_cpy4(char *s, int i, char *dest);
void	clean(char **tab, int size);
int		ft_count_word(char const *s, char c);
void	print_and_free_exp_tab(t_env *envi);
int		is_only_char(char *str, char c);
void	print_new_line(void);

#endif