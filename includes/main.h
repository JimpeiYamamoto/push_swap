/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:29:25 by yjimpei           #+#    #+#             */
/*   Updated: 2021/11/30 23:24:51 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "vector.h"

typedef struct s_info
{
	t_vec	*a_vec;
	t_vec	*b_vec;
	t_list	*ope_list;
	int		a_len;
	int		b_len;
	int		not_sort;
	int		group;
	t_bool	first;
	t_bool	loop;
}			t_info;
/*
error_check
*/
t_bool	is_correct_input(int argc, char **argv);
t_bool	is_deplicate(t_vec **vec, t_info *info);
/*
push_swap
*/
void	few_sort_a(t_info *info);
void	few_sort_b(t_info *info);
void	middle_sort(t_info *info);
void	middle_sort_b(t_info *info);
void	many_sort(t_info *info);
/*
push_utils
*/
t_bool	is_sort(t_vec *vec);
int		min_elem(t_vec *vec);
int		get_index(t_vec *vec, int elem);
void	move_to_top_a(t_info *info, int index);
void	move_top_b(t_info *info, int index);
int		get_median(t_vec *vec, int start, int stop);
void	loop_quick(t_info *info);
void	six_sort_pa(t_info *info);
/*
reduce_ans
*/
void	reduce_ans(t_info *info);

#endif