/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:55:06 by smayrand          #+#    #+#             */
/*   Updated: 2023/03/01 02:32:34 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern char	**g_env_global;

void	ft_clean_redirect(int *nb, char ***token, int *i, int size)
{
	*nb = *nb - size;
	*token = *token + size;
	*i = -1;
}

void	ft_redirect(t_cmd *cmd, char *meta, int flag)
{
	cmd->i = -1;
	if (cmd->i + 1 >= cmd->token_nb)
		cmd->open_error = 1;
	while (++cmd->i < cmd->token_nb)
	{
		if (ft_strncmp(cmd->token[cmd->i], meta, ft_strllen(meta)) == 0)
		{
			if (cmd->token[cmd->i][ft_strllen(meta)] == '\0')
			{
				cmd->fd = mini_open(cmd, cmd->token[cmd->i + 1], flag);
				if (cmd->i == 0)
					ft_clean_redirect(&cmd->token_nb, &cmd->token, &cmd->i, 2);
			}
			else
			{
				cmd->fd = mini_open(cmd, &cmd->token[cmd->i][0], flag);
				if (cmd->i == 0)
					ft_clean_redirect(&cmd->token_nb, &cmd->token, &cmd->i, 1);
			}
		}
	}
}

int	redirection_finder(t_shell *shell, int nb)
{	
	ft_redirect(&shell->cmd[nb], ">>", 3);
	ft_redirect(&shell->cmd[nb], ">", 2);
	if (shell->cmd[nb].fd > 2)
	{
		dup2(shell->cmd[nb].fd, 1);
		shell->cmd[nb].fd = -1;
	}
	ft_redirect(&shell->cmd[nb], "<", 1);
	if (shell->cmd[nb].fd > 2)
	{
		dup2(shell->cmd[nb].fd, 0);
		shell->cmd[nb].fd = -1;
	}
	token_cleaner(shell, shell->cmd[nb].token);
	if (shell->cmd[nb].open_error == 1)
	{
		return (1);
	}
	return (0);
}

char	*ft_get_path(t_shell *shell, int nb)
{
	char	*program;
	char	*env_path;
	char	**fcnt_path;
	char	*test_path;
	int		i;

	i = -1;
	if (access(shell->cmd[nb].token[0], F_OK | X_OK) == 0)
		return (shell->cmd[nb].token[0]);
	program = ft_strjoin_f("/", shell->cmd[nb].token[0], 0);
	env_path = get_var("PATH", 0);
	fcnt_path = ft_split(env_path, ':');
	if (program == NULL || env_path[0] == '\0' || fcnt_path == NULL)
		return (NULL);
	while (fcnt_path[++i])
	{
		test_path = ft_strjoin_f(fcnt_path[i], program, 0);
		if (access(test_path, F_OK | X_OK) == 0)
			break ;
		ft_free (test_path);
		test_path = NULL;
	}
	ft_free_array(fcnt_path);
	ft_free(program);
	return (test_path);
}

void	mini_execve(t_shell *shell, int nb)
{
	char	*cmd_path;

	cmd_path = ft_get_path(shell, nb);
	if (cmd_path)
		execve(cmd_path, shell->cmd[nb].token, g_env_global);
	write(2, "minishell: ", 11);
	write(2, shell->cmd[nb].token[0], ft_strllen(shell->cmd[nb].token[0]));
	write(2, ": command not found\n", 20);
	ft_exit(shell, NULL, 1);
}
