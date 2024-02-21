/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:45:43 by bvalerii          #+#    #+#             */
/*   Updated: 2024/02/20 17:49:02 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (!_->a)
		ko(_);
	_->a = rotate(_->a);
}

void	rb(t_data *_)
{
	if (!_->b)
		ko(_);
	_->b = rotate(_->b);
}

void	rr(t_data *_)
{
	if (!_->b || !_->a)
		ko(_);
	_->a = rotate(_->a);
	_->b = rotate(_->b);
}
