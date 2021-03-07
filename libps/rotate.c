#include "libps.h"

void	rotate(t_stack *lst)
{
	t_stack	*tmp;
	int64_t	val;

	if (lst == NULL || lst->next == NULL)
		return ;
	tmp = lst;
	val = lst->val;
	while (tmp->next)
	{
		tmp->val = tmp->next->val;
		tmp = tmp->next;
	}
	tmp->val = val;
}

void	rotate_s(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	r_rotate(t_stack *lst)
{
	t_stack	*tmp;
	int64_t	val;
	int64_t	tmp_val;

	if (lst == NULL || lst->next == NULL)
		return ;
	tmp = lst;
	tmp_val = tmp->val;
	while (tmp->next)
	{
		val = tmp_val;
		tmp = tmp->next;
		tmp_val = tmp->val;
		tmp->val = val;
	}
	lst->val = tmp_val;
}

void	r_rotate_s(t_stack *a, t_stack *b)
{
	r_rotate(a);
	r_rotate(b);
}