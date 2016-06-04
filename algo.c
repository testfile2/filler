/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:33:25 by kcowle            #+#    #+#             */
/*   Updated: 2016/06/04 16:04:45 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

int		check(t_raw_map *b, t_env env)
{
	return 1;
}

void	place_coords(int x, int y)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void	algo(t_env env, t_raw_map **b)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (k < env.map.map_y)
	{
		while (i < env.map.map_x)
		{
			if (check(b[0], env) == 1)
			{
				place_coords(i, k);
				break;
			}
			++i;
		}
		i = 0;
		++k;
	}
}
