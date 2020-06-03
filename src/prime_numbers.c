/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 08:46:47 by ubuntu            #+#    #+#             */
/*   Updated: 2020/06/03 10:32:48 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prime_numbers.h"

static void		prime_numbers_1(size_t size)
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

static void		prime_numbers_2(size_t size)
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

int				main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_atoi(argv[2]) == 1)
			prime_numbers_1((size_t)ft_atoi(argv[1]));
		else
			prime_numbers_2((size_t)ft_atoi(argv[1]));
	}
	return (0);
}
