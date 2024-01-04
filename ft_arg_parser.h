/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 4242 <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 05:14:22 by 4242              #+#    #+#             */
/*   Updated: 2024/01/04 05:27:33 by 4242             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARG_PARSER_H
# define FT_ARG_PARSER_H

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_argv	t_argv;
struct s_argv
{
	char	*val;
	t_argv	*nxt;
};
#endif
