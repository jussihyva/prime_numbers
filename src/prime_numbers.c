/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 08:46:47 by ubuntu            #+#    #+#             */
/*   Updated: 2020/06/03 11:27:26 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prime_numbers.h"

static void			swap_order(t_list **numbers)
{
	t_list	*new_order;
	t_list	*elem;
	t_list	*tmp_elem;

	new_order = NULL;
	elem = *numbers;
	while (elem)
	{
		tmp_elem = elem->next;
		ft_lstadd(&new_order, elem);
		elem = tmp_elem;
	}
	*numbers = new_order;
	return ;
}

static void			prime_numbers_1(size_t size)
{
	int			i;
	int			count;
	int			c;

	i = 3;
	if (size >= 1)
		ft_printf("2\n");
	count = 2;
	while (count <= (int)size)
	{
		c = 1;
		while (++c <= i - 1)
		{
			if (!(i % c))
				break ;
		}
		if (c == i)
		{
			ft_printf("%d\n", i);
			count++;
		}
		i++;
	}
	return ;
}

static void			prime_numbers_2(size_t size, t_list **numbers)
{
	size_t		i;
	size_t		count;
	size_t		c;

	i = 2;
	ft_lstadd(numbers, ft_lstnew(&i, sizeof(i)));
	count = 2;
	while (count <= size)
	{
		i++;
		c = 1;
		while (++c <= i - 1)
		{
			if (!(i % c))
				break ;
		}
		if (c == i)
		{
			ft_lstadd(numbers, ft_lstnew(&i, sizeof(i)));
			count++;
		}
	}
	swap_order(numbers);
	return ;
}

int					main(int argc, char **argv)
{
	t_list		**numbers;
	t_list		*elem;

	if (argc == 3 && ft_atoi(argv[1]))
	{
		if (ft_atoi(argv[2]) == 1)
			prime_numbers_1((size_t)ft_atoi(argv[1]));
		else
		{
			numbers = (t_list **)ft_memalloc(sizeof(*numbers));
			prime_numbers_2((size_t)ft_atoi(argv[1]), numbers);
			elem = *numbers;
			while (elem)
			{
				ft_printf("%d\n", *((int *)elem->content));
				elem = elem->next;
			}
			ft_lstdel(numbers, del_elem);
			free(numbers);
		}
	}
	return (0);
}
