#include "libps.h"

void	push(t_stack **dst, t_stack **src)
{
	t_ilst	*tmp;

	if ((*src)->top == NULL)
		return ;
	tmp = (*dst)->top;
	(*dst)->top = (*src)->top;
	(*src)->top = (*src)->top->next;
	if ((*src)->top == NULL)
		(*src)->end = NULL;
	(*dst)->top->next = tmp;
}
