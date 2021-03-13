#include "push_swap.h"

uint64_t	ft_abs(int64_t val)
{
	uint64_t	abs_val;

	if (val > 0)
		return ((uint64_t)val);
	abs_val = val * -1;
	return (abs_val);
}

void	rotate_or_swap(int8_t flag, t_stack *a)
{
	if (flag == ASCENDING_ORDER)
	{
		if (ilst_count_sorted(flag, a->top->next) > 1 &&
			a->top->val > a->top->next->next->val)
		{
			ft_printf("ra\n");
			rotate(a->top);
		}
		else
		{
			ft_printf("sa\n");
			swap(a->top);
		}
	}
	else if (flag == DESCENDING_ORDER)
	{
		if (ilst_count_sorted(flag, a->top->next) > 1 &&
			a->top->val < a->top->next->next->val)
		{
			ft_printf("ra\n");
			rotate(a->top);
		}
		else
		{
			ft_printf("sa\n");
			swap(a->top);
		}
	}
}

int	min_bigger(int64_t comp, int64_t a, int64_t b, int64_t c)
{
	int64_t	smallest;

	smallest = INT64_MAX;
	if (a >= comp)
		smallest = a;
	if (b >= comp && b < smallest)
		smallest = b;
	if (c >= comp && c < smallest)
		smallest = c;
	return (smallest);
}

int	max_smaller(int64_t comp, int64_t a, int64_t b, int64_t c)
{
	int64_t	biggest;

	biggest = INT64_MIN;
	if (a <= comp)
		biggest = a;
	if (b <= comp && b > biggest)
		biggest = b;
	if (c <= comp && c > biggest)
		biggest = c;
	return (biggest);
}

int	fill_b_end(t_stack *a, t_stack *b)
{
	int64_t		biggest;
	t_ilst		*top;
	t_ilst		*next;
	t_ilst		*end;

	top = a->top;
	next = a->top->next;
	end = a->end;
	if (b->end == NULL)
		biggest = max_smaller(0, top->val, next->val, end->val);
	biggest = max_smaller(b->end->val, top->val, next->val, end->val);
	if (top->val == biggest)
	{
		ft_printf("pb\n");
		push(&b, &a);
//		ft_printf("rb\n");
//		rotate(b->top);
	}
	else if (next->val == biggest)
		rotate_or_swap(ASCENDING_ORDER, a);
	else if (end->val == biggest)
	{
		ft_printf("rra\n");
		r_rotate(a->top);
	}
	else
		return (0);
	return (1);
}

int	fill_b(t_stack *a, t_stack *b)
{
	int64_t		smallest;
	t_ilst		*top;
	t_ilst		*next;
	t_ilst		*end;

	top = a->top;
	next = a->top->next;
	end = a->end;
	if (b->top == NULL)
		smallest = min_bigger(0,
			top->val, next->val, end->val);
	else
		smallest = min_bigger(b->top->val,
			top->val, top->next->val, end->val);
	if (top->val == smallest)
	{
		ft_printf("pb\n");
		push(&b, &a);
	}
	else if (next->val == smallest)
		rotate_or_swap(ASCENDING_ORDER, a);
	else if (end->val == smallest)
	{
		ft_printf("rra\n");
		r_rotate(a->top);
	}
	else
		return (0);
	return (1);
}

int	fill_a(t_stack *a, t_stack *b)
{
	int64_t		top_a;
	int64_t		end_a;
	int64_t		top_b;

	if (b->top && b->top->val > a->top->val)
	{
		while (b->top->val < a->end->val)
		{
			ft_printf("rra\n");
			r_rotate(a->top);
		}
	}
	while (b->top)
	{
		top_a = a->top->val;
		end_a = a->end->val;
		top_b = b->top->val;
		if (end_a <= top_a && end_a >= top_b)
		{
			ft_printf("rra\n");
			r_rotate(a->top);
		}
		else
		{
			ft_printf("pa\n");
			push(&a, &b);
		}
	}
	return (1);
}

