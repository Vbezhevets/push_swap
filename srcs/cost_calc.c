/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:34:48 by bvalerii          #+#    #+#             */
/*   Updated: 2024/03/04 19:50:11 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	steps_s(t_node *s, int size, t_data *_)
{
	int	steps;

	if (m(s, size, _))
		steps = size - s->index + 1;
	else
		steps = s->index - 1;
	s->steps = steps;
	return (steps);
}

int	steps_calc(t_data *_, t_node *s, int s_size, int bg_size)
{
	int	s_steps;
	int	bg_steps;
	int	steps;

	s_steps = steps_s(s, s_size, _);
	bg_steps = steps_s(s->pair, bg_size, _);
	if ((m(s, s_size, _) && m(s->pair, bg_size, _))
		|| (!m(s, s_size, _) && !m(s->pair, bg_size, _)))
	{
		if (s_steps >= bg_steps)
			steps = s_steps;
		else
			steps = bg_steps;
	}
	else
		steps = s_steps + bg_steps;
	return (steps);
}

t_node	*cost_calc(t_node *s, t_node *bg, int s_size, int bg_size)
{
	t_node	*best_s;
	long	min;
	int		i;

	i = 1;
	min = MAX;
	while (i <= s_size)
	{
		pair(s, bg, bg_size, 0);
		s->steps = steps_calc(s->_, s, s_size, bg_size);
		if (s->steps == 0)
			return (s);
		if (s->steps < min)
		{
			min = s->steps;
			best_s = s;
		}
		if (s->next)
			s = s->next;
		i++;
	}
	return (best_s);
}
