#include "push_swap.h"


t_node * rotate(t_node *s)
{
	if (!s)
		return NULL;
	if (s->next)
		return (s->next);
	return s;
}

void ra(t_data *_)
{
	_->a = rotate(_->a);
	p("ra", _);
}
void rb(t_data *_)
{
	_->b = rotate(_->b);
	p("rb", _);
}
void rr(t_data *_)
{
	_->a = rotate(_->a);
	_->b = rotate(_->b);
	p("rr", _);
}