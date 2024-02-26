/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:45:01 by bvalerii          #+#    #+#             */
/*   Updated: 2024/02/24 15:17:08 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	dupl(t_node *s, int size)
{
	int	i;
	int	n;

	n = s->num;
	i = 0;
	s->s = 1;
	if (s->prev)
	{
		while (++i <= size)
		{
			if (n == s->prev->num)
				return (1);
			s = s->prev;
		}
	}
	return (0);
}

int	fill_a(t_data *_, int i, t_node *s, t_node *prev)
{
	while (_->str[++i])
	{
		_->a_qty = i;
		s->prev = prev;
		prev = s;
		s->next = _->a;
		s->num = (int)ft_atol(_->str[i], _);
		if (dupl(s, i))
			return (-1);
		if (_->str[i + 1])
		{
			s->next = (t_node *)ft_calloc(1, sizeof(t_node));
			if (!s->next)
				return (-1);
			s = s->next;
		}
		else
		{
			s->next = _->a;
			_->a->prev = s;
		}
	}
	_->a_qty = i;
	return (i);
}

t_data	*init_null(t_data *_)
{
	_ = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!_)
	{
		ft_printf("Error\n");
		exit(1);
	}
	_->a = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!_->a)
	{
		ft_printf("Error\n");
		free(_);
		exit(1);
	}
	_->a->next = NULL;
	_->a->pair = NULL;
	_->a->prev = NULL;
	_->b = NULL;
	_->b_qty = 0;
	_->str = NULL;
	_->needsf = 0;
	_->cmd = NULL;
	return (_);
}

void	read_cmd(t_data *_)
{
	int	br;

	while (1)
	{
		if (is_sorted(_->a, _) && _->b_qty == 0)
			ok(_);
		_->cmd = (char *)malloc(4);
		if (!_->cmd)
			error(_);
		br = read(0, _->cmd, 4);
		if (br == 1 && !ft_strncmp(_->cmd, "\n", 1))
		{
			free(_->cmd);
			_->cmd = NULL;
			break ;
		}
		_->cmd[br] = '\0';
		exec(_->cmd, _);
		free(_->cmd);
		_->cmd = NULL;
	}
	check(_);
}

int	main(int argc, char **argv)
{
	t_data	*_;
	int		l;

	_ = NULL;
	if (argc == 1)
		exit(1);
	_ = init_null(_);
	if (argc == 2)
	{
		_->needsf = 1;
		_->str = ft_split(argv[1], ' ');
		if (!_->str)
			return (error(_), 1);
	}
	else if (argc > 2)
		_->str = (argv + 1);
	l = fill_a(_, -1, _->a, NULL);
	if (argc == 2)
		free_str(_);
	if (l < 1)
		error(_);
	if (l > 1)
		read_cmd(_);
	else
		ex(_);
}
