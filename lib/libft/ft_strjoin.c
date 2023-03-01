/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:18:10 by smayrand          #+#    #+#             */
/*   Updated: 2023/02/22 13:55:44 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strllen(s1) + ft_strllen(s2) + 1);
	str = ft_calloc(len, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, (char *)s1, len);
	ft_strlcat(str, (char *)s2, len);
	return (str);
}

char	*ft_strjoin_f(char *s1, char const *s2, int f)
{
	char	*tmp;
	int		is;
	int		id;

	is = 0;
	id = 0;
	if (!s1 || !s2)
		return (NULL);
	tmp = malloc(sizeof(char) * (ft_strllen(s1) + ft_strllen(s2) + 1));
	if (tmp == NULL)
		return (NULL);
	while (s1 && s1[is])
	{
		tmp[is] = s1[is];
		is++;
	}
	while (s2 && s2[id])
		tmp[is++] = s2[id++];
	tmp[is] = '\0';
	if (f == 1)
		free(s1);
	return (tmp);
}