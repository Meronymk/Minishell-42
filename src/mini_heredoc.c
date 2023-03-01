/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:17:25 by smayrand          #+#    #+#             */
/*   Updated: 2023/03/01 00:21:51 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	heredoc_maker(char *limiter, char *heredoc)
{
	int		fd;
	char	*str;

	if (!heredoc)
		return ;
	fd = mini_open_fd(heredoc, 2);
	str = readline("heredoc: ");
	while (str)
	{
		if (ft_strncmp(str, limiter, ft_strllen(limiter)) == 0)
			break ;
		ft_putstr_fd(str, fd);
		ft_putstr_fd("\n", fd);
		ft_free(str);
		str = readline("heredoc: ");
	}
	ft_free(str);
	close(fd);
}

void	heredoc_unlink(t_shell *shell)
{
	int	i;

	shell->heredoc[0] = 'a';
	i = -1;
	while (++i < 26)
	{
		unlink(shell->heredoc);
		shell->heredoc[0] = shell->heredoc[0] + 1;
	}
}

char	*exp_hrdc_s(t_shell *shell, char *heredoc)
{
	char	*temps;
	char	*expand;

	expand = ft_strjoin_f("<", shell->heredoc, 0);
	expand = ft_strjoin_f(expand, "=", 1);
	temps = ft_strjoin_f(expand, heredoc, 0);
	free(heredoc);
	mini_export(shell, temps, 0);
	free(temps);
	expand[ft_strllen(expand) - 1] = '\0';
	temps = get_var(expand, 0);
	free(expand);
	return (temps);
}
