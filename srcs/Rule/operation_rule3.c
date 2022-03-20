/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rule3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:11:50 by yjimpei           #+#    #+#             */
/*   Updated: 2021/11/30 23:25:57 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "main.h"

static int	get_bottom_value_del(t_vec **vec)
{
	t_vec	*ptr;
	int		index;
	int		bottom;

	ptr = *vec;
	index = 0;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		index++;
	}
	bottom = ptr->value;
	elem_delete(vec, index);
	return (bottom);
}

t_bool	rra(t_info *info)
{
	elem_add_top(&(info->a_vec), get_bottom_value_del(&(info->a_vec)));
	ft_lstadd_back(&(info->ope_list), ft_lstnew("rra"));
	return (TRUE);
}

t_bool	rrb(t_info *info)
{
	elem_add_top(&(info->b_vec), get_bottom_value_del(&(info->b_vec)));
	ft_lstadd_back(&(info->ope_list), ft_lstnew("rrb"));
	return (TRUE);
}

t_bool	rrr(t_info *info)
{
	if (info->b_len < 2 || info->a_len < 2)
		return (FALSE);
	elem_add_top(&(info->a_vec), get_bottom_value_del(&(info->a_vec)));
	elem_add_top(&(info->b_vec), get_bottom_value_del(&(info->b_vec)));
	ft_lstadd_back(&(info->ope_list), ft_lstnew("rrr"));
	return (TRUE);
}
