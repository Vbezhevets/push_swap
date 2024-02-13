
#include "libft/libft.h"
#include "push_swap.h"

void pr_single(t_node *s)
{

	if (s ==NULL)
	{
		ft_printf("not exist\n");
		return;
	}
	if  (s->num)
		ft_printf("num: %d | ", s->num);
	if (s->prev)
		ft_printf("prev: %d | ",s->prev->num);
	if (s->next)
		ft_printf("next: %d | ",s->next->num);
	if (s->index)
		ft_printf("Ind: %d | ", s->index);
	if (s->steps)
		ft_printf("steps %d | ", s->steps );
	if (s->pair)
		ft_printf("pair: %d \n", s->pair->num);
	else
		ft_printf("no pair\n");
	// ft_printf("\n");
}

void pr(t_node *s)
{
	t_node *point;

	point = s;
	if (s != NULL)
	{	
		while(s->next != point && s->next != NULL)
		{
			pr_single(s);
			s = s->next;
		}
		if (s != NULL)
			pr_single(s);
	}
}
void rpr(t_node *s)
{
	t_node *point;

	point = s;
	if (s != NULL)
	{	
		while(s->prev != point && s->prev != NULL)
		{
			s = s->prev;
			pr_single(s);
		}
		pr_single(s->prev);
	}
}

void pr_by_ind(t_node *s, int i)
{
	t_node *point;

	point = s;
	if (s != NULL)
	{	
		while(s->index != i)
			s = s->next;
		if (s->index == i)
				pr_single(s);
	}
}
void prt(t_data *_)
{
	ft_printf("====a====\n");
	pr(_->a);
	ft_printf("====b====\n");
	pr(_->b);
}

t_node *cpy_loop(t_node * dst, t_node *src, int size, int i)
{
	t_node *prev;

	prev = dst;
	dst->num = src->num;
	dst->index = src->index;
	dst->steps = 0;
	dst->pair = src->pair;
	if (i == size)
		return(dst);
	dst->next = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!dst->next)
		return(NULL);
	dst = dst->next;
	dst->prev = prev;
	i++;
	return(dst);
}


t_node *copy_list(t_node *src, int size, t_data *_, int i)
{
  	t_node *start;
    t_node *dst;
    
	start = (t_node *)ft_calloc(1, sizeof(t_node));
        if (!start)
        return (error(_), NULL);
    dst = start;
	while (++i <= size)
	{
		dst = cpy_loop(dst, src, size, i);
			if (dst == NULL)
  				return (free_list(start), error(_), NULL);
		src = src->next;
	}
	if (i > 1)
	{
		dst->next = start;
		start->prev = dst;
	}
	else 
	{
		start->next = NULL;
		start->prev = NULL;
	}
	return (start);
}

t_node *rev_loop(t_node * dst, t_node *src, int size, int i)
{
	t_node *prev;

	prev = dst;
	dst->num = src->num;

	if (i == size)
		return(dst);
	dst->next = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!dst->next)
		return(NULL);
	dst = dst->next;
	dst->prev = prev;
	i++;
	return(dst);
}

t_node *rev_list(t_node *src, int size, t_data *_, int i)
{
  	t_node *start;
    t_node *dst;
    
	start = (t_node *)ft_calloc(1, sizeof(t_node));
        if (!start)
        return (error(_), NULL);
    dst = start;
	while (++i <= size)
	{
		dst = cpy_loop(dst, src, size, i);
			if (dst == NULL)
  				return (free_list(start), error(_), NULL);
		src = src->prev;
	}
	if (i > 1)
	{
		dst->next = start;
		start->prev = dst;
	}
	else 
	{
		start->next = NULL;
		start->prev = NULL;
	}
    return (start);
}