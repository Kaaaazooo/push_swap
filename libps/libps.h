#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_stack
{
	int64_t		val;
	struct s_stack	*next;
}		t_stack;

void	push(t_stack **dst, t_stack **src);
void	r_rotate_s(t_stack *a, t_stack *b);
void	r_rotate(t_stack *lst);
void	rotate_s(t_stack *a, t_stack *b);
void	rotate(t_stack *lst);
void	swap(t_stack *lst);
void	swap_s(t_stack *a, t_stack *b);

void	stack_add_front(t_stack **dst, int64_t val);
int	stack_free_all(t_stack *lst);

#endif
