#include "push_swap.h"

uint64_t	ft_abs(int64_t val)
{
	uint64_t	abs_val;

	if (val > 0)
		return ((uint64_t)val);
	abs_val = val * -1;
	return (abs_val);
}

int	get_dist(t_stack *s, t_ilst *a, t_ilst *b, t_ilst *c)
{
	t_ilst	*lst;
	int	i;
	int	dist;

	lst = s->top;
	i = 1;
	dist = INT_MAX;
	while (lst)
	{
		if (a && lst->val >= a->val && lst->next && a->val >= lst->next->val)
			if (i < dist || (i > s->size / 2 && s->size - i < dist))
				dist = i;
		if (b && lst->val >= b->val && lst->next && b->val >= lst->next->val)
			if (i < dist || (i > s->size / 2 && s->size - i < dist))
				dist = i;
		if (c && lst->val >= c->val && lst->next && c->val >= lst->next->val)
			if (i < dist || (i > s->size / 2 && s->size - i < dist))
				dist = i;
		lst = lst->next;
		++i;
	}
	if (dist == INT_MAX)
		dist = ilst_count_sorted(D_ORDER, s->top);
	if (dist > s->size / 2)
		dist -= s->size;
	return (dist);
}

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
			rotate(c, a->top);
		else
			r_rotate(c, a->top);
	}
	return (1);
}

void	sort_array(int64_t *tab, int32_t size)
{
	int64_t	c;
	int64_t	d;
	int64_t	t;

	c = 0;
	while (c < (int64_t)(size - 1))
	{
		d = 0;
		while (d < ((int64_t)size - 1) - c)
		{
			if (tab[d] > tab[d + 1])
			{
				t = tab[d];
				tab[d] = tab[d + 1];
				tab[d + 1] = t;
			}
			++d;
		}
		++c;
	}
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
		exit(0);
	i = 0;
	while (lst)
	{
		values[i++] = lst->val;
		lst = lst->next;
	}
	sort_array(values, size);
	median = values[size / 2];
	return (median);
}

//	j = 0;
//	while (j < size)
//	{
//		ft_printf("values[%d] = %ld\n", j, values[j]);
//		++j;
//	}
//	ft_printf("values sorted\n");
//	ft_printf("size = %ld\n", size);
//	ft_printf("size / 2 = %ld\n", size / 2);

int		chunk_size(t_ilst *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 1;
	while (lst->next && lst->next->chunk == lst->chunk)
	{
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
	int		size;

	size = chunk_size((*a)->top);
	ft_printf("size= %d\n", size);
	median = get_median((*a)->top, size);
	++(*chunk);
	ft_printf("MID SORT A\n");
	while (!ilst_is_sorted(A_ORDER, (*a)->top))
	{
		print_stacks(*a, *b);
		if (chunk_size((*a)->top) <= size / 2)
		{
			size = chunk_size((*a)->top);
			median = get_median((*a)->top, size);
			++(*chunk);
		}
		ft_printf("median = %ld\n", median);
		if ((*a)->top->val < median)
		{
			push('b', b, a);
			(*b)->top->chunk = *chunk;
		}
		else
			rotate('a', (*a)->top);
		usleep(900000);
	}
}

void	mid_sort_b(int64_t *chunk, t_stack **a, t_stack **b)
{
	int64_t	median;
	int		size;

	size = chunk_size((*b)->top);
	ft_printf("size= %d\n", size);
	median = get_median((*b)->top, size);
	++(*chunk);
	ft_printf("MID SORT B\n");
	while (!ilst_is_sorted(D_ORDER, (*b)->top))
	{
		print_stacks(*a, *b);
		if (chunk_size((*b)->top) <= size / 2)
		{
			size = chunk_size((*b)->top);
			median = get_median((*b)->top, size);
			++(*chunk);
		}
		ft_printf("median = %ld\n", median);
		if ((*b)->top->val > median)
		{
			push('a', a, b);
			(*a)->top->chunk = *chunk;
		}
		else
			rotate('b', (*b)->top);
		usleep(900000);
	}
}

void	fill_a(t_stack **a, t_stack **b)
{
	while ((*b)->top && (*a)->end->val < (*b)->top->val)
	{
		print_stacks(*a, *b);
		r_rotate('a', (*a)->top);
		usleep(900000);
	}
	while ((*b)->top)
	{
		if ((*a)->end->val < (*a)->top->val && (*a)->end->val > (*b)->top->val)
			r_rotate('a', (*a)->top);
		else
			push('a', a, b);
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	int64_t	chunk;

	chunk = 0;
	while (!ilst_is_sorted(A_ORDER, a->top) || b->top)
	{
		print_stacks(a, b);
		chunk = biggest_chunk(a->top, b->top);
		mid_sort_a(&chunk, &a, &b);
		mid_sort_b(&chunk, &a, &b);
		if (ilst_is_sorted(A_ORDER, a->top) && ilst_is_sorted(D_ORDER, b->top))
			fill_a(&a, &b);
		usleep(900000);
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
	if (a.top == NULL)
		return (print_ret("Error\n", -1));
	push_swap(&a, &b);
	return (ilst_free_all(a.top) | ilst_free_all(b.top));
}
