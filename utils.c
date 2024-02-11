
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

int indx(t_node *s)
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

t_node *cpy_loop(t_node * dst, t_node *src, int size, int i)
{
	t_node *prev;

	prev = dst;
	dst->num = src->num;
	dst->index = src->index;
	dst->steps = 0;
	dst->pair = src->pair;
	if (i == size)
		return(dst);
	dst->next = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!dst->next)
		return(NULL);
	dst = dst->next;
	dst->prev = prev;
	i++;
	return(dst);
}


t_node *copy_list(t_node *src, int size, t_data *_, int i)
{
  	t_node *start;
    t_node *dst;
    
	start = (t_node *)ft_calloc(1, sizeof(t_node));
        if (!start)
        return (error(MLC_ERR, _), NULL);
    dst = start;
	while (++i <= size)
	{
		dst = cpy_loop(dst, src, size, i);
			if (dst == NULL)
  				return (free_list(start), error(MLC_ERR, _), NULL);
		src = src->next;
	}
	if (i > 1)
	{
		dst->next = start;
		start->prev = dst;
	}
	else 
	{
		start->next = NULL;
		start->prev = NULL;
	}
	return (start);
}



