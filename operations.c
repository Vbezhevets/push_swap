#include "libft/libft.h"
#include "push_swap.h"
void a_to_b(t_data *_, t_node *a)
{	
	while (m(a, _->a_qty, _) && m(a->pair, _->b_qty, _) && !f(a, _) && !f(a->pair, _))
		rrr(_);
	while (!m(a, _->a_qty, _) && !m(a->pair, _->b_qty, _ ) && !f(a, _) && !f(a->pair, _))
		rr(_);
	if (!m(a, _->a_qty, _))
		while (!f(a, _))
			ra(_);
	else
		while (!f(a, _))
			rra(_);
	if (!m(a->pair, _->b_qty, _))
		while (!f(a->pair, _))
			rb(_);
	else
		while (!f(a->pair, _))
			rrb(_);
	if (f(a, _) && f(a->pair, _))
		pb(_);
}

void b_to_a(t_data *_, t_node *b)
{	
	while (m(b, _->b_qty, _) && m(b->pair, _->a_qty, _) && !f(b, _) && !f(b->pair, _))
		rrr(_);
	while (!m(b, _->b_qty, _) && !m(b->pair, _->a_qty, _ ) && !f(b, _) && !f(b->pair, _))
		rr(_);
	if (!m(b, _->b_qty, _))
		while (!f(b, _))
			rb(_);
	else
		while (!f(b, _))
			rrb(_);
	if (!m(b->pair, _->a_qty, _))
		while (!f(b->pair, _))
			ra(_);
	else
		while (!f(b->pair, _))
			rra(_);
	if (f(b, _) && f(b->pair, _))
		pa(_);
}

void top(t_node *s, int size, t_data *_)
{
	t_node *max;
	
	re_ind(_);
	max = find_max(s, size);
	if (max->next)
		max = max->next;
	while(!f(max, _))
	{
		if (m(max, size, _))
			rra(_);
		else
			ra(_);
	}
}

void back_to_a(t_data *_)
{
	t_node *best;
	int maxi;
	
	maxi = find_maxi(_->b, 3);
	if (maxi == 1)
		rb(_);
	if (maxi == 2)
		rrb(_);
	if (_->b && _->b->next)
		if (_->b->num > _->b->next->num)
			sb(_);
	while (_->b_qty > 0)
	{
		pair(_->b, _->a, _->a_qty, 0);
		best = cost_calc(_->b, _->a, _->b_qty, _->a_qty);
		b_to_a(_, best);
		re_ind(_);
	}
	top(_->a,_->a_qty, _);
}

