/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 4242 <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:34:32 by 4242              #+#    #+#             */
/*   Updated: 2024/01/04 09:27:04 by 4242             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arg_parser.h"

char	*ft_strtrim(char *input)
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

void	*ft_free_list(t_argv *argv, char *buf)
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
	if (buf != NULL)
		free(buf);
	return (NULL);
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
