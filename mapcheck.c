/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:45:04 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/17 14:45:05 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

int	mapcheck(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (*map == 0 || i-- < 5)
		return (0);
	if (map[i] == 'b' && map[i - 1] == 'u' && map[i - 2] == 'c' && map[i - 3] \
			== '.')
		return (1);
	else
		return (0);
}

void	check_img(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd != -1)
		close(fd);
	else if (fd == -1)
	{
		printf("Error\nPicture is not\n");
		close(fd);
		exit(1);
	}
}

static void	check_charif(t_gmap *g_map)
{
	if (g_map->char_cnt == 0)
	{
		printf("Error\nNo character start direction\n");
		exit(1);
	}
	else if (g_map->char_cnt >= 2)
	{
		printf("Error\nCharacter start direction too much\n");
		exit(1);
	}
}

void	map_character_check(t_gmap *g_map)
{
	while (g_map->map[g_map->c_arg])
	{
		g_map->c_idx = 0;
		while (g_map->map[g_map->c_arg][g_map->c_idx])
		{
			if (g_map->map[g_map->c_arg] \
				[g_map->c_idx] == 'N')
			g_map->char_cnt += 1;
			else if (g_map->map[g_map->c_arg] \
					[g_map->c_idx] == 'E')
			g_map->char_cnt += 1;
			else if (g_map->map[g_map->c_arg] \
					[g_map->c_idx] == 'S')
			g_map->char_cnt += 1;
			else if (g_map->map[g_map->c_arg] \
					[g_map->c_idx] == 'W')
			g_map->char_cnt += 1;
			g_map->c_idx++;
		}
		g_map->c_arg++;
	}
	check_charif(g_map);
}
