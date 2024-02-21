/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:46:07 by bvalerii          #+#    #+#             */
/*   Updated: 2024/02/20 17:48:46 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*swap(t_node *s)
{
	t_node	*node;

	if (s)
	{
		if (s->next)
		{
			if (s->next != s->prev)
			{
				node = s->next->next;
				s->next->next = s;
				node->prev = s;
				s->prev->next = s->next;
				s->next->prev = s->prev;
				s->prev = s->next;
				s->next = node;
			}
			return (s->prev);
		}
		else
			return (s);
	}
	return (NULL);
}

void	sa(t_data *_)
{
	if (!_->a)
		ko(_);
	_->a = swap(_->a);
}

void	sb(t_data *_)
{
	if (!_->b)
		ko(_);
	_->b = swap(_->b);
}

void	ss(t_data *_)
{
	if (!_->b || !_->a)
		ko(_);
	_->a = swap(_->a);
	_->b = swap(_->b);
}
