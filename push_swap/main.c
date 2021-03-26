#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	ft_printf("a :\n");
	if (a->top)
		print_ilst(a->top);
	write(1, "\n", 1);
	ft_printf("b :\n");
	if (b->top)
		print_ilst(b->top);
	write(1, "\n", 1);
}

int	sort_trinome(char c, t_stack *a)
{
	if (a->size != 3)
		return (0);
	while (!ilst_is_sorted(A_ORDER, a->top))
	{
		if (a->top->val > a->top->next->val && a->top->val < a->end->val)
			swap(c, a->top);
		else if (a->top->val > a->top->next->val && a->top->val > a->end->val)
			rotate(c, a);
		else
			r_rotate(c, a);
	}
	return (1);
}

int64_t	get_median(t_ilst *lst, int32_t size)
{
	int64_t	*values;
	int64_t	median;
	int		i;

	if (!lst || size == 0)
		exit(0);
	values = malloc(sizeof(int64_t) * size);
	if (!values)
	{
		ft_printf("malloc failed\n");
		exit(0);
	}
	i = 0;
	while (i < size)
	{
		values[i] = lst->val;
		lst = lst->next;
		++i;
	}
	sort_array(values, size);
	median = values[size / 2];
	free(values);
	return (median);
}

int64_t	get_min(t_ilst *lst)
{
	int64_t	val;

	if (lst == NULL)
		return (0);
	val = INT64_MAX;
	while (lst)
	{
		if (lst->val < val)
			val = lst->val;
		lst = lst->next;
	}
	return (val);
}

int64_t	get_max(t_ilst *lst)
{
	int64_t	val;

	if (lst == NULL)
		return (0);
	val = INT64_MIN;
	while (lst)
	{
		if (lst->val > val)
			val = lst->val;
		lst = lst->next;
	}
	return (val);
}

int64_t	chunk_min(t_ilst *lst, int64_t chunk)
{
	int64_t	val;

	if (lst == NULL)
		return (0);
	val = INT64_MAX;
	while (lst)
	{
		if (lst->chunk == chunk && lst->val < val)
			val = lst->val;
		lst = lst->next;
	}
	return (val);
}

int64_t	chunk_max(t_ilst *lst, int64_t chunk)
{
	int64_t	val;

	if (lst == NULL)
		return (0);
	val = INT64_MIN;
	while (lst)
	{
		if (lst->chunk == chunk && lst->val > val)
			val = lst->val;
		lst = lst->next;
	}
	return (val);
}

int	chunk_size(t_ilst *lst, int64_t chunk)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 0;
	while (lst)
	{
		if (lst->chunk == chunk)
			++i;
		lst = lst->next;
	}
	return (i);
}

int64_t	biggest_chunk(t_ilst *a, t_ilst *b)
{
	int64_t	ret;

	ret = 0;
	while (a)
	{
		if (a->chunk > ret)
			ret = a->chunk;
		a = a->next;
	}
	while (b)
	{
		if (b->chunk > ret)
			ret = b->chunk;
		b = b->next;
	}
	return (ret);
}

void	mid_sort_a(int64_t *chunk, t_stack **a, t_stack **b)
{
	int64_t	median;
	int64_t	top_chunk;
	int	size;
	int	chk_size;

	top_chunk = (*a)->top->chunk;
	size = chunk_size((*a)->top, top_chunk);
	chk_size = size;
	median = get_median((*a)->top, size);
	++(*chunk);
	while (!ilst_is_sorted(A_ORDER, (*a)->top) || !(*b)->top ||
		chunk_max((*b)->top, (*b)->top->chunk) >
		chunk_min((*a)->top, top_chunk))
	{
		if ((*a)->size == 3 && get_min((*a)->top) > get_max((*b)->top))
			break ;
		chk_size = chunk_size((*a)->top, top_chunk);
		if (chunk_min((*a)->top, top_chunk) >= median)
		{
			if (chk_size && chk_size != (*a)->size)
				while ((*a)->end->chunk == top_chunk)
					r_rotate('a', *a);
			else
				top_chunk = (*a)->top->chunk;
			size = chunk_size((*a)->top, top_chunk);
			chk_size = size;
			median = get_median((*a)->top, size);
			++(*chunk);
		}
		if (chk_size == 1)
			push('b', b, a);
		else if (chk_size == 2)
		{
			if ((*a)->top->val >= chunk_min((*a)->top, top_chunk))
				swap('a', (*a)->top);
			if (!ilst_is_sorted(A_ORDER, (*a)->top))
				push('b', b, a);
		}
		else
		{
			if ((*a)->top->val < median)
			{
				push('b', b, a);
				(*b)->top->chunk = *chunk;
			}
			else
				rotate('a', *a);
		}
	}
}

