/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:46:12 by smayrand          #+#    #+#             */
/*   Updated: 2023/03/01 03:37:25 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_buf_int(t_shell *shell)
{
	if (!shell->buffer)
		ft_exit(shell, "exit successful\n", 0);
	if (char_checker(shell->buffer, ' '))
	{
		shell->error = 127;
		return (0);
	}
	add_history(shell->buffer);
	if (quote_check(shell->buffer)
		|| check_pipe(shell->buffer) || empty_token(shell->buffer))
	{
		shell->error = 127;
		return (0);
	}
	return (1);
}
