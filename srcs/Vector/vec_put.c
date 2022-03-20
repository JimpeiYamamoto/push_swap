/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:46:10 by yjimpei           #+#    #+#             */
/*   Updated: 2021/11/30 13:47:43 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"

void	listPrint(t_vec *ptr)
{
	char	*str;

	ft_putstr_fd("{ ", 1);
	while (ptr != NULL)
	{
		str = ft_itoa(ptr->value);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(" ", 1);
		free(str);
		ptr = ptr->next;
	}
	ft_putendl_fd("}", 1);
}

void	put_vec_set(t_vec *ptr1, t_vec *ptr2)
{
	ft_putendl_fd("---A---", 1);
	listPrint(ptr1);
	ft_putendl_fd("---B---", 1);
	listPrint(ptr2);
}
