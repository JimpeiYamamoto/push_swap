/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:31:25 by yjimpei           #+#    #+#             */
/*   Updated: 2021/07/04 13:43:08 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst)
	{
		free(lst);
		return ;
	}
	while (*lst)
	{
		tmp = *lst;
		if (del)
			del((*lst)->content);
		*lst = (*lst)->next;
		free(tmp);
	}
	*lst = NULL;
}
