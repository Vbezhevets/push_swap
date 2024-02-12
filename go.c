#include "libft/libft.h"
#include "push_swap.h"

void sort_2(t_data *_)
{
	if (_->a->num > _->a->next->num)
		sa(_);
}

void sort_3(t_data *_)
{
	int maxi;

	maxi = find_maxi(_->a, 3);
	ft_printf("%d MI\n\n\n", maxi);
	if (maxi == 1)
		ra(_);
	if (maxi == 2)
		rra(_);
	sort_2(_);
}

void turk(t_data *_)
{
	t_node *best;

	while (_->a_qty > 3 && _->b_qty <2)
		pb(_);
	re_ind(_);
	while (_->a_qty > 3)
	{
		best = cost_calc(_, _->a, _->b, 0);
		operations(_, best);
		re_ind(_);
	}
	re_ind(_);
	
	sort_3(_);
	prt(_);

	back_to_a(_);
	prt(_);

	//while (!is_sorted())2
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