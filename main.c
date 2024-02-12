#include "libft/libft.h"
#include "push_swap.h"

int	fill_a(char **nums, t_data *_, int i)
{
	t_node	*node;
	t_node	*prev;

	prev = NULL;
	node = _->a;
	while (nums[i])
	{
		node->num = ft_atoi(nums[i]);
		node->prev = prev;
		prev = node;
		if (nums[i + 1])
		{
			node->next = (t_node *)ft_calloc(1, sizeof(t_node));
				if (!node->next)
					error(MLC_ERR, _);
			node = node->next;
		}
		else
		{
		 	node->next = _->a;
			_->a->prev = node; 
		}
		i++;
	}
	return(i);
}

t_data *init_null(t_data *_)
{
	_ = (t_data *)ft_calloc(1, sizeof(t_data));
	_->a = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!_ || !_->a)
		{
			error(MLC_ERR, _);
			exit (1);
		}
	_->a->next = NULL;
	_->a->pair = NULL;
	_->a->prev = NULL;
	_->b = NULL;
	_->b_qty = 0;
	_->c = 0;
	return _;
}

void check_and_load(char **str, t_data *_)
{
	if (1)
		_->a_qty = fill_a(str, _, 0);

	if (_->a_qty > 1)
	{	
		indx(_->a);
		go(_);
	}
	else
		ft_printf("sorted\n");
}
int main(int argc, char **argv)
{

	t_data *_;

	_ = init_null(_);

	if (argc == 2)
		check_and_load(ft_split(argv[1], ' '), _);
	else if (argc > 2)
		check_and_load((argv + 1), _);
	else
		ft_printf("No parameters\n");
	
}	