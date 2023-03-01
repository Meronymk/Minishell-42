/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:50:06 by smayrand          #+#    #+#             */
/*   Updated: 2023/02/22 11:51:03 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlist)
{
	t_list	*temp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = newlist;
		else
		{
			temp = ft_lstlast(*(lst));
			temp->next = newlist;
		}
	}
}
