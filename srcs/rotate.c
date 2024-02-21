/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:13 by bvalerii          #+#    #+#             */
/*   Updated: 2024/02/20 16:51:56 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*rotate(t_node *s)
{
	if (!s)
		return (NULL);
	if (s->next)
		return (s->next);
	return (s);
}

void	ra(t_data *_)
{
	_->a = rotate(_->a);
	ft_printf("ra\n");
}

void	rb(t_data *_)
{
	_->b = rotate(_->b);
	ft_printf("rb\n");
}

void	rr(t_data *_)
{
	_->a = rotate(_->a);
	_->b = rotate(_->b);
	ft_printf("rr\n");
}
