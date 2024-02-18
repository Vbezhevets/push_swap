 
#include "libft/libft.h"
#include "push_swap.h"


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
	big_steps = steps_s(s->pair, big_size, _);
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
		pair(s, big, big_size, 0);
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