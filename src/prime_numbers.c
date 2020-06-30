/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 08:46:47 by ubuntu            #+#    #+#             */
/*   Updated: 2020/06/27 20:30:32 by ubuntu           ###   ########.fr       */
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
	size_t		i;
	size_t		c;

	ft_printf("2\n");
	i = 2;
	while (size > i)
	{
		i++;
		c = 1;
		while (++c <= i - 1)
		{
			if (!(i % c))
				break ;
		}
		// if (c == i)
		// 	ft_printf("%d\n", i);
	}
	return ;
}

static void			prime_numbers_2(size_t size, t_list **numbers)
{
	size_t		i;
	size_t		c;

	i = 2;
	ft_lstadd(numbers, ft_lstnew(&i, sizeof(i)));
	while (size > i)
	{
		i++;
		c = 1;
		while (++c <= i - 1)
		{
			if (!(i % c))
				break ;
		}
		if (c == i)
			ft_lstadd(numbers, ft_lstnew(&i, sizeof(i)));
	}
	return ;
}

static void			prime_numbers_3(size_t size, t_list **numbers)
{
	int			*number_array;
	size_t		current_prime_number;
	size_t		current_number;

	number_array = (int *)ft_memalloc(sizeof(*number_array) * (size + 1));
	current_prime_number = 2;
	number_array[0] = 1;
	number_array[1] = 1;
	while (current_prime_number <= size)
	{
		current_number = current_prime_number * 2;
		while (current_number <= size)
		{
			number_array[current_number] = 1;
			current_number += current_prime_number;
		}
		current_prime_number++;
		while (number_array[current_prime_number])
			current_prime_number++;
	}
	current_number = -1;
	while (++current_number <= size)
	{
		if (!number_array[current_number])
			ft_lstadd(numbers, ft_lstnew(&current_number, sizeof(current_number)));
	}
	free(number_array);
	return ;
}

static void			is_prime_number_1(size_t nbr)
{
	size_t		div_nbr;
	int			is_prime;

	if (nbr == 1)
		ft_printf("Not prime\n");
	else if (nbr == 2)
		ft_printf("Prime\n");
	else if (nbr % 2)
	{
		is_prime = 1;
		div_nbr = nbr - 2;
		while (div_nbr > 2)
		{
			if (!(nbr % div_nbr))
			{
				is_prime = 0;
				break ;
			}
			div_nbr -= 2;
		}
		if (is_prime)
			ft_printf("Prime\n");
		else
			ft_printf("Not prime\n");
	}
	else
		ft_printf("Not prime\n");
	return ;
}

static void			is_prime_number_2(size_t nbr)
{
	size_t		div_nbr;
	int			is_prime;

	if (nbr == 1)
		ft_printf("Not prime\n");
	else if (nbr == 2)
		ft_printf("Prime\n");
	else if (nbr % 2)
	{
		is_prime = 1;
		div_nbr = nbr / 2;
		if (!(div_nbr))
			div_nbr -= 1;
		while (div_nbr > 2)
		{
			if (!(nbr % div_nbr))
			{
				is_prime = 0;
				break ;
			}
			div_nbr -= 2;
		}
		if (is_prime)
			ft_printf("Prime\n");
		else
			ft_printf("Not prime\n");
	}
	else
		ft_printf("Not prime\n");
	return ;
}

int					main(int argc, char **argv)
{
	t_list		**numbers;
	t_list		*elem;

	if (argc == 3 && ft_atoi(argv[1]) > 1)
	{
		if (ft_atoi(argv[2]) == 1)
			prime_numbers_1((size_t)ft_atoi(argv[1]));
		else
		{
			numbers = (t_list **)ft_memalloc(sizeof(*numbers));
			if (ft_atoi(argv[2]) == 2)
				prime_numbers_2((size_t)ft_atoi(argv[1]), numbers);
			else if (ft_atoi(argv[2]) == 3)
				prime_numbers_3((size_t)ft_atoi(argv[1]), numbers);
			else if (ft_atoi(argv[2]) == 11)
				is_prime_number_1((size_t)atoi(argv[1]));
			else if (ft_atoi(argv[2]) == 12)
				is_prime_number_2((size_t)atoi(argv[1]));
			swap_order(numbers);
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
