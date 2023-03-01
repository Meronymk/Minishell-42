/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:12:46 by smayrand          #+#    #+#             */
/*   Updated: 2023/02/28 20:45:49 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern char	**g_env_global;

char	*ft_expand(t_shell *shell, char *token, int flag)
{
	char	*temp[4];

	temp[0] = ft_strchr(token, '$');
	temp[1] = rm_char(ft_substr(token, 0, temp[0] - token), '\"');
	temp[2] = temp[0] + 1;
	while (++temp[0])
		if (!ft_isalnum(*temp[0]))
			break ;
	temp[2] = ft_substr(temp[2], 0, temp[0] - temp[2]);
	temp[3] = get_var(temp[2], 1);
	temp[3] = ft_strjoin_f(temp[1], temp[3], 1);
	ft_free (temp[2]);
	temp[1] = rm_char(ft_substr(temp[0], 0, ft_strllen(temp[0])), '\"');
	temp[0] = ft_strjoin_f(temp[3], temp[1], 1);
	ft_free(temp[1]);
	if (flag == 1)
		ft_free (token);
	if (ft_strchr(temp[0], '$'))
		temp[0] = ft_expand(shell, temp[0], 1);
	return (temp[0]);
}

char	*ft_expand_variable(t_shell *shell, char *token)
{
	char	*temps;
	char	*expand;

	if (token[0] == '$' && ft_strchr(&token[1], '$') == NULL)
		token = get_var(&token[1], 1);
	else
	{
		if (token[0] == '\"')
			token = ft_expand(shell, token + 1, 0);
		else
			token = ft_expand(shell, token, 0);
		expand = ft_strjoin_f(&shell->expand[0], "-expand=", 0);
		temps = ft_strjoin_f(expand, token, 0);
		ft_free(token);
		mini_export(shell, temps, 0);
		ft_free(temps);
		expand[ft_strllen(expand) - 1] = '\0';
		token = get_var(expand, 1);
		ft_free(expand);
		shell->expand[0] = shell->expand[0] + 1;
	}
	return (token);
}

void	token_cleaner(t_shell *shell, char **token)
{
	int	t;

	t = 0;
	while (token[t])
	{
		if (token[t][0] == '\'' && token[t][ft_strllen(token[t]) - 1] == '\'')
			rm_char(token[t], '\'');
		else if (token[t][0] == '\"' &&
			token[t][ft_strllen(token[t]) - 1] == '\"')
		{
			if (ft_strchr(token[t], '$') && !char_checker(token[t], '$'))
				token[t] = ft_expand_variable(shell, token[t]);
			else
				rm_char(token[t], '\"');
		}
		else
		{
			token[t] = token_trimmer(token[t], ' ');
			if (ft_strchr(token[t], '$') && !char_checker(token[t], '$'))
				token[t] = ft_expand_variable(shell, token[t]);
		}
		t++;
	}
}

char	*expand_heredoc(t_shell *shell, char *heredoc)
{
	char	*temps;
	char	*expand;

	expand = ft_strjoin_f("<<", shell->heredoc, 0);
	expand = ft_strjoin_f(expand, "=", 1);
	temps = ft_strjoin_f(expand, heredoc, 0);
	free(heredoc);
	mini_export(shell, temps, 0);
	free(temps);
	expand[ft_strllen(expand) - 1] = '\0';
	temps = get_var(expand, 0);
	free(expand);
	shell->heredoc[0] = shell->heredoc[0] + 1;
	return (temps);
}

int	empty_token(char *buf)
{
	char	*tmp;
	char	*token;
	int		i;

	i = 0;
	tmp = ft_strdup(buf);
	token = ft_strtok(tmp, '|');
	while (token)
	{
		if (char_checker(token, ' ')
			|| char_checker(token, '>') || char_checker(token, '<'))
		{
			printf("error: syntax error\n");
			ft_free(tmp);
			return (1);
		}
		i++;
		token = (ft_strtok(NULL, '|'));
	}
	ft_free(tmp);
	return (0);
}
