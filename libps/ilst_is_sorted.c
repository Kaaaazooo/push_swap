#include "libps.h"

int	ilst_is_sorted(uint8_t flag, t_ilst *lst)
{
	int64_t	val;

	val = INT64_MIN;
	if (flag == DESCENDING_ORDER)
		val = INT64_MAX;
	while (lst)
	{
		if (flag == ASCENDING_ORDER)
		{
			if (lst->val > val)
				val = lst->val;
			else if (lst->val < val)
				return (0);
		}
		else if (flag == DESCENDING_ORDER)
		{
			if (lst->val < val)
				val = lst->val;
			else if (lst->val > val)
				return (0);
		}
		lst = lst->next;
	}
	return (1);
}
