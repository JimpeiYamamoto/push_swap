/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:04:37 by yjimpei           #+#    #+#             */
/*   Updated: 2021/11/30 23:32:37 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

t_vec	*create_new(int value, t_vec *next)
{
	t_vec	*ptr;

	ptr = malloc(sizeof(t_vec));
	if (!ptr)
		return (NULL);
	else
	{
		ptr->value = value;
		ptr->group = 0;
		ptr->next = next;
		return (ptr);
	}
}

t_bool	elem_add_top(t_vec **ptrptr, int value)
{
	t_vec	*ptr;

	ptr = create_new(value, *ptrptr);
	if (!ptr)
		return (FALSE);
	else
	{
		*ptrptr = ptr;
		return (TRUE);
	}
}

t_bool	elem_add_bottom(t_vec **ptrptr, int value)
{
	t_vec	*ptr;

	ptr = create_new(value, NULL);
	if (!ptr)
		return (FALSE);
	else
	{
		while (*ptrptr != NULL)
			ptrptr = &((*ptrptr)->next);
		*ptrptr = ptr;
		return (TRUE);
	}
}

t_bool	elem_delete(t_vec **ptrptr, int index)
{
	t_vec	*ptr;

	while (index > 0 && *ptrptr)
	{
		index--;
		ptrptr = &((*ptrptr)->next);
	}
	if (*ptrptr != NULL)
	{
		ptr = (*ptrptr)->next;
		free(*ptrptr);
		*ptrptr = ptr;
		return (TRUE);
	}
	else
		return (FALSE);
}
