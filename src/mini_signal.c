/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:51:07 by krochefo          #+#    #+#             */
/*   Updated: 2023/02/28 17:09:01 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	signal_checker(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signal == SIGQUIT)
		rl_redisplay();
}

void	sig_off(void)
{
	signal(SIGINT, sig_break);
	signal(SIGQUIT, sig_break);
}

void	sig_on(void)
{
	signal(SIGINT, signal_checker);
	signal(SIGQUIT, signal_checker);
}

void	sig_break(int signal)
{
	if (signal == SIGINT)
	{
		kill(0, 0);
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
	}
	if (signal == SIGQUIT)
	{
		kill(0, 0);
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
	}
}

void	free_cmd(t_shell *shell)
{
	int	i;

	i = -1;
	while (++i < shell->cmd_nb)
		ft_free(shell->cmd[i].save);
	shell->cmd = ft_free(shell->cmd);
	shell->pid = ft_free(shell->pid);
	shell->buffer = ft_free(shell->buffer);
	shell->cmd_nb = 0;
	ft_clear_fd();
}
