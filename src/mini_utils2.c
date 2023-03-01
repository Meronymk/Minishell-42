/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:05:47 by smayrand          #+#    #+#             */
/*   Updated: 2023/02/22 15:02:32 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*rm_char(char *token, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (token[i])
	{
		if (token[i] == sep)
		{
			j = i - 1;
			while (token[++j])
				token[j] = token[j + 1];
		}
		else
			i++;
	}
	return (token);
}

char	*token_trimmer(char *token, char sep)
{
	int		i;

	if (!token)
		return (token);
	i = ft_strllen(token) - 1;
	while (token[i] == sep)
	{
		token[i] = '\0';
		i--;
	}
	while (*token == sep)
		token++;
	return (token);
}

int	token_counter(char *buffer, char sep)
{
	char	*tmp;
	char	*token;
	int		i;

	i = 0;
	tmp = ft_strdup(buffer);
	token = token_trimmer(ft_strtok(tmp, sep), ' ');
	while (token)
	{
		i++;
		token = token_trimmer(ft_strtok(NULL, sep), ' ');
	}
	free(tmp);
	return (i);
}

void	ft_clear_fd(void)
{
	int	i;

	i = 3;
	while (i < 101)
	{
		close(i);
		i++;
	}
}
