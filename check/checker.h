#ifndef CHECKER_H
#define CHECKER_H
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

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
    char    **str;
    t_node  *a;
    t_node  *b;
    t_node  *a_top;
    t_node  *b_top;
    t_node  temp;
    t_node  *b_temp;
    int     a_qty;
    int     b_qty;
    int needsf;
    char    *cmd;
} t_data;



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

int	ft_atol( char *nptr, t_data *_);
int indx(t_node *s, t_data *_);
void re_ind(t_data *_);
int is_sorted(t_node *s, t_data *_);
void exec(char *c, t_data *_);


void free_null(t_data *_);
void free_list(t_node *s);
int error(t_data *_);
int ex(t_data *_);
void free_str(t_data *_);
void ko(t_data *_);
void ok(t_data *_);

void pr(t_node *s);
void rpr(t_node *s);
void prt(t_data *_);
void pr_single(t_node *s);
void pr_by_ind(t_node *s, int i);

#define MIN -2147483648
#define MAX 2147483647
#endif
