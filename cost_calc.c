 
#include "libft/libft.h"
#include "push_swap.h"

void pair_max(t_node *s, t_node *big, int size)
{
	int max;
	int i;

	i = 1;
	max = MIN;
	while(i <= size)
	{
		if (big->num > max)
		{
			max = big->num;
			s->pair = big;
		}
		big = big->next;
		i++;
	}
}

void pair_min_diff(t_node *s, t_node *big, int size)
{
	int i;
	long min_diff;

	min_diff = MAX;
	i = 0;
	while (++i <= size)
	{
		if (big->p_found == 1)
			if (min_diff > big->dist)
			{
				min_diff = big->dist;
				s->pair = big;
			}
		big = big->next;
	}
}

void pair(t_node *s, t_node *big, int size)
{
	int i;
	t_node *big_start;
	i = 0;
	big_start = big;
	s->p_found = 0;
	while (++i <= size)
	{
		if (s->num >= big->num)
		{
			big->dist = s->num - big->num;
			big->p_found = 1;
			s->p_found = 1;
		}
		else
			big->p_found = -1;
		big = big->next;
	}
	if (s->p_found != 1)
		pair_max(s, big_start, size);
	else
		pair_min_diff(s, big_start, size);
}

int steps_s(t_node *s, int size, t_data *_)
{
	int steps;
	if (m(s, size, _))
		steps = size - s->index + 1;
	else
	 	steps = s->index - 1;
	return steps;
}
int steps_calc(t_data *_, t_node *a, t_node *pair)
{
	int a_steps;
	int b_steps;
	int steps;
	int d;
	
	d = 0;
	a_steps = steps_s(a, _->a_qty, _);
	b_steps = steps_s(pair, _->b_qty, _);
	if ((m(a, _->a_qty, _) && m(pair, _->b_qty, _)) || !m(a, _->a_qty, _) && !m(pair, _->b_qty, _))
		d = (a_steps + b_steps) / 2;
	if (d < 0)
		d = -d;
	steps = a_steps + b_steps - d;
	return (steps);
}

t_node *cost_calc(t_data *_, t_node *a, t_node *b, int i)
{
	t_node *best;
	int min;
	
	min = MAX;
	while (++i <= _->a_qty)
	{
		pair(a, _->b, _->b_qty);
		a->steps = steps_calc(_, a, a->pair);
		if (a->steps < min)
		{
			min = a->steps;
			best = a;
		}
		if (a->steps == 0)
			break;
		a = a->next;
	}
	return best;
}