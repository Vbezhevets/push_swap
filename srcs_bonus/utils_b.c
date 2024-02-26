/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:46:14 by bvalerii          #+#    #+#             */
/*   Updated: 2024/02/20 17:46:15 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (s->next == NULL || s->prev == NULL)
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

int	ft_atol(char *nptr, t_data *_)
{
	char	*str;
	long	num;
	int		l;
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
	num = ato(nptr, _);
	str = ft_itoa(num * sign);
	if (num * sign < MIN || num * sign > MAX || l != ft_strlen(str))
		return (free(str), error(_), 1);
	return (free(str), num * sign);
}
