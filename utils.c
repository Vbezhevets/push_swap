
#include "libft/libft.h"
#include "push_swap.h"
int find_maxi(t_node *s, int size)
{
	int max;
	int i;
	int maxi;

	i = 1;
	max = MIN;
	while(i <= size)
	{
		if (s->num > max)
		{
			max = s->num;
			maxi = s->index;
		}
		s = s->next;
		i++;
	}
	return (maxi);
}

int is_sorted(t_node *s)
{
	int i;
	int lasti;
	i = 1;
	lasti = indx(s);
	while (i < lasti)
	{
		
		if (s->num > s->next->num)
			return(0);
		s = s->next;
		i++;
	}
	return (1);
}

int indx(t_node *s	)
{
	int i; 
	t_node *point;

	i = 0;
	if (!s->prev || !s)
		return(1);
	point = s->prev;
	while(s != point)
	{
		i++;
		s->index = i;
		s->dist = 0;
		s = s->next;
	}
	s->index = ++i;
	return i;
}

t_node *find_max(t_node *s, int size)
{
	int i;
	i = 0;
	while (++i != find_maxi(s, size))
		s = s->next;
	return(s);
}
