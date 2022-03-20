/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rule2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:35:47 by yjimpei           #+#    #+#             */
/*   Updated: 2021/11/30 23:26:21 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "main.h"

t_bool	ra(t_info *info)
{
	int	top;

	if (info->a_len < 2)
		return (FALSE);
	top = info->a_vec->value;
	elem_delete(&(info->a_vec), 0);
	elem_add_bottom(&(info->a_vec), top);
	ft_lstadd_back(&(info->ope_list), ft_lstnew("ra"));
	return (TRUE);
}

t_bool	rb(t_info *info)
{
	int	top;

	if (info->b_len < 2)
		return (FALSE);
	top = info->b_vec->value;
	elem_delete(&(info->b_vec), 0);
	elem_add_bottom(&(info->b_vec), top);
	ft_lstadd_back(&(info->ope_list), ft_lstnew("rb"));
	return (TRUE);
}

t_bool	rr(t_info *info)
{
	int	top;

	if (info->a_len < 2 || info->b_len < 2)
		return (FALSE);
	top = info->a_vec->value;
	elem_delete(&(info->a_vec), 0);
	elem_add_bottom(&(info->a_vec), top);
	top = info->b_vec->value;
	elem_delete(&(info->b_vec), 0);
	elem_add_bottom(&(info->b_vec), top);
	ft_lstadd_back(&(info->ope_list), ft_lstnew("rr"));
	return (TRUE);
}
