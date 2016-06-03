/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 12:44:09 by kcowle            #+#    #+#             */
/*   Updated: 2016/06/01 17:46:13 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_map{
	int map_y;
	int map_x;
	int Area;
}				t_map;

typedef struct s_piece{
    char **piece;
    int piece_y;
    int piece_x;
    int piece_a;
}               t_piece;
typedef struct s_raw_map{
	char point;
	struct s_raw_map *next;
}				t_raw_map;
