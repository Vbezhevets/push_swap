/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:30 by bvalerii          #+#    #+#             */
/*   Updated: 2024/02/20 16:54:43 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_ind(t_data *_)
{
	if (_->a)
		indx(_->a, _);
	if (_->b)
		indx(_->b, _);
}

int	m(t_node *s, int size, t_data *_)
{
	re_ind(_);
	if (s->index <= size / 2)
		return (0);
	return (1);
}

int	f(t_node *s, t_data *_)
{
	re_ind(_);
	if (s->index == 1)
		return (1);
	return (0);
}

t_node	*find_max(t_node *s, int size)
{
	int	i;

	i = 0;
	while (++i != find_maxi(s, size))
		s = s->next;
	return (s);
}
