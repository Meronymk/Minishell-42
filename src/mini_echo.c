/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:02:11 by smayrand          #+#    #+#             */
/*   Updated: 2023/02/22 13:28:37 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mini_echo(char **arg)
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	if (arg[1] && ft_strncmp(arg[1], "-n", 2) == 0)
	{
		if (char_checker(&arg[1][1], 'n'))
			flag = 1;
		i++;
	}
	while (arg[i])
	{
		if (char_checker(arg[i], ' '))
			i++;
		else
		{
			printf("%s", arg[i++]);
			if (arg[i])
				printf(" ");
		}
	}
	if (flag == 0)
		printf("\n");
}
