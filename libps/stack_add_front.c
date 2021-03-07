#include "libps.h"

void	stack_add_front(t_stack **dst, int64_t val)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return ;
	new->val = val;
	new->next = *dst;
	*dst = new;
}
