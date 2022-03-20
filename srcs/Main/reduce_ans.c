/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_ans.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:05:16 by yjimpei           #+#    #+#             */
/*   Updated: 2021/11/30 23:31:32 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "main.h"
#include "rule.h"

static int	get_how_reduce(void *c1, void *c2)
{
	if (!ft_strncmp(c1, "sa", 3) && !ft_strncmp(c2, "sb", 3))
		return (1);
	if (!ft_strncmp(c1, "sb", 3) && !ft_strncmp(c2, "sa", 3))
		return (2);
	if (!ft_strncmp(c1, "ra", 3) && !ft_strncmp(c2, "rb", 3))
		return (3);
	if (!ft_strncmp(c1, "rra", 3) && !ft_strncmp(c2, "rrb", 3))
		return (4);
	if (!ft_strncmp(c1, "pa", 3) && !ft_strncmp(c2, "pb", 3))
		return (5);
	if (!ft_strncmp(c1, "pb", 3) && !ft_strncmp(c2, "pa", 3))
		return (6);
	return (0);
}

static t_list	*replace_elem(int how)
{
	if (how == 1 || how == 2)
		return (ft_lstnew("ss"));
	if (how == 3)
		return (ft_lstnew("rr"));
	if (how == 4)
		return (ft_lstnew("rrr"));
	return (NULL);
}

void	reduce_ans(t_info *info)
{
	t_list	**ptrptr;
	t_list	*ptr;
	t_list	*replace;
	int		how;

	ptrptr = &(info->ope_list);
	while ((*ptrptr)->next != NULL)
	{
		how = get_how_reduce((*ptrptr)->content, (*ptrptr)->next->content);
		if (how != 0)
		{
			ptr = (*ptrptr)->next->next;
			free((*ptrptr)->next);
			free(*ptrptr);
			if (how == 1 || how == 2 || how == 3 || how == 4)
			{
				replace = replace_elem(how);
				replace->next = ptr;
				*ptrptr = replace;
			}
			if (how >= 5)
				*ptrptr = ptr;
		}
		ptrptr = &((*ptrptr)->next);
	}
}
