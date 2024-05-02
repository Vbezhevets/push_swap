/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:35:36 by bvalerii          #+#    #+#             */
/*   Updated: 2024/03/04 19:49:31 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pair_max(t_node *s, t_node *bg, int size) // "s" is the Node is a node from A We are searching for minimum in B-stack (before a_to_b) "bg" here is stack B
{
	long	max;
	int		i;

	i = 1;
	max = MIN;
	while (i <= size)
	{
		if (bg->num > max) // if this number is more than we have before let's remember it:
		{
			max = bg->num;
			s->pair = bg; //finaly writing our best pair in this moment inside the "pair"-field in the A Node
		}
		bg = bg->next;
		i++;
	}
}

void	pair_min(t_node *s, t_node *bg, int size) // "s" is the Node is a node from B We are searching for minimum in A-stack (before b_to_a) "bg" here is stack A
{
	long	min;
	int		i;

	i = 1;
	min = MAX;
	while (i <= size)
	{
		if (bg->num < min) // if this number is less than we have before let's remember it:
		{
			min = bg->num;
			s->pair = bg; //finaly writing our best pair in this moment inside the "pair"-field in the B Node
		}
		bg = bg->next;
		i++;
	}
}

void	pair_min_diff(t_node *s, t_node *bg, int size) // writing adress of node with closest number inside pair-field of our Node
{
	int		i;
	long	min_diff;

	min_diff = MAXDIST;
	i = 0;
	while (++i <= size) // searching in distance recordings in stack of nodes
	{
		if (bg->p_found == 1) // it makes sense to look in this node
		{
			if (min_diff > bg->dist) // is the distance written in this node less than we allready found 
			{
				min_diff = bg->dist; // if new distance lower - we remeber it
				s->pair = bg; // writing our best pair in this moment inside the "pair"-field in the Node
			}
		}
		bg = bg->next; // go check next node
	}
}

void	pair(t_node *s, t_node *bg, int bg_size, int i) // I run this function 2 times : first before moving a_to_b and second before moving b_to_a that's why I have stupid  s->s == 1 and s->s == 2
{
	t_node	*bg_start;

	bg_start = bg; // start of stack in which we are searching for pair for our Node
	s->p_found = 0;
	while (++i <= bg_size)
	{
//s->s == 1 means we searching for pair to A in B stack ("bg" is B stack now, "s" is a Node from A-stack)
//s->s == 2 means we searching for pair to B in A stack ("bg" is A stack now, "s" is a Node from B-stack)
		if ((s->num > bg->num && s->s == 1) || (s->num < bg->num && s->s == 2)) 
 		{
			if (s->s == 1)// (before  a_to_b)
				bg->dist = s->num - bg->num; // writing in node from B stack found distance with number: A-stack->node->num minus B-stack->node->num
			else // before (b_to_a)
				bg->dist = bg->num - s->num; // writing in node from A stack found distance with number: B-stack->node->num minus A-stack->node->num
			bg->p_found = 1;
			s->p_found = 1;
		}
		else
			bg->p_found = -1; // wasn't find lower pair for A Node (when a_to_b) or higher pair for B Node (when b_to_a)
		bg = bg->next;
	}
	if (s->p_found != 1 && s->s == 1) // this case when smaller was not found and "s" is the Node from A-stack ( a_to_b)
		pair_max(s, bg_start, bg_size);  
	else if (s->p_found != 1 && s->s == 2) // this case when smaller was not found ("s" is the Node from B-stack ( b_to_a)
		pair_min(s, bg_start, bg_size); 
	else
		pair_min_diff(s, bg_start, bg_size); // search for a pair with the minimum distance (closest number) from those found
}

//Node ("s") - is our particular node for which we are looking for a pair
//bg - is Stack the stack we are iterating over