/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:44:11 by smayrand          #+#    #+#             */
/*   Updated: 2022/09/16 16:12:50 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_splitsize(char *src, char sep)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (src[i])
	{
		while (src[i] == sep)
			i++;
		if (src[i] != sep && src[i])
			words++;
		while (src[i] != sep && src[i])
			i++;
	}
	return (words);
}
