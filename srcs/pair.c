/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:35:36 by bvalerii          #+#    #+#             */
/*   Updated: 2024/02/20 16:43:32 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pair_max(t_node *s, t_node *bg, int size)
{
	int	max;
	int	i;

	i = 1;
	max = MIN;
	while (i <= size)
	{
		if (bg->num > max)
		{
			max = bg->num;
			s->pair = bg;
		}
		bg = bg->next;
		i++;
	}
}

void	pair_min(t_node *s, t_node *bg, int size)
{
	int	min;
	int	i;

	i = 1;
	min = MAX;
	while (i <= size)
	{
		if (bg->num < min)
		{
			min = bg->num;
			s->pair = bg;
		}
		bg = bg->next;
		i++;
	}
}

void	pair_min_diff(t_node *s, t_node *bg, int size)
{
	int		i;
	long	min_diff;

	min_diff = MAX;
	i = 0;
	while (++i <= size)
	{
		if (bg->p_found == 1)
		{
			if (min_diff > bg->dist)
			{
				min_diff = bg->dist;
				s->pair = bg;
			}
		}
		bg = bg->next;
	}
}

void	pair(t_node *s, t_node *bg, int size, int i)
{
	t_node	*bg_start;

	bg_start = bg;
	s->p_found = 0;
	while (++i <= size)
	{
		if ((s->num > bg->num && s->s == 1) || (s->num < bg->num && s->s == 2))
		{
			if (s->s == 1)
				bg->dist = s->num - bg->num;
			else
				bg->dist = bg->num - s->num;
			bg->p_found = 1;
			s->p_found = 1;
		}
		else
			bg->p_found = -1;
		bg = bg->next;
	}
	if (s->p_found != 1 && s->s == 1)
		pair_max(s, bg_start, size);
	else if (s->p_found != 1 && s->s == 2)
		pair_min(s, bg_start, size);
	else
		pair_min_diff(s, bg_start, size);
}
