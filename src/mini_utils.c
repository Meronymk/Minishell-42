/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:05:47 by smayrand          #+#    #+#             */
/*   Updated: 2023/02/24 10:13:53 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	char_checker(char *buf, char c)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (buf[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	check_pipe(char *buf)
{
	char	*tmp;

	tmp = buf;
	if (buf[0] == '|' || buf[ft_strllen(buf) - 1] == '|')
	{
		ft_putstr_fd("error: syntax error\n", 2);
		return (1);
	}
	while (*tmp)
	{
		if (*tmp == '|' && *(tmp + 1) == '|')
		{
			*tmp = '\0';
			return (0);
		}
		if (*tmp == '|' && char_checker(tmp + 1, ' '))
		{
			ft_putstr_fd("error: syntax error\n", 2);
			return (1);
		}
		tmp++;
	}
	return (0);
}

int	quote_check(char *buf)
{
	char	*tmp;

	tmp = buf;
	while (*tmp)
	{
		if (*tmp == '\'' || *tmp == '\"')
		{
			if (ft_strchr(tmp + 1, *tmp) == NULL)
			{
				ft_putstr_fd("error syntax error\n", 2);
				return (1);
			}
			else
				tmp = ft_strchr(tmp + 1, *tmp);
		}
		tmp++;
	}
	return (0);
}

static char	*end_buffer(char *ret, char **save)
{
	*save = NULL;
	if (char_checker(ret, ' '))
		return (NULL);
	return (ret);
}

char	*ft_strtok(char *buffer, char sep)
{
	static char	*save;
	char		*ret;

	if (!save)
		save = buffer;
	ret = save;
	while (save && *save == ' ')
		save++;
	while (save && *save != sep)
	{
		if (*save == '\0')
			return (end_buffer(ret, &save));
		else if (*save == '\'' || *save == '\"')
		{
			save = strchr(save + 1, *save);
			if (!save)
				return (ret);
			save++;
		}
		else
			save++;
	}
	if (save)
		*save++ = '\0';
	return (ret);
}
