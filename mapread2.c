/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:08:23 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/22 15:08:24 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

static void	check_trans_frpg(char *Frpg, t_proc *proc)
{

}

static void	check_trans_crpg(char *Crpg, t_proc *proc)
{

}

static void	check_trans_img(char **map)
{
	if (ft_strcmp(*map, "NO") || ft_strcmp(*map, "SO") \
		|| ft_strcmp(*map, "WE") || ft_strcmp(*map, "EA"))
		check_img(*map + 3);
	else if ((map[0][1] == ' ' ) && (*map[0] == 'N' || *map[0] == 'S' \
		|| *map[0] == 'W' || *map[0] == 'E'))
		check_img(*map + 2);
	else
	{
		printf("Error\nMap Arguman is wrong\n");
		exit(1);
	}
}

void	map_trans_rpg_img_gmap(t_proc *proc)
{
	char	**maps;

	maps = proc->map;
	check_trans_img(maps);
	check_trans_frpg(maps[4], proc);
	check_trans_crpg(maps[5], proc);

}
