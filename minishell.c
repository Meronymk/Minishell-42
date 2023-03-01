/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:04:50 by smayrand          #+#    #+#             */
/*   Updated: 2023/03/01 03:36:36 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_env_global;

void	mini_parser_export(t_shell *shell, int nb)
{
	int	i;

	if (shell->cmd[nb].token_nb == 1)
		mini_env(0);
	else
	{
		i = 0;
		while (++i < shell->cmd[nb].token_nb)
			mini_export(shell, shell->cmd[nb].token[i], 1);
	}
}

void	mini_parser_unset(t_shell *shell, int nb)
{
	int	i;

	i = 0;
	while (++i < shell->cmd[nb].token_nb)
		mini_unset(shell->cmd[nb].token[i]);
}

void	ft_exit(t_shell *shell, char *msg, int errno)
{
	ft_putstr_fd(msg, 2);
	free_cmd(shell);
	g_env_global = (char **)ft_free_array(g_env_global);
	rl_clear_history();
	exit(errno);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	ft_memset(&shell, 0, sizeof(t_shell));
	shell.expand[0] = 'a';
	shell.heredoc[0] = 'a';
	g_env_global = ft_remalloc(env, 0, 0);
	if (!g_env_global)
		ft_exit(&shell, "error: malloc failed\n", 1);
	export_err(&shell);
	while (1)
	{
		sig_on();
		shell.buffer = readline("minishell:");
		if (mini_parser(&shell) == 1)
		{
			sig_off();
			exec_cmd(&shell, 0);
		}
		free_cmd(&shell);
	}
	return (0);
}
