/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 4242 <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:15:42 by 4242              #+#    #+#             */
/*   Updated: 2024/01/04 08:21:39 by 4242             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arg_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*strtrim(char *input)
{
	while (*input != '\0' && isspace(*input))
		input++;
	return (input);
}

t_argv	*ft_create_list(t_argv **argv)
{
	if (*argv != NULL)
		return (*argv);
	*argv = malloc(sizeof(t_argv));
	if (*argv == NULL)
		return (NULL);
	(*argv)->nxt = NULL;
	(*argv)->val = NULL;
	return (*argv);
}

void	*ft_free_list(t_argv *argv)
{
	t_argv	*tmp;

	while (argv != NULL)
	{
		tmp = argv->nxt;
		if (argv->val != NULL)
			free(argv->val);
		free(argv);
		argv = tmp;
	}
	return (NULL);
}

char	*arg_check(char **arg, char **input,
			char *squote, char *dquote, char *bsquote)
{
	if (**input == '\\')
		*bsquote = 1;
	else if (*squote)
	{
		if (**input == '\'')
			*squote = 0;
		else
			*(*arg)++ = **input;
	}
	else if (*dquote)
	{
		if (**input == '"')
			*dquote = 0;
		else
			*(*arg)++ = **input;
	}
	else
	{
		if (**input == '\'')
			*squote = 1;
		else if (**input == '"')
			*dquote = 1;
		else
			*(*arg)++ = **input;
	}
}
char	*arg_getstr(char **arg, char **input)
{
	char	squote = 0;
	char	dquote = 0;
	char	bsquote = 0;

	while (**input != '\0')
	{
		if (isspace (**input) && !squote && !dquote && !bsquote)
			break ;
		else
		{
			if (bsquote)
			{
				bsquote = 0;
				*(*arg)++ = **input;
				(*input)++;
				continue ;
			}

			(*input)++;
		}
	}
	return (*arg);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = malloc(ft_strlen(str));
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	return (tmp);
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
		input = strtrim(input);
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
		input = strtrim(input);
		if (*input == '\0')
			break ;
	}
	free(copybuf);
	return (lst_argv);
}

int	main(int argc, char **argv)
{
	(void) argc;
	t_argv *tmp = arg_parser(argv[1]);
	while (tmp != NULL)
	{
		printf("[%s]\n", tmp->val);
		tmp = tmp->nxt;
	}
	return (0);
}
