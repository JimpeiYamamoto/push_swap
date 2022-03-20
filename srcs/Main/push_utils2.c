/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:05:36 by yjimpei           #+#    #+#             */
/*   Updated: 2021/11/30 22:02:37 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "main.h"
#include "rule.h"

static t_bool	is_median(t_vec *vec, int start, int stop, int num)
{
	int	i;
	int	cnt;

	i = 0;
	while (i < start)
	{
		vec = vec->next;
		i++;
	}
	cnt = 0;
	while (i < stop)
	{
		if (num > vec->value)
			cnt++;
		i++;
		vec = vec->next;
	}
	if (cnt == (stop - start) / 2)
		return (TRUE);
	else
		return (FALSE);
}

int	get_median(t_vec *vec, int start, int stop)
{
	t_vec	*ptr;
	int		i;

	i = 0;
	ptr = vec;
	while (ptr != NULL)
	{
		if (i >= start && i <= stop)
		{
			if (is_median(vec, start, stop, ptr->value) == TRUE)
				return (ptr->value);
		}
		i++;
		ptr = ptr->next;
	}
	return (vec->value);
}

static void	give_group(t_info *info, int value)
{
	int		index;
	t_vec	*ptr;

	index = get_index(info->a_vec, value);
	ptr = info->a_vec;
	while (index > 0)
	{
		ptr = ptr->next;
		index--;
	}
	ptr->group = info->group;
}

void	loop_quick(t_info *info)
{
	int		len;
	int		value;
	int		median;
	t_vec	*ptr;

	len = info->b_len;
	median = get_median(info->b_vec, 0, len);
	while (len > 0)
	{
		ptr = info->b_vec;
		if (median < ptr->value)
		{
			value = ptr->value;
			pa(info);
			give_group(info, value);
		}
		else
			rb(info);
		len--;
	}
	(info->group)++;
}

void	six_sort_pa(t_info *info)
{
	middle_sort_b(info);
	while (info->b_len > 0)
	{
		pa(info);
		ra(info);
	}
}
