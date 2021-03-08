#include "libps.h"

int	ilst_free_all(t_ilst *lst)
{
	t_ilst	*next;
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
