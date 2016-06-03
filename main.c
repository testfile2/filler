/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 08:52:11 by kcowle            #+#    #+#             */
/*   Updated: 2016/06/02 16:43:06 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>
#include "fdf.h"

int		get_player_number(char **line)
{
    static int number = 0;

    if (line[0][0] == '$' && line[0][1] == '$' && line[0][2] == '$' && line[0][ft_strlen(*line) - 2] == 'i'\
            && line[0][ft_strlen(*line) - 3] == 'n' && line[0][ft_strlen(*line) - 4] == 'i' &&\
            line[0][ft_strlen(*line) - 5] == 'V')
    {
        if (line[0][10] == '1')
            number = 1;
        else if (line[0][10] == '2')
            number = 2;
    }
    else
    {
        get_next_line(0, line);
        get_player_number(line);
    }
    return (number);
}

void	insert_line(char *line, t_raw_map **b)
{
    int i;

    i = 4;
    while (line[i])
    {
        b[0] = (t_raw_map *)malloc(sizeof(t_raw_map));
        b[0]->point = line[i];
        i++;
        b[0]->next = b[1];
        b[1] = b[0];
    }
}
     
void	printf_list(t_raw_map **b, int i)
{
    int n = 1;

    while (b[0])
    {
        n = 1;
        while (b[0] &&n <= i)
        {
            ft_putchar(b[0]->point);
            b[0] = b[0]->next;
            ++n;
        }
        ft_putchar('\n');
    }
}

void    insert_piece(char *line, t_piece piece)
{
    int i;
    int j;

    i = 0;
    j = 0;
    piece.piece = (char **)malloc(sizeof(char) * piece.piece_y);
    while (j < piece.piece_y)
    {
        piece.piece[j] = (char *)malloc(sizeof(char) * piece.piece_x);
        ++j;
    }
    j = 0;
    while (j < piece.piece_y)
    {
        i = 0;
        while (i <= piece.piece_x && line[i] != '\n' && line[i] != '\0')
        {
            piece.piece[j][i] = line[i];
            ft_putchar(piece.piece[j][i]);
            ++i;
        }
        ++j;
        if (line[i] == '\n')
            ++i;
    }
}

void    reverse_map(t_raw_map **b)
{
    b[0] = 0;
    while (b[1])
    {
        b[2] = b[1]->next;
        b[1]->next = b[0];
        b[0] = b[1];
        b[1] = b[2];
    }
}

int 	main()
{
    int i;
    char **line2;
    t_raw_map	*b[3];
    t_map a;
    t_piece piece;

    i = 4;
    b[1] = NULL;
    int player_number;
    char *line;
    char *tline;
    get_next_line(0, &line);
    player_number = get_player_number(&line);

    while (line[0] != 'P' || line[1] != 'l' || line[2] != 'a' || line[3] != 't' || line[4] != 'e')
    {
        get_next_line(0, &line);
    }

    line2 = ft_strsplit(line, ' ');
    a.map_y = ft_atoi(line2[1]);
    a.map_x = ft_atoi(line2[2]);

    while (ft_isdigit(line[0]) && ft_isdigit(line[1]) && ft_isdigit(line[2]) )
    {
        get_next_line(0, &line);
    }

    while (player_number == 1 || player_number == 2)
    {
        i = 1;
        if (ft_isdigit(line[0]) && ft_isdigit(line[1]) && ft_isdigit(line[2]))
        {
            insert_line(line, b);
            while (get_next_line(0, &line) > 0 && i < a.map_y)
            {
                insert_line(line, b);
                i++;
            }
            line2 = ft_strsplit(line, ' ');
            piece.piece_y = ft_atoi(line2[1]);
            piece.piece_x = ft_atoi(line2[2]);
            piece.piece_a = piece.piece_y * piece.piece_x;

            i = 1;
            tline = (char *)malloc(sizeof(char *) * piece.piece_a);
            while (i <= piece.piece_y)
            {
                get_next_line(0, &line);
                ft_strcat(tline, line);
                ++i;
            }
            insert_piece(tline, piece);
            reverse_map(b);
            printf_list(b, a.map_x);
            ft_putstr("\n\n");
            ft_putchar(piece.piece[0][0]);
            break;
        }
        else
            get_next_line(0, &line);
    }
    return 0;
}
