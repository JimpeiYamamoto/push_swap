/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:43:00 by yjimpei           #+#    #+#             */
/*   Updated: 2021/11/30 23:28:33 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "main.h"
#include "rule.h"

static void	quick_init(t_info *info)
{
	info->group = 1;
	info->loop = FALSE;
	info->first = TRUE;
	info->not_sort = info->a_len;
}

static void	all_pb(t_info *info)
{
	int	len;

	len = info->not_sort;
	while (len > 0)
	{
		pb(info);
		len--;
	}
}

static void	half_pb(t_info *info)
{
	int		ra_cnt;
	int		median;
	int		len;
	t_vec	*ptr;

	ra_cnt = 0;
	median = get_median(info->a_vec, 0, info->not_sort);
	len = info->not_sort;
	while (len > 0)
	{
		ptr = info->a_vec;
		if (median > ptr->value)
			pb(info);
		else
		{
			ra(info);
			ra_cnt++;
		}
		len--;
	}
	while (ra_cnt > 0 && info->first == FALSE)
	{
		rra(info);
		ra_cnt--;
	}
}

static void	group_pb(t_info *info)
{
	t_vec	*ptr;
	int		select_group;

	ptr = info->a_vec;
	select_group = ptr->group;
	while (ptr->group == select_group)
	{
		ptr = info->a_vec;
		pb(info);
		ptr = info->a_vec;
	}
}

void	many_sort(t_info *info)
{
	t_vec	*ptr_a;

	quick_init(info);
	while (1)
	{
		ptr_a = info->a_vec;
		if (ptr_a->group == 0)
			info->loop = FALSE;
		else
			info->loop = TRUE;
		if (info->not_sort <= 6)
			all_pb(info);
		else if (info->loop == FALSE)
			half_pb(info);
		else
			group_pb(info);
		info->first = FALSE;
		if (is_sort(info->a_vec) == TRUE && info->b_len == 0)
			break ;
		while (info->b_len > 6)
			loop_quick(info);
		info->not_sort -= info->b_len;
		six_sort_pa(info);
	}
}
