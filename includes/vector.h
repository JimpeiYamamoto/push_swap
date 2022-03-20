/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:03:30 by yjimpei           #+#    #+#             */
/*   Updated: 2021/11/30 23:22:50 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "libft.h"

typedef struct s_vec
{
	int				value;
	int				group;
	struct s_vec	*next;	
}					t_vec;
/*
print vec
*/
void	listPrint(t_vec *ptr);
void	put_vec_set(t_vec *ptr1, t_vec *ptr2);
/*
add_delete
*/
t_bool	elem_add_top(t_vec **ptrptr, int value);
t_bool	elem_add_bottom(t_vec **ptrptr, int value);
t_bool	elem_delete(t_vec **ptrptr, int index);

#endif