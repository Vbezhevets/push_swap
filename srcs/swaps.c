/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:38 by bvalerii          #+#    #+#             */
/*   Updated: 2024/02/20 16:58:32 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	_->a = swap(_->a);
	ft_printf("sa\n");
}

void	sb(t_data *_)
{
	_->b = swap(_->b);
	ft_printf("sb\n");
}

void	ss(t_data *_)
{
	_->a = swap(_->a);
	_->b = swap(_->b);
	ft_printf("ss\n");
}
