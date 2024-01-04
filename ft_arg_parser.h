/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 4242 <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 05:14:22 by 4242              #+#    #+#             */
/*   Updated: 2024/01/04 12:35:16 by 4242             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARG_PARSER_H
# define FT_ARG_PARSER_H

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_arg_tag
{
	char	squote;
	char	dquote;
	char	bquote;
}	t_arg_tag;

typedef struct s_argv	t_argv;
struct s_argv
{
	char	*val;
	t_argv	*nxt;
};

t_argv	*arg_parser(char *input);
void	arg_check(char **arg, char **input, t_arg_tag *tag);
char	*arg_getstr(char **arg, char **input);

char	*ft_strtrim(char *input);
t_argv	*ft_create_list(t_argv **argv);
void	*ft_free_list(t_argv *argv, char *buf);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	ft_isspace(char c);
#endif
