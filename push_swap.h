#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_data t_data; 
typedef struct s_node
{
    int index;
    int num;
    int steps;
    int dist;/*ance*/
    int     p_found;
    int s;
    struct s_node *pair;
    struct s_node *next;
    struct s_node *prev;
    struct s_data *_;

} t_node;

typedef struct s_data
{
    t_node  *a;
    t_node  *b;
    t_node  *a_top;
    t_node  *b_top;
    t_node  temp;
    t_node  *b_temp;
    int     a_lasti;
    int     a_qty;
    int     b_qty;
    struct s_data *cp;
    int allsteps;
} t_data;

t_node *s(t_node *st);
void sa(t_data *_);
void sb(t_data *_);
void ss(t_data *_);
void pb(t_data *_);
void pa(t_data *_);
void ra(t_data *_);
void rb(t_data *_);
void rr(t_data *_);
void rra(t_data *_);
void rrb(t_data *_);
void rrr(t_data *_);


int f(t_node *s, t_data *_); /*irst*/
int m(t_node *s, int size, t_data *_); /*iddle (bellow midle)*/

void *go(t_data *_);

int indx(t_node *s, t_data *_);
void re_ind(t_data *_);
int is_sorted(t_node *s, t_data *_);
int find_maxi(t_node *s, int size);
t_node *find_max(t_node *s, int size);
void pair_max(t_node *s, t_node *big, int size);
void pair(t_node *s, t_node *big, int size);
int steps_s(t_node *s, int size, t_data *_);

t_node *cost_calc(t_node *s, t_node *big, int s_size, int big_size);
//t_node *copy_list(t_node *src, int size, t_data *_, int i);
void step(t_node *a, t_node *s);
void a_to_b(t_data *_, t_node *a);
void b_to_a(t_data *_, t_node *b);
void back_to_a(t_data *_);

void free_null(t_data *_);
void free_list(t_node *s);
int error(t_data *_);

void pr(t_node *s);
void rpr(t_node *s);
void prt(t_data *_);
void pr_single(t_node *s);
void pr_by_ind(t_node *s, int i);

t_node *rev_list(t_node *src, int size, t_data *_, int i);

#define MIN -2147483648
#define MAX 2147483647
#define MAXDIF  4294967294
#endif
