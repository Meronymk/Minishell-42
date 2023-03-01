/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:55:34 by smayrand          #+#    #+#             */
/*   Updated: 2023/02/22 14:47:55 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern char	**g_env_global;

void	mini_export(t_shell *shell, char *arg, int flag)
{
	char	*duplicate;

	if (arg && ft_isalpha(arg[0]) == 0 && flag == 1)
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		shell->error = 1;
	}
	else
	{
		if (ft_strchr(arg, '='))
		{
			duplicate = ft_substr(arg, 0, ft_strchr(arg, '=') - arg);
			if (get_var(duplicate, 0))
				mini_unset(duplicate);
			ft_free (duplicate);
		}
		g_env_global = ft_remalloc(g_env_global, 1, 1);
		g_env_global[ft_array_len(g_env_global) - 1] = ft_strdup(arg);
	}
}

void	export_err(t_shell *shell)
{
	char	*status;
	char	*export_status;

	status = ft_itoa(shell->error);
	export_status = ft_strjoin_f("?=", status, 0);
	mini_export(shell, export_status, 0);
	free (export_status);
	free (status);
}
