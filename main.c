/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 4242 <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:15:42 by 4242              #+#    #+#             */
/*   Updated: 2024/01/03 22:46:31 by 4242             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*strtrim(char *input)
{
	while (*input != '\0' && isspace(*input))
		input++;
	return (input);
}

char	**arg_parser(char *input)
{
	char	*arg;
	char	**argv;
	char 	*copybuf;
	int	squote = 0;
	int	dquote = 0;
	int	bsquote = 0;

	if (input == NULL)
		return (NULL);
	copybuf = malloc((strlen(input) + 1) * sizeof(char));
	if (!copybuf)
		return (NULL);
	while (*input != '\0')
	{
		input = strtrim(input);
		if (*input == '\0')
			break ;
		arg = copybuf;
		while (*input != '\0')
		{
			if (isspace (*input) && !squote && !dquote && !bsquote)
				break ;
			else
			{
				if (bsquote)
				{
					bsquote = 0;
					*arg++ = *input;
				}
				else if (*input == '\\')
					bsquote = 1;
				else if (squote)
				{
					if (*input == '\'')
						squote = 0;
					else
						*arg++ = *input;
				}
				else if (dquote)
				{
					if (*input == '"')
						dquote = 0;
					else
						*arg++ = *input;
				}
				else
				{
					if (*input == '\'')
						squote = 1;
					else if (*input == '"')
						dquote = 1;
					else
						*arg++ = *input;
				}
				input++;
			}
		}
		*arg = '\0';
		printf("[%s]\n", copybuf);
		input = strtrim(input);
		if (*input == '\0')
			break ;
	}
	free(copybuf);
	return (argv);
}

int	main(int argc, char **argv)
{
	(void) argc;
	arg_parser(argv[1]);
	return (0);
}