void	mid_sort_b(int64_t *chunk, t_stack **a, t_stack **b)
{
	int64_t	median;
	int64_t	top_chunk;
	int	size;
	int	chk_size;

	top_chunk = (*b)->top->chunk;
	size = chunk_size((*b)->top, top_chunk);
	chk_size = size;
	median = get_median((*b)->top, size);
	++(*chunk);
	while (!ilst_is_sorted(D_ORDER, (*b)->top) || !(*a)->top)
	{
		chk_size = chunk_size((*b)->top, top_chunk);
		if (chunk_max((*b)->top, top_chunk) <= median)
		{
			if (chk_size && chk_size != (*b)->size)
				while ((*b)->end->chunk == top_chunk)
					r_rotate('b', *b);
			else
				top_chunk = (*b)->top->chunk;
			size = chunk_size((*b)->top, top_chunk);
			chk_size = size;
			median = get_median((*b)->top, size);
			++(*chunk);
		}
		if (chk_size == 1)
			push('a', a, b);
		else if (chk_size == 2)
		{
			if ((*b)->top->val == chunk_min((*b)->top, top_chunk))
				swap('b', (*b)->top);
			if (!ilst_is_sorted(D_ORDER, (*b)->top))
				push('a', a, b);
		}
		else
		{
			if ((*b)->top->val > median)
			{
				push('a', a, b);
				(*a)->top->chunk = *chunk;
			}
			else
				rotate('b', *b);
		}
	}
}

void	fill_a(t_stack **a, t_stack **b)
{
	if ((*b)->top && (*b)->top->val > (*a)->top->val)
	{
		while ((*b)->top && (*a)->end->val > (*b)->top->val)
			r_rotate('a', *a);
	}
	while ((*b)->top)
	{
		if ((*a)->end->val < (*a)->top->val && (*a)->end->val > (*b)->top->val)
			r_rotate('a', *a);
		else
			push('a', a, b);
	}
	while ((*a)->end->val < (*a)->top->val)
		r_rotate('a', *a);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int64_t	chunk;

	chunk = 0;
	if (a->size == 3)
	{
		sort_trinome('a', a);
		return ;
	}
	while (!ilst_is_sorted(A_ORDER, a->top) || b->top)
	{
		chunk = biggest_chunk(a->top, b->top);
		if (a->top)
			mid_sort_a(&chunk, &a, &b);
		if (a->size == 3)
			sort_trinome('a', a);
		if (!ilst_is_sorted(A_ORDER, a->top) ||
			!ilst_is_sorted(D_ORDER, b->top))
			mid_sort_b(&chunk, &a, &b);
		if (ilst_is_sorted(A_ORDER, a->top) &&
			ilst_is_sorted(D_ORDER, b->top))
			fill_a(&a, &b);
	}
}

int	main(int ac, char **av)
{
	t_stack a;
	t_stack b;

	ft_bzero(&a, sizeof(t_stack));
	ft_bzero(&b, sizeof(t_stack));
	while (--ac > 0)
	{
		if (!is_digit_str(av[ac]))
			return (print_ret("Error\n", -1));
		stack_add_front(&a, ft_atoi(av[ac]));
	}
	if (check_duplicates(a.top, a.size))
		return (print_ret("Error\n", -1));
	if (a.top == NULL)
		return (print_ret("Error\n", -1));
	push_swap(&a, &b);
	return (ilst_free_all(a.top) | ilst_free_all(b.top));
}
