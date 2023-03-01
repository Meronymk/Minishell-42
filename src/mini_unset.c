/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:55:34 by smayrand          #+#    #+#             */
/*   Updated: 2023/02/22 13:23:16 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern char	**g_env_global;

void	mini_unset(char *buffer)
{
	int	i;

	i = -1;
	while (g_env_global[++i])
	{
		if (ft_strncmp(g_env_global[i], buffer, ft_strllen(buffer)) == 0
			&& g_env_global[i][ft_strllen(buffer)] == '=')
		{
			ft_free(g_env_global[i]);
			while (g_env_global[i + 1])
			{
				g_env_global[i] = g_env_global[i + 1];
				i++;
			}
			g_env_global[i] = NULL;
		}
	}
}
