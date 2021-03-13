#include "libps.h"

int	ilst_count_sorted(uint8_t flag, t_ilst *lst)
{
	int64_t	val;
	int64_t	i;

	val = INT64_MIN;
	if (flag == DESCENDING_ORDER)
		val = INT64_MAX;
	i = 0;
	while (lst)
	{
		if (flag == ASCENDING_ORDER)
		{
			if (lst->val < val)
				return (i);
			val = lst->val;
		}
		else if (flag == DESCENDING_ORDER)
		{
			if (lst->val > val)
				return (i);
			val = lst->val;
		}
		lst = lst->next;
		i++;
	}
	return (i);
}
