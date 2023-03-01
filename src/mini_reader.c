/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:12:50 by smayrand          #+#    #+#             */
/*   Updated: 2023/02/22 13:32:03 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern char	**g_env_global;

char	*get_var(char *buffer, int flag)
{
	int		i;

	i = -1;
	if (!buffer)
		return (NULL);
	while (g_env_global[++i])
	{
		if (ft_strncmp(g_env_global[i], buffer, ft_strllen(buffer)) == 0)
		{
			if (g_env_global[i][ft_strllen(buffer)] == '=')
				return (g_env_global[i] + (ft_strllen(buffer) + 1));
		}
	}
	if (flag == 1)
		buffer[0] = '\0';
	return (buffer);
}
