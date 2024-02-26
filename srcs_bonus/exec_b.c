/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:44:51 by bvalerii          #+#    #+#             */
/*   Updated: 2024/02/26 17:42:48 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ok(t_data *_)
{
	ft_printf("OK\n");
	free_null(_);
	exit(0);
}

void	ko(t_data *_)
{
	ft_printf("KO\n");
	free_null(_);
	exit(1);
}

void	check(t_data *_)
{
	if (is_sorted(_->a, _) && _->b_qty == 0)
		ok(_);
	else
		ko(_);
}

void	exec2(char *c, t_data *_)
{
	if (!ft_strncmp(c, "ss", 2))
		ss(_);
	else if (!ft_strncmp(c, "sa", 2))
		sa(_);
	else if (!ft_strncmp(c, "sb", 2))
		sb(_);
	else if (!ft_strncmp(c, "pa", 2))
		pa(_);
	else if (!ft_strncmp(c, "pb", 2))
		pb(_);
	else if (*c == '\0') 
		check(_);
	else
		error(_);
}

void	exec(char *c, t_data *_)
{
	if (!ft_strncmp(c, "rrr", 3))
		rrr(_);
	else if (!ft_strncmp(c, "rra", 3))
		rra(_);
	else if (!ft_strncmp(c, "rrb", 3))
		rrb(_);
	else if (!ft_strncmp(c, "rr", 2))
		rr(_);
	else if (!ft_strncmp(c, "ra", 2))
		ra(_);
	else if (!ft_strncmp(c, "rb", 2))
		rb(_);
	else
		(exec2(c, _));
}
