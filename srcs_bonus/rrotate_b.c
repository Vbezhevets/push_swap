/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:45:54 by bvalerii          #+#    #+#             */
/*   Updated: 2024/02/20 17:49:26 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*rrotate(t_node *s)
{
	if (!s)
		return (NULL);
	if (s->prev)
		return (s->prev);
	return (s);
}

void	rra(t_data *_)
{
	if (!_->a)
		ko(_);
	_->a = rrotate(_->a);
}

void	rrb(t_data *_)
{
	if (!_->b)
		ko(_);
	_->b = rrotate(_->b);
}

void	rrr(t_data *_)
{
	if (!_->b || !_->a)
		ko(_);
	_->a = rrotate(_->a);
	_->b = rrotate(_->b);
}
