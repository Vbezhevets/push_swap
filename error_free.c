#include "push_swap.h"

void free_list(t_node *s)
{
	while(s)
	{
		if (s->next)
		{
			s = s->next;
			free(s->prev);
			s->prev = NULL;
		}
		else
		{
			free(s);
			s = NULL;
		}
	}
}

void free_null(t_data *_)
{
	t_node	*s;

	s = NULL;
	if (_->a)
		s = _->a;
	else if(_->b)
		s = _->b;
	else if (_)
		free(_);
	else
		return;
	free_list(s);
	free_null(_);
}


int error(char * m, t_data *_)
{
	ft_printf("%s", m);
	if (_) free_null(_);
	exit(1);
}