int	fill_b_min(t_stack *a, t_stack *b)
{
	int64_t		smallest;
	t_ilst		*top;
	t_ilst		*next;
	t_ilst		*end;

	top = a->top;
	next = a->top->next;
	end = a->end;
	if (b->top == NULL)
		smallest = min_bigger(0,
			top->val, next->val, end->val);
	else
		smallest = min_bigger(b->top->val,
			top->val, top->next->val, end->val);
	if (top->val == smallest && smallest <= b->end->val)
	{
		ft_printf("pb\n");
		push(&b, &a);
	}
	else if (next->val == smallest && smallest <= b->end->val)
		rotate_or_swap(ASCENDING_ORDER, a);
	else if (end->val == smallest && smallest <= b->end->val)
	{
		ft_printf("rra\n");
		r_rotate(a->top);
	}
	else
		return (0);
	return (1);
}

int	get_dist(t_stack *s, t_ilst *a, t_ilst *b, t_ilst *c)
{
	t_ilst	*lst;
	int	i;
	int	dist;

	lst = s->top;
	i = 1;
	dist = INT_MAX;
//	ft_printf("a = %ld\n", a->val);
//	ft_printf("b = %ld\n", b->val);
//	ft_printf("c = %ld\n", c->val);
	while (lst)
	{
		if (a && lst->val >= a->val && lst->next && a->val >= lst->next->val)
			if (i < dist || (i > s->size / 2 && s->size - i < dist))
			{
//				ft_printf("dist to a\n");
				dist = i;
			}
		if (b && lst->val >= b->val && lst->next && b->val >= lst->next->val)
			if (i < dist || (i > s->size / 2 && s->size - i < dist))
			{
//				ft_printf("dist to b\n");
				dist = i;
			}
		if (c && lst->val >= c->val && lst->next && c->val >= lst->next->val)
			if (i < dist || (i > s->size / 2 && s->size - i < dist))
			{
//				ft_printf("dist to c\n");
				dist = i;
			}
//		ft_printf("dist = %d\n", dist);
//		ft_printf("i = %d\n", i);
		lst = lst->next;
		++i;
	}
	if (dist == INT_MAX)
		dist = ilst_count_sorted(DESCENDING_ORDER, s->top);
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

int	sort_trinome(t_stack *a)
{
	if (a->size != 3)
		return (0);
	while (!ilst_is_sorted(ASCENDING_ORDER, a->top))
	{
		if (a->top->val > a->top->next->val && a->top->val < a->end->val)
		{
			ft_printf("sa\n");
			swap(a->top);
		}
		else if (a->top->val > a->top->next->val && a->top->val > a->end->val)
		{
			ft_printf("ra\n");
			rotate(a->top);
		}
		else //(a->top->val < a->top->next->val && a->top->val > a->end->val)
		{
			ft_printf("rra\n");
			r_rotate(a->top);
		}
	}
	return (1);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	ret;
	int	dist;

//	print_stacks(a, b);
	dist = 0;
	ret = 0;
	if (ilst_is_sorted(DESCENDING_ORDER, b->top))
	{
		ret = sort_trinome(a);
		if (ilst_is_sorted(ASCENDING_ORDER, a->top))
			while (b->top)
				ret = fill_a(a, b);
		if (!ret)
			ret = fill_b(a, b);
		if (!ret)
			ret = fill_b_end(a, b);
	}
	if (!ret)
	{
		ret = 1;
		while (ret && a->top && !ilst_is_sorted(ASCENDING_ORDER, a->top))
			ret = fill_b_min(a, b);
		dist = get_dist(b, a->top, a->top->next, a->end);
		//printf("dist = %d\n", dist);
		if (ilst_is_sorted(ASCENDING_ORDER, a->top))
		{
			while (!ilst_is_sorted(DESCENDING_ORDER, b->top))
			{
				if (dist < 0)
				{
					ft_printf("rrb\n");
					r_rotate(b->top);
				}
				else if (dist > 0)
				{
					ft_printf("rb\n");
					rotate(b->top);
				}
			}
		}
		else if (dist < 0)
		{
			ft_printf("rrb\n");
			r_rotate(b->top);
		}
		else if (dist > 0)
		{
			ft_printf("rb\n");
			rotate(b->top);
		}
//		ft_printf("dist = %d\n", dist);
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
	while (b.top || !ilst_is_sorted(ASCENDING_ORDER, a.top))
	{
		sort_stack(&a, &b);
//		usleep(90000);
	}
/*	ft_printf("a :\n");
	if (a.top)
		print_ilst(a.top);
	write(1, "\n", 1);
	ft_printf("b :\n");
	if (b.top)
		print_ilst(b.top);
	write(1, "\n", 1);
*/
	//check_ilsts(a.top, b.top);
	return (ilst_free_all(a.top) | ilst_free_all(b.top));
}
