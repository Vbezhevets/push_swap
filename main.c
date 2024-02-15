#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

int dupl(t_node *s, int n, int size, t_data *_)
{
	int i;
	
	i = 0;
	s->s = 1;
	if (s->prev)
		while (++i <= size)
		{
			if (n == s->prev->num)
				return (error (_), 1);
			s = s->prev;
		}
	return 0;
}

int	fill_a(char **nums, t_data *_, int i)
{
	t_node	*node;
	t_node	*prev;

	prev = NULL;
	node = _->a;
	while (nums[++i])
	{
		node->num = ft_atoi(nums[i]);
		node->prev = prev;
		prev = node;
		if (nums[i + 1] && !dupl(node, node->num, i, _))
		{
			node->next = (t_node *)ft_calloc(1, sizeof(t_node));
				if (!node->next)
					error(_);
			node->_ = _;
			node->steps = MAX;
			node->s = 1;
			node = node->next;
		}
		else
		{
		 	node->next = _->a;
			node->_ = _;
			node->s = 1;
			node->steps = MAX;
			_->a->prev = node; 
		}
	}
	return(i);
}

t_data *init_null(t_data *_)
{
	_ = (t_data *)ft_calloc(1, sizeof(t_data));
	_->a = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!_ || !_->a)
			error(_);
	_->a->next = NULL;
	_->a->pair = NULL;
	_->a->prev = NULL;
	_->b = NULL;
	_->b_qty = 0;
	_->allsteps = 0;
	return _;
}

void check_and_load(char **str, t_data *_)
{
	if (1)
		_->a_qty = fill_a(str, _, -1);

	if (_->a_qty > 1)
	{	
		indx(_->a, _);
		go(_);
	}
	else
		exit(0);
}
int main(int argc, char **argv)
{
	t_data *_;
	_ = NULL;

	_ = init_null(_);
	if (argc == 2)
		check_and_load(ft_split(argv[1], ' '), _);
	else if (argc > 2)
		check_and_load((argv + 1), _);
	else
		exit(1);
	
}	