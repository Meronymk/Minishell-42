/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:04:09 by smayrand          #+#    #+#             */
/*   Updated: 2023/03/01 03:37:19 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_open(t_cmd *cmd, char *str, int flag)
{
	cmd->fdt = -1;
	while (str && (str[0] == '>' || str[0] == '<'))
		str++;
	if (flag == 1)
		cmd->fdt = open(str, O_RDONLY, 0644);
	else if (flag == 2)
	{
		cmd->fdt = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(cmd->fdt, STDOUT_FILENO);
		ft_putstr_fd(cmd->token[0], cmd->fdt);
	}
	else if (flag == 3)
	{
		cmd->fdt = open(str, O_CREAT | O_WRONLY | O_APPEND, 0644);
		dup2(cmd->fdt, STDOUT_FILENO);
		write(cmd->fdt, "\n", 1);
		ft_putstr_fd(cmd->token[0], cmd->fdt);
	}
	else if (cmd->fdt < 0)
	{
		ft_putstr_fd("error: open() error\n", 2);
		cmd->open_error = 1;
	}
	return (cmd->fdt);
}

int	mini_open_fd(char *str, int flag)
{
	static int	fd;

	while (str && (str[0] == '>' || str[0] == '<'))
		str++;
	if (flag == 1)
		fd = open(str, O_RDONLY, 0644);
	else if (flag == 2)
		fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (flag == 3)
		fd = open(str, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (flag == 4)
		fd = open(str, O_RDWR | O_CREAT, 0644);
	else if (flag == 5)
		fd = open(str, O_WRONLY | O_CREAT, 0644);
	else if (flag == 6)
		fd = open(str, O_RDWR | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("error: open() error\n", 2);
		return (-1);
	}
	return (fd);
}
