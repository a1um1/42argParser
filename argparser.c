/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 4242 <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:15:42 by 4242              #+#    #+#             */
/*   Updated: 2024/01/04 09:07:33 by 4242             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arg_parser.h"

void	arg_check(char **arg, char **input, t_arg_tag *tag)
{
	if (**input == '\\')
		tag->bquote = 1;
	else if (tag->squote)
	{
		if (**input == '\'')
			tag->squote = 0;
		else
			*(*arg)++ = **input;
	}
	else if (tag->dquote)
	{
		if (**input == '"')
			tag->dquote = 0;
		else
			*(*arg)++ = **input;
	}
	else
	{
		if (**input == '\'')
			tag->squote = 1;
		else if (**input == '"')
			tag->dquote = 1;
		else
			*(*arg)++ = **input;
	}
}
char	*arg_getstr(char **arg, char **input)
{
	t_arg_tag	tag;

	tag.squote = 0;
	tag.dquote = 0;
	tag.bquote = 0;
	while (**input != '\0')
	{
		if (isspace (**input) && !tag.squote && !tag.dquote && !tag.bquote)
			break ;
		else
		{
			if (tag.bquote)
			{
				tag.bquote = 0;
				*(*arg)++ = **input;
				(*input)++;
				continue ;
			}
			arg_check(arg, input, &tag);
			(*input)++;
		}
	}
	return (*arg);
}

t_argv	*arg_parser(char *input)
{
	char	*arg;
	char	*copybuf;
	t_argv	*lst_argv;
	t_argv	*lst_copy;

	if (input == NULL)
		return (NULL);
	copybuf = malloc((ft_strlen(input) + 1) * sizeof(char));
	if (!copybuf)
		return (NULL);
	lst_argv = NULL;
	if (!ft_create_list(&lst_argv))
		return (ft_free_list(NULL));
	lst_copy = lst_argv;
	while (*input != '\0')
	{
		input = ft_strtrim(input);
		if (*input == '\0')
			break ;
		arg = copybuf;
		if (!ft_create_list(&lst_copy))
			return (ft_free_list(lst_argv));
		arg_getstr(&arg, &input);
		*arg = '\0';
		lst_copy->val = ft_strdup(copybuf);
		if (!ft_create_list(&(lst_copy->nxt)))
			return (ft_free_list(lst_argv));
		lst_copy = lst_copy->nxt;
	}
	free(copybuf);
	return (lst_argv);
}