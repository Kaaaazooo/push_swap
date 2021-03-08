#include "libps.h"

void	stack_add_front(t_stack *dst, int64_t val)
{
	t_ilst	*new;

	new = (t_ilst *)malloc(sizeof(t_ilst));
	if (new == NULL)
		return ;
	if (dst->top == NULL)
		dst->end = new;
	new->val = val;
	new->next = dst->top;
	dst->top = new;
}
