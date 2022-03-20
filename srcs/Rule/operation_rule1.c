/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rule1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:54:30 by yjimpei           #+#    #+#             */
/*   Updated: 2021/11/30 23:26:58 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "main.h"

t_bool	sa(t_info *info)
{
	int	top1;
	int	top2;

	if (info->a_len < 2)
		return (FALSE);
	top1 = info->a_vec->value;
	top2 = info->a_vec->next->value;
	elem_delete(&(info->a_vec), 0);
	elem_delete(&(info->a_vec), 0);
	elem_add_top(&(info->a_vec), top1);
	elem_add_top(&(info->a_vec), top2);
	ft_lstadd_back(&(info->ope_list), ft_lstnew("sa"));
	return (TRUE);
}

t_bool	sb(t_info *info)
{
	int	top1;
	int	top2;

	if (info->b_len < 2)
		return (FALSE);
	top1 = info->b_vec->value;
	top2 = info->b_vec->next->value;
	elem_delete(&(info->b_vec), 0);
	elem_delete(&(info->b_vec), 0);
	elem_add_top(&(info->b_vec), top1);
	elem_add_top(&(info->b_vec), top2);
	ft_lstadd_back(&(info->ope_list), ft_lstnew("sb"));
	return (TRUE);
}

t_bool	ss(t_info *info)
{
	int	top1;
	int	top2;

	if (info->a_len < 2 || info->b_len < 2)
		return (FALSE);
	top1 = info->b_vec->value;
	top2 = info->b_vec->next->value;
	elem_delete(&(info->b_vec), 0);
	elem_delete(&(info->b_vec), 0);
	elem_add_top(&(info->b_vec), top1);
	elem_add_top(&(info->b_vec), top2);
	top1 = info->a_vec->value;
	top2 = info->a_vec->next->value;
	elem_delete(&(info->a_vec), 0);
	elem_delete(&(info->a_vec), 0);
	elem_add_top(&(info->a_vec), top1);
	elem_add_top(&(info->a_vec), top2);
	ft_lstadd_back(&(info->ope_list), ft_lstnew("ss"));
	return (TRUE);
}

t_bool	pb(t_info *info)
{
	int	top_a;

	if (info->a_len < 1)
		return (FALSE);
	top_a = info->a_vec->value;
	elem_delete(&(info->a_vec), 0);
	elem_add_top(&(info->b_vec), top_a);
	(info->a_len)--;
	(info->b_len)++;
	ft_lstadd_back(&(info->ope_list), ft_lstnew("pb"));
	return (TRUE);
}

t_bool	pa(t_info *info)
{
	int	top_b;

	if (info->b_len < 1)
		return (FALSE);
	top_b = info->b_vec->value;
	elem_delete(&(info->b_vec), 0);
	elem_add_top(&(info->a_vec), top_b);
	ft_lstadd_back(&(info->ope_list), ft_lstnew("pa"));
	(info->a_len)++;
	(info->b_len)--;
	return (TRUE);
}
