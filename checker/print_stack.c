#include "checker.h"

void	print_ilst(t_ilst *lst)
{
	t_ilst	*tmp;
	tmp = lst;
	while (tmp)
	{
		ft_printf("%ld\n", tmp->val);
		tmp = tmp->next;
	}
}
