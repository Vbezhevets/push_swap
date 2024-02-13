#include "libft/libft.h"
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
	ft_printf("rra\n");
}
void rrb(t_data *_)
{
	_->b = rrotate(_->b);
	ft_printf("rrb\n");
}
void rrr(t_data *_)
{
	_->a = rrotate(_->a);
	_->b = rrotate(_->b);
	ft_printf("rrr\n");
}