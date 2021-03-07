#include "checker.h"

void	print_stack(t_stack *lst)
{
	t_stack	*tmp;
	tmp = lst;
	while (tmp)
	{
		ft_printf("%ld\n", tmp->val);
		tmp = tmp->next;
	}
}
