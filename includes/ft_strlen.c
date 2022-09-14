/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:39:26 by krochefo          #+#    #+#             */
/*   Updated: 2022/09/13 17:25:12 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

// Return length of param1.
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
