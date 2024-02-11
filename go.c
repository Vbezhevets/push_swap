#include "libft/libft.h"
#include "push_swap.h"

void sort_2(t_data *_)
{
	if (_->a->num > _->a->next->num)
		sa(_);
}

void sort_3(t_data *_)
{
	int max;
	max = find_maxi(_->a, 3);
	if (max == 1)
	{
		ra(_);
		sort_2(_);
	}
	if (max == 2)
	{
		ra(_);
		ra(_);
		sort_2(_);
	}
}

void turk(t_data *_)
{
	int i;
	t_node *best;

	i = 0;
	if (_->a_qty > 3)
	{
		pb(_);
		pb(_);	
		pb(_);		
	}
	// pr(_->a);
	re_ind(_);
	while (_->a_qty > 3)
	{
		best = cost_calc(_, _->a, _->b, 0);
		operations(_, best);
		re_ind(_);
		prt(_);
	}
	ft_printf("b: %p b: next %p b prev: %d\n", _->b, _->b->next, _->b->prev);
	ft_printf("__\n");
	pr_single(_->a);
	//while (!is_sorted())
}

void go(t_data *_)
{
	t_node * node;
	if (is_sorted(_->a))
	{
		ft_printf("sorted\n");
		return;
	}

	if (_->a_qty == 2)
		sort_2(_);

	if (_->a_qty == 3)
		sort_3(_);
	if (_->a_qty > 3)
		turk(_);
}