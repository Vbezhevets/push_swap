/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:47:24 by bvalerii          #+#    #+#             */
/*   Updated: 2024/03/04 19:51:04 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data	t_data;
typedef struct s_node
{
	int					index;
	long				num;
	int					steps;
	long				dist;
	int					p_found;
	int					s;
	struct s_node		*pair;
	struct s_node		*next;
	struct s_node		*prev;
	struct s_data		*_;

}						t_node;

typedef struct s_data
{
	char				**str;
	t_node				*a;
	t_node				*b;
	t_node				*a_top;
	t_node				*b_top;
	t_node				temp;
	t_node				*b_temp;
	int					a_qty;
	int					b_qty;
	int					needsf;
}						t_data;

void					sa(t_data *_);
void					sb(t_data *_);
void					ss(t_data *_);
void					pb(t_data *_);
void					pa(t_data *_);
void					ra(t_data *_);
void					rb(t_data *_);
void					rr(t_data *_);
void					rra(t_data *_);
void					rrb(t_data *_);
void					rrr(t_data *_);

int						f(t_node *s, t_data *_);
int						m(t_node *s, int size, t_data *_);

void					nnule(t_node *s, t_data *_);
int						ft_atol(char *nptr, t_data *_, int l);
void					*go(t_data *_);
int						indx(t_node *s, t_data *_);
void					re_ind(t_data *_);
int						is_sorted(t_node *s, t_data *_);
int						find_maxi(t_node *s, int size);
t_node					*find_max(t_node *s, int size);
void					pair_max(t_node *s, t_node *bg, int size);
void					pair(t_node *s, t_node *bg, int size, int i);
int						steps_s(t_node *s, int size, t_data *_);
void					sort_3(t_data *_);

t_node					*cost_calc(t_node *s, t_node *bg, int s_size,
							int bg_size);
void					step(t_node *a, t_node *s);
void					a_to_b(t_data *_, t_node *a);
void					b_to_a(t_data *_, t_node *b);
void					back_to_a(t_data *_);

void					free_null(t_data *_);
void					free_list(t_node *s);
int						error(t_data *_);
int						ex(t_data *_);
void					free_str(t_data *_);

# define MIN -2147483648
# define MAX 2147483647
# define MAXDIST 4294967295

#endif
