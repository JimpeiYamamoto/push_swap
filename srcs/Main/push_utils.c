/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:59:18 by yjimpei           #+#    #+#             */
/*   Updated: 2021/11/30 23:28:09 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "main.h"
#include "rule.h"

t_bool	is_sort(t_vec *vec)
{
	while (vec->next != NULL)
	{
		if (vec->value > vec->next->value)
			return (FALSE);
		vec = vec->next;
	}
	return (TRUE);
}

int	min_elem(t_vec *vec)
{
	int		ans;

	ans = vec->value;
	while (vec != NULL)
	{
		if (ans > vec->value)
			ans = vec->value;
		vec = vec->next;
	}
	return (ans);
}

int	get_index(t_vec *vec, int elem)
{
	int	i;

	i = 0;
	while (vec != NULL)
	{
		if (vec->value == elem)
			return (i);
		i++;
		vec = vec->next;
	}
	return (i);
}

void	move_to_top_a(t_info *info, int index)
{
	if (index > info->a_len / 2)
	{
		while (info->a_len > index)
		{
			rra(info);
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			ra(info);
			index--;
		}
	}
}

void	move_top_b(t_info *info, int index)
{
	if (index > info->b_len)
	{
		while (info->b_len - index > 0)
		{
			rrb(info);
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			rb(info);
			index--;
		}
	}
}
