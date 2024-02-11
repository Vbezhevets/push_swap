#include "libft/libft.h"
#include "push_swap.h"


void re_ind(t_data *_)
{
	if (_->a_qty > 1)
		indx(_->a);
	if (_->b_qty > 1)
		indx(_->b);
	else
		_->b->index = 1;
}

int m(t_node *s, int size, t_data *_)
{
	re_ind(_);
	if (s->index <= ((size + 1)/2))
		return 0;
	return 1;
}

int f(t_node *s, t_data *_)
{
	re_ind(_);
	if (s->index == 1)
		return (1);
	return (0);
}


void p(char *m, t_data *_)
{
	ft_printf("%s\n", m);
	_->c++;
}
void step(t_node *a, t_node *s)
{
	a->steps++;
	indx(s);
}