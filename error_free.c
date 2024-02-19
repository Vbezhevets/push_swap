#include "libft/libft.h"
#include "push_swap.h"
#include <assert.h>

void free_list(t_node *s)
{
	t_node *f;

	f = s;
	if (s->next)
	{
		while(s->next && s->next != f)
		{
			s = s->next;
			free(s->prev);
		}
		free (s);
		s = NULL;
	}
	else
	{
		free (f);
		f = NULL;
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
	if (_->needsf == 1)
	{
		free_str(_);
		_->needsf = 0;
	}
	free_null(_);
	exit(1);
}
void free_str(t_data *_)
{
	char **start;
	char **str;
	int i;

	str = _->str;
	i = 0;
	start = str;
	
	if (str)
	{
		while (str[i] != NULL)
			free(str[i++]);
		free(start);
		start = NULL;
	}
	_->needsf = 0;
}
int ex(t_data *_)
{
	free_null(_);
	exit(0);
}

