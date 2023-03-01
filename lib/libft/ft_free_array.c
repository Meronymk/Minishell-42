/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:36:34 by smayrand          #+#    #+#             */
/*   Updated: 2023/02/22 13:36:53 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_free_array(char **array)
{
	int	i;

	if (!array)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		if (array[i])
			array[i] = ft_free(array[i]);
	}
	array = ft_free(array);
	return (NULL);
}