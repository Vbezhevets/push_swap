 
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

void pair_min(t_node *s, t_node *big, int size)
{
	int min;
	int i;

	i = 1;
	min = MAX;
	while(i <= size)
	{
		if (big->num < min)
		{
			min = big->num;
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
		if (s->num > big->num && s->s == 1)
		{
			big->dist = s->num - big->num;
			big->p_found = 1;
			s->p_found = 1;
		}
		else if (s->num < big->num && s->s == 2)
		{
			big->dist = big->num - s->num;
			big->p_found = 1;
			s->p_found = 1;
		}
		else
			big->p_found = -1;
		big = big->next;
	}
	if (s->p_found != 1 && s->s == 1)
		pair_max(s, big_start, size);
	else if (s->p_found != 1 && s->s == 2)
		pair_min(s, big_start, size);	
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
	s->steps = steps;
	return steps;
}


int steps_calc(t_data *_, t_node *s, int s_size, int big_size)
{
	int s_steps;
	int big_steps;
	int steps;

	s_steps = steps_s(s, s_size, _);
	big_steps = steps_s(s->pair, big_size, _); //if found can skip Important to errase after push?? | st_found 1 
	if ((m(s, s_size, _) && m(s->pair, big_size, _)) || (!m(s, s_size, _) && !m(s->pair, big_size, _)))
		{
			if (s_steps >= big_steps)
				steps = s_steps;
			else
				steps = big_steps;
		}
	else
			steps = s_steps + big_steps;
	return (steps);
}

t_node *cost_calc(t_node *s, t_node *big, int s_size, int big_size)
{
	t_node *best_s;
	int min;
	int i;
	
	i = 0;
	min = MAX;
	while (++i <= s_size)
	{
		pair(s, big, big_size);
		s->steps = steps_calc(s->_, s, s_size, big_size);
		if (s->steps == 0)
				return s; 
		if (s->steps < min)
		{
			min = s->steps;
			best_s = s;
		}
		if (s->next)
			s = s->next;
	}
		return best_s;

}