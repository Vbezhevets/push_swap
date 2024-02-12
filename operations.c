#include "libft/libft.h"
#include "push_swap.h"
 void operations(t_data *_, t_node *a)
{	
	while (m(a, _->a_qty, _) && m(a->pair, _->b_qty, _) && !f(a, _) && !f(a->pair, _))
		rrr(_);
	while (!m(a, _->a_qty, _) && !m(a->pair, _->b_qty, _ ) && !f(a, _) && !f(a->pair, _))
		rr(_);
	if (!m(a, _->a_qty, _))
		while (!f(a, _))
			rra(_);
	else
		while (!f(a, _))
			ra(_);
	if (!m(a->pair, _->b_qty, _))
		while (!f(a->pair, _))
			rrb(_);
	else
		while (!f(a->pair, _))
			rb(_);
	if (f(a, _) && f(a->pair, _))
		pb(_);
	a->p_found = 0;
	a->pair->p_found = 0;
	a->pair->pair = NULL;
	a->pair = NULL;
}
void roll_b_min_top(t_data *_)
{
	t_node *max;
	
	re_ind(_);
	max = find_max(_->b, _->b_qty);
	if (max->prev)
		max = max->prev;
	while(!f(max, _))
	{
		if (m(max, _->b_qty, _))
			rrb(_);
		else
			rb(_);
	}
}
void back_to_a(t_data *_)
{
	t_node *top;

	while (_->b_qty > 1)
	{
		roll_b_min_top(_);
		while (_->a->num < _->b->num)
			ra(_);
		if (_->b->num <= _->a->num)
			pa(_);
	}
	top = find_max(_->a, _->a_qty);
		top = top->next;
	while(!f(top, _))
	{
		if (m(top, _->a_qty, _))
			rra(_);
		else
			ra(_);
	}
	if (_->b->num >= _->a->prev->num)
		pa(_);
	ra(_);
}

