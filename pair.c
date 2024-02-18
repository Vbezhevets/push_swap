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

void pair(t_node *s, t_node *big, int size, int i)
{
	t_node *big_start;

	big_start = big;
	s->p_found = 0;
	while (++i <= size)
	{
		if ((s->num > big->num && s->s == 1) || (s->num < big->num && s->s == 2))
		{
			if (s->s == 1)
				big->dist = s->num - big->num;
			else 
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
 