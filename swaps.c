#include "push_swap.h"

t_node *swap(t_node *s)
{
	if (s)
	{
		t_node * node;
		// [p]->[s]->[n]->(node) 		<-s
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
			return s;
	}
	return NULL;
}
void sa(t_data *_)
{
	_->a = swap(_->a);
	ft_printf("sa\n");
}
void sb(t_data *_)
{
	_->b = swap(_->b);
	ft_printf("sb\n");
}
void ss(t_data *_)
{
	_->a = swap(_->a);
	_->b = swap(_->b);
	ft_printf("ss\n");
}

