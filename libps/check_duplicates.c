#include "libps.h"

int	check_duplicates(t_ilst *lst, int size)
{
	int64_t	*values;
	int	i;

	values = malloc(sizeof(int64_t) * size);
	if (values == NULL)
		exit(0);
	i = 0;
	while (i < size)
	{
		values[i++] = lst->val;
		lst = lst->next;
	}
	sort_array(values, size);
	while (i)
	{
		if (values[i - 1] == values[i])
		{
			free(values);
			return (1);
		}
		--i;
	}
	free(values);
	return (0);
}
