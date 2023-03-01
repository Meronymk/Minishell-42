/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:02:11 by smayrand          #+#    #+#             */
/*   Updated: 2023/02/22 13:56:54 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mini_cd(t_shell *shell, char *buffer)
{
	char	*temp[2];

	if (!buffer)
		buffer = get_var("HOME", 0);
	if (buffer && chdir(buffer) == 0)
	{
		mini_unset("OLDPWD");
		temp[0] = get_var("PWD", 0);
		temp[1] = ft_strjoin_f("OLDPWD=", temp[0], 0);
		mini_export(shell, temp[1], 0);
		ft_free(temp[1]);
		mini_unset("PWD");
		temp[0] = getcwd(NULL, 0);
		temp[1] = ft_strjoin_f("PWD=", temp[0], 0);
		mini_export(shell, temp[1], 0);
		ft_free(temp[0]);
		ft_free(temp[1]);
	}
	else
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(buffer, 2);
		ft_putstr_fd(": no such file or directory\n", 2);
	}
}
