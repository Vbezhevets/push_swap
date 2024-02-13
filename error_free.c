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
			if (_->a != NULL)
			free_list(_->a);
		if(_->b != NULL)
			free_list(_->b);
		if (_)
			free(_);
}
int error(t_data *_)
{
	ft_printf("Error\n");
	free_null(_);
	exit(1);
}