#include "libps.h"

int	stack_free_all(t_stack *lst)
{
	t_stack	*next;
	while (lst)
	{
		next = lst->next;
		lst->val = 0;
		lst->next = NULL;
		free(lst);
		lst = next;
	}
	return (0);
}
