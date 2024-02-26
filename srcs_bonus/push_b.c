/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:45:35 by bvalerii          #+#    #+#             */
/*   Updated: 2024/02/24 13:59:14 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*push(t_node *new, t_node *old)
{
	new->pair = NULL;
	new->p_found = 0;
	new->steps = MAX;
	new->dist = MAX;
	if (old)
	{
		new->next = old;
		if (old->prev)
		{
			new->prev = old->prev;
			old->prev->next = new;
		}
		else
		{
			new->prev = old;
			old->next = new;
		}
		old->prev = new;
	}
	else
	{
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

void	pb(t_data *_)
{
	t_node	*s;

	if (!_->a)
		ko(_);
	s = _->a;
	if (s->next)
	{
		_->a_top = s->next;
		if (s->prev != s->next)
		{
			s->prev->next = s->next;
			s->next->prev = s->prev;
		}
		else
		{
			_->a_top->next = NULL;
			_->a_top->prev = NULL;
		}
	}
	else
		_->a_top = NULL;
	_->b = push(_->a, _->b);
	_->a = _->a_top;
	_->b_qty++;
	_->a_qty--;
}

void	pa(t_data *_)
{
	t_node	*n;

	if (!_->b)
		ko(_);
	n = _->b;
	if (n->next)
	{
		_->b_top = n->next;
		if (n->prev && n->prev != n->next)
		{
			n->prev->next = n->next;
			n->next->prev = n->prev;
		}
		else
		{
			_->b_top->next = NULL;
			_->b_top->prev = NULL;
		}
	}
	else
		_->b_top = NULL;
	_->a = push(_->b, _->a);
	_->b = _->b_top;
	_->b_qty--;
	_->a_qty++;
}
