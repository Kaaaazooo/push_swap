#include "libps.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = *dst;
	*dst = *src;
	*src = (*src)->next;
	(*dst)->next = tmp;
}
