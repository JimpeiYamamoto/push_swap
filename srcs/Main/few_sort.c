/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:14:54 by yjimpei           #+#    #+#             */
/*   Updated: 2021/11/30 17:40:23 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "main.h"
#include "rule.h"

static int	judge_three(t_vec *top)
{
	int	first;
	int	second;
	int	third;

	first = top->value;
	second = top->next->value;
	third = top->next->next->value;
	if (first >= second && second <= third && first <= third)
		return (1);
	if (first >= second && second >= third && first >= third)
		return (2);
	if (first <= second && second >= third && first >= third)
		return (3);
	if (first <= second && second >= third && first < third)
		return (4);
	return (5);
}

void	few_sort_a(t_info *info)
{
	int	how_ope;

	if (info->a_len == 1 || is_sort(info->a_vec) == TRUE)
		return ;
	if (info->a_len == 2)
	{
		sa(info);
		return ;
	}
	how_ope = judge_three(info->a_vec);
	if (how_ope == 1 || how_ope == 2)
	{
		sa(info);
		if (how_ope == 2)
			rra(info);
	}
	else if (how_ope == 3 || how_ope == 4)
	{
		rra(info);
		if (how_ope == 4)
			sa(info);
	}
	else
		ra(info);
}

void	few_sort_b(t_info *info)
{
	int	how_ope;

	if (info->b_len == 1 || is_sort(info->b_vec) == TRUE)
		return ;
	if (info->b_len == 2)
	{
		sb(info);
		return ;
	}
	how_ope = judge_three(info->b_vec);
	if (how_ope == 1 || how_ope == 2)
	{
		sb(info);
		if (how_ope == 2)
			rrb(info);
	}
	else if (how_ope == 3 || how_ope == 4)
	{
		rrb(info);
		if (how_ope == 4)
			sb(info);
	}
	else
		rb(info);
}
