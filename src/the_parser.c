/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:21:33 by smayrand          #+#    #+#             */
/*   Updated: 2023/03/01 03:37:13 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_parser(t_shell *shell)
{
	int		i;

	i = 0;
	if (check_buf_int(shell) == 0)
	{
		export_err(shell);
		return (0);
	}
	shell->cmd_nb = token_counter(shell->buffer, '|');
	shell->cmd = ft_calloc(sizeof(t_cmd), shell->cmd_nb);
	shell->pid = ft_calloc(sizeof(pid_t), shell->cmd_nb);
	if (shell->pid == NULL || shell->cmd == NULL)
		ft_exit(shell, "error: malloc failed\n", 1);
	shell->cmd[0].buffer = token_trimmer(ft_strtok(shell->buffer, '|'), ' ');
	while (++i < shell->cmd_nb)
		shell->cmd[i].buffer = token_trimmer(ft_strtok(NULL, '|'), ' ');
	token_parser(shell);
	return (1);
}

void	heredoc_parser(t_shell *shell, char **token)
{
	int		i;
	char	*str;

	i = -1;
	while (token[++i])
	{
		if (ft_strncmp(token[i], "<<", 2) == 0)
		{
			if (token[i][2] == '\0')
			{
				str = exp_hrdc_s(shell, ft_strjoin_f("<", shell->heredoc, 0));
				heredoc_maker(token[i + 1], str);
				token[i][1] = '\0';
				token[i + 1] = str;
			}
			else
			{
				str = exp_hrdc_s(shell, ft_strjoin_f("<", shell->heredoc, 0));
				heredoc_maker(&token[i][2], str);
				token[i] = str;
			}
			shell->heredoc[0] = shell->heredoc[0] + 1;
		}
	}
}

void	token_parser(t_shell *shell)
{
	int	c;
	int	t;

	c = -1;
	while (++c < shell->cmd_nb)
	{
		shell->cmd[c].token_nb = token_counter(shell->cmd[c].buffer, ' ');
		shell->cmd[c].token = ft_calloc(sizeof(char *),
				shell->cmd[c].token_nb + 1);
		if (!shell->cmd[c].token)
			ft_exit(shell, "error: malloc failed\n", 1);
		t = 0;
		shell->cmd[c].token[t] = ft_strtok(shell->cmd[c].buffer, ' ');
		while (shell->cmd[c].token[t++])
			shell->cmd[c].token[t] = ft_strtok(NULL, ' ');
		shell->cmd[c].save = shell->cmd[c].token;
		shell->cmd[c].open_error = 0;
		heredoc_parser(shell, shell->cmd[c].token);
	}
}
