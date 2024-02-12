
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
	if (s->index)
		ft_printf("Ind: %d | ", s->index);
	if (s->steps)
		ft_printf("steps %d | ", s->steps );
	if (s->pair)
		ft_printf("pair: %d \n", s->pair->num);
	else
		ft_printf("no pair\n");
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