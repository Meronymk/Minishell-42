/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:55:34 by smayrand          #+#    #+#             */
/*   Updated: 2023/02/28 23:18:34 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern char	**g_env_global;

void	mini_env(int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		while (g_env_global[i + 1] != NULL)
		{
			if (g_env_global[i][0] != '<' && g_env_global[i][1] != '-'
				&& ft_strchr(g_env_global[i], '='))
				printf("declare -x %s\n", g_env_global[i]);
			i++;
		}
	}
	else
	{
		while (g_env_global[i + 1] != NULL)
		{
			if (g_env_global[i][0] != '<' && g_env_global[i][1] != '-'
				&& ft_strchr(g_env_global[i], '='))
				printf("%s\n", g_env_global[i]);
			i++;
		}
	}
}
