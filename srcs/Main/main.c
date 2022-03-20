/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:56:05 by yjimpei           #+#    #+#             */
/*   Updated: 2021/12/28 16:14:24 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "main.h"
#include "rule.h"

/*
void	end(void)__attribute__((destructor));

void	end(void)
{
	system("leaks push_swap");
}
*/

static void	all_memory_free(t_info *info)
{
	while (info->a_vec)
		elem_delete(&(info->a_vec), 0);
	while (info->b_vec)
		elem_delete(&(info->b_vec), 0);
	ft_lstclear(&(info->ope_list), NULL);
	free(info);
}

static void	push_swap(t_info *info)
{
	if (is_sort(info->a_vec) == TRUE)
		return ;
	if (info->a_len <= 3)
		few_sort_a(info);
	else if (info->a_len <= 6)
		middle_sort(info);
	else
		many_sort(info);
	if (info->a_len >= 6)
		reduce_ans(info);
	ft_lstput(&(info->ope_list));
}

int	main(int argc, char **argv)
{
	t_info	*info;
	int		index;

	if (is_correct_input(argc, argv) == FALSE)
		return (1);
	info = malloc(sizeof(t_info));
	info->a_vec = NULL;
	info->b_vec = NULL;
	info->ope_list = NULL;
	index = 0;
	while (++index < argc)
		elem_add_bottom(&(info->a_vec), ft_atoi(argv[index]));
	info->a_len = argc - 1;
	info->b_len = 0;
	if (is_deplicate(&(info->a_vec), info) == TRUE)
		return (1);
	push_swap(info);
	all_memory_free(info);
	return (0);
}
