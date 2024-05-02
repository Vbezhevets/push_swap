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

int	steps_s(t_node *s, int size, t_data *_) //calculating steps to top
{
	int	steps;

	if (m(s, size, _))
		steps = size - s->index + 1;  //if node is above middle of it's stack we should
	else
		steps = s->index - 1; //if node is under middle of it's stack just substract
	s->steps = steps;
	return (steps);
}

int	steps_calc(t_data *_, t_node *s, int s_size, int bg_size)
{
	int	s_steps;
	int	bg_steps;
	int	steps;

	s_steps = steps_s(s, s_size, _); //steps needed for Node to come to the top
	bg_steps = steps_s(s->pair, bg_size, _); //steps needed for node to the top in destiantion stack
	if ((m(s, s_size, _) && m(s->pair, bg_size, _)) //m - calculates if node is under or above the midle of it's stack
		|| (!m(s, s_size, _) && !m(s->pair, bg_size, _))) // if they both have the same diraction for moving, we can ignore the smaller distance (cause we can use one operation to turn both)
	{
		if (s_steps >= bg_steps)
			steps = s_steps;
		else
			steps = bg_steps;
	}
	else
		steps = s_steps + bg_steps; // if both nodes has different direciton for moving to the top we must add two 
	return (steps);
}

t_node	*cost_calc(t_node *s, t_node *bg, int s_size, int bg_size)
{
	t_node	*best_s;
	long	min;
	int		i;

	i = 1;
	min = MAX;
	while (i <= s_size) // searching for Node that has less steps (qty of operrations)
	{
		pair(s, bg, bg_size, 0);
		s->steps = steps_calc(s->_, s, s_size, bg_size); 
		if (s->steps == 0)
			return (s); // allready the best case, no operations needed (excepting push)
		if (s->steps < min) // less than previous saved in min
		{
			min = s->steps;
			best_s = s;
		}
		if (s->next)
			s = s->next;
		i++;
	}
	return (best_s); // return node that has minimum operations with it's pair
}
