
#include "libft/libft.h"
#include "push_swap.h"
#include <alloca.h>

t_node *push(t_node *new, t_node *old)
{
		// [p]->[]->[s]
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
	else {

		ft_printf("ELSE \n");
		_->a_top = NULL;
	}
	_->b = push(_->a, _->b);
	_->a = _->a_top;
	_->a_qty--;
	_->b_qty++;
	p("pb", _);
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
	_->a = push(_->b, _->a);
	_->b = _->b_top;
	_->b_qty--;
	_->a_qty++;
	p("pa", _);
}

/*
t_node *from_to(t_node *from, t_node *to) 
{
	t_node *s;
	t_node *node;

	s = from;
	if (s->next)
	{
		node = s->next;
		if (s->prev && s->prev != s->next)
		{
			s->prev->next = s->next;
			s->next->prev = s->prev;
		}
		else
		{
			node->next = NULL;
			node->prev = NULL;
		}
	}
	else
		node = NULL;
	to = push(from, to);

	from = node;
}

void pb (t_data *_)
{

	ft_printf("a: \n%p\nb: \n%p\n",_->a, _->b);
	from_to(_->a, _->b);
	
	ft_printf("a: \n%p\nb: \n%p\n",_->a, _->b);
	_->a_qty--;
	_->b_qty++;
}
*/

// :-[]
/*
void from_to (t_node *one, t_node *two)
{
	t_node *n;
	t_node *node;

	if (!one)
		return;

	n = one;
	if (n->next)
	{
		node = n->next;
		if (n->prev && n->prev != n->next)
		{
			n->prev->next = n->next;
			n->next->prev = n->prev;
		}
		else
		{
			node->next = NULL;
			node->prev = NULL;
		}
	}
	else 
		node = NULL;
	two = push(one, two);
	one = node;
} 
void pb (t_data *_)
{
	from_to (_->a, _->b);
}
void pa (t_data *_)
{
	from_to (_->b, _->a);
}
*/
