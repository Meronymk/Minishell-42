/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:21:14 by smayrand          #+#    #+#             */
/*   Updated: 2023/02/22 14:45:56 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_remalloc(char **old, int size, int f)
{
	char	**new;
	int		i;

	if (old == NULL)
		return (NULL);
	new = ft_calloc(sizeof(char *), (ft_array_len(old) + size));
	if (!new)
		return (NULL);
	i = -1;
	while (old[++i])
		new[i] = ft_strdup(old[i]);
	if (f == 1)
		ft_free_array(old);
	return (new);
}