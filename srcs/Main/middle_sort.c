/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:50:18 by yjimpei           #+#    #+#             */
/*   Updated: 2021/11/30 23:27:19 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "main.h"
#include "rule.h"

void	middle_sort(t_info *info)
{
	while (info->a_len > 3)
	{
		move_to_top_a(info, get_index(info->a_vec, min_elem(info->a_vec)));
		pb(info);
	}
	few_sort_a(info);
	while (info->b_len > 0)
		pa(info);
}

void	middle_sort_b(t_info *info)
{
	int	cnt;

	cnt = 0;
	while (info->b_len > 3)
	{
		move_top_b(info, get_index(info->b_vec, min_elem(info->b_vec)));
		pa(info);
		cnt++;
	}
	few_sort_b(info);
	while (cnt > 0)
	{
		pb(info);
		cnt--;
	}
}
