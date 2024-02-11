#include "push_swap.h"



t_node * rrotate(t_node *s)
{
	if (!s)
		return NULL;
	if (s->prev)
		return (s->prev);
	return s;
}

void rra(t_data *_)
{
	_->a = rrotate(_->a);
	p("rra", _);
}
void rrb(t_data *_)
{
	_->b = rrotate(_->b);
	p("rrb", _);
}
void rrr(t_data *_)
{
	_->a = rrotate(_->a);
	_->b = rrotate(_->b);
	p("rrr", _);
}