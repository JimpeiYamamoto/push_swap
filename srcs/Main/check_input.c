/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:28:08 by yjimpei           #+#    #+#             */
/*   Updated: 2021/12/19 00:56:27 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "main.h"

static t_bool	is_num(char *str)
{
	if (*str == '+' || *str == '-')
	{
		str++;
		if (!*str)
			return (FALSE);
	}
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (FALSE);
		str++;
	}
	return (TRUE);
}

static t_bool	is_int(char *str)
{
	long long	num;
	int			sign;

	if ((*str == '+' || *str == '-') && (ft_strlen(str) >= 12))
		return (FALSE);
	else if (*str != '+' && *str != '-' && ft_strlen(str) >= 11)
		return (FALSE);
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	num = *str - '0';
	while (*(++str))
	{
		num *= 10;
		num += *str - '0';
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	is_correct_input(int argc, char **argv)
{
	int	index;

	if (argc == 1)
		return (FALSE);
	index = 1;
	while (index < argc)
	{
		if (is_num(argv[index]) == FALSE || is_int(argv[index]) == FALSE)
		{
			ft_putendl_fd("Error", 2);
			return (FALSE);
		}
		index++;
	}
	return (TRUE);
}

t_bool	is_deplicate(t_vec **vec, t_info *info)
{
	int		tmp;
	t_vec	*ptr;
	t_vec	*ptr2;

	ptr = *vec;
	while (ptr != NULL)
	{
		tmp = ptr->value;
		ptr2 = ptr->next;
		while (ptr2 != NULL)
		{
			if (tmp == ptr2->value)
			{
				while (info->a_vec)
					elem_delete(&(info->a_vec), 0);
				ft_lstclear(&(info->ope_list), NULL);
				free(info);
				ft_putendl_fd("Error", 2);
				return (TRUE);
			}
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	return (FALSE);
}
