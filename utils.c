
#include "libft/libft.h"
#include "push_swap.h"

int	ft_atol( char *nptr, t_data *_)
{
	long	num;
	int	sign;
	int	n;

	n = 0;
	num = 0;
	sign = 1;
		
	if (*nptr == 45)
	{
		sign = -1;
		nptr++;
	}
	while (*nptr)
	{
		if ((*nptr > 47) && (*nptr < 58))
			n = *nptr - 48;
		else
		 	return (error(_), 1);
		num = num * 10 + n;
		nptr++;
	}
	if (num * sign < MIN || num > MAX)
		return (error(_), 1);
	return (num * sign);
}

int find_maxi(t_node *s, int size)
{
	int max;
	int i;
	int maxi;

	i = 1;
	max = MIN;
	while(i <= size)
	{
		if (s)
		{
			if (s->num > max)
			{
				max = s->num;
				maxi = s->index;
			}
			s = s->next;
		}
		i++;
	}
	return (maxi);
}

int is_sorted(t_node *s, t_data *_)
{
	int i;
	int lasti;
	i = 1;
	lasti = indx(s, _);
	while (i < lasti)
	{
		if (s->num > s->next->num)
			return(0);
		s = s->next;
		i++;
	}
	return (1);
}

int indx(t_node *s, t_data *_)
{
	int i; 
	t_node *point;

	i = 0;
	if (s == NULL)
		return(0);
	if (s->next == NULL || s->prev == NULL )
		{
			s->index = 1;
			s->_ = _;
			return (1);
		}
	point = s->prev;
	while(s != point)
	{
		i++;
		s->index = i;
		s->_ = _;		
		s = s->next;
	}
	s->_ = _;
	s->index = ++i;
	return i;
}

