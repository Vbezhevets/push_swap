
#include "libft/libft.h"
#include "push_swap.h"

t_node *push(t_node *new, t_node *old)
{
	new->pair = NULL;
	new->p_found = 0;
	new->steps = MAX;
	new->dist = MAX;
	if (old)
	{
		new->next = old;
		if (old->prev)
		{
			new->prev = old->prev;
			old->prev->next = new;
		}
		else
		{
			new->prev = old;
			old->next = new;
		}
		old->prev = new;
	}
	else
	{
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

void pb (t_data *_)
{
	t_node *s;

	s = _->a;
	if (s->next)
	{
		_->a_top = s->next;
		if (s->prev != s->next)
		{
			s->prev->next = s->next;
			s->next->prev = s->prev;
		}
		else
		{
			_->a_top->next = NULL;
			_->a_top->prev = NULL;
		}
	}
	else
		_->a_top = NULL;
	_->a->s = 2;	
	_->b = push(_->a, _->b);
	_->a = _->a_top;
	_->a_qty--;
	_->b_qty++;
	ft_printf("pb\n");
}

void pa (t_data *_)
{
	t_node *n;

	n = _->b;
	if (n->next)
	{
		_->b_top = n->next;
		if (n->prev && n->prev != n->next)
		{
			n->prev->next = n->next;
			n->next->prev = n->prev;
		}
		else
		{
			_->b_top->next = NULL;
			_->b_top->prev = NULL;
		}
	}
	else 
		_->b_top = NULL;
	_->b->s = 1;
	_->a = push(_->b, _->a);
	_->b = _->b_top;
	_->b_qty--;
	_->a_qty++;
	ft_printf("pa\n");
}


