#include "checker.h"

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
	if (!_->a)
		ko(_);
	_->a = rotate(_->a);
	// ft_printf("ra\n");
}
void rb(t_data *_)
{
	if (!_->b)
		ko(_);
	_->b = rotate(_->b);
	// ft_printf("rb\n");
}
void rr(t_data *_)
{
	if (!_->b || !_->a)
		ko(_);
	_->a = rotate(_->a);
	_->b = rotate(_->b);
	// ft_printf("rr\n");
}