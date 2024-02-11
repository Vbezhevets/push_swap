#include "push_swap.h"
 void operations(t_data *_, t_node *a)
{	
	pr_single(a);
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