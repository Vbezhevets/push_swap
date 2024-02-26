/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:49:07 by bvalerii          #+#    #+#             */
/*   Updated: 2024/02/26 17:06:01 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ato(char *nptr, t_data *_)
{
	long	num;
	long	n;

	n = 0;
	num = 0;
	while (*nptr)
	{
		if ((*nptr > 47) && (*nptr < 58))
			n = *nptr - 48;
		else
			return (error(_), 1);
		num = num * 10 + n;
		nptr++;
	}
	return (num);
}

int	ft_atol(char *nptr, t_data *_, int l)
{
	char	*str;
	long	num;
	long	sign;

	sign = 1;
	l = ft_strlen(nptr);
	if (l == 0 || (l == 1 && *nptr == '-'))
		return (error(_), 1);
	if (*nptr == 45)
	{
		sign = -1;
		nptr++;
	}
	while (*nptr == '0')
	{
		nptr++;
		l--;
	}
	num = ato(nptr, _);
	str = ft_itoa(num * sign);
	if (num * sign < MIN || num * sign > MAX || l != ft_strlen(str))
		return (free(str), error(_), 1);
	return (free(str), num * sign);
}

int	find_maxi(t_node *s, int size)
{
	long	max;
	int	i;
	int	maxi;

	i = 1;
	max = MIN;
	while (i <= size)
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

int	is_sorted(t_node *s, t_data *_)
{
	int	i;
	int	lasti;

	i = 1;
	lasti = indx(s, _);
	while (i < lasti)
	{
		if (s->num > s->next->num)
			return (0);
		s = s->next;
		i++;
	}
	return (1);
}

int	indx(t_node *s, t_data *_)
{
	int		i;
	t_node	*point;

	i = 0;
	if (s == NULL)
		return (0);
	if (s->next == NULL || s->prev == NULL )
	{
		s->index = 1;
		s->_ = _;
		return (1);
	}
	point = s->prev;
	while (s != point)
	{
		i++;
		s->index = i;
		s->_ = _;
		s = s->next;
	}
	s->_ = _;
	s->index = ++i;
	return (i);
}
