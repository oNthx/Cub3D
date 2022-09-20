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

int	check_imgs(void)
{
	int	fd;

	fd = open("./xpm/NO.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/SO.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/WE.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/EA.xpm", O_RDONLY) == -1;
	return (fd);
}

static void	check_charif(t_proc *proc)
{
	if (proc->char_cnt == 0)
	{
		printf("no character start direction Error\n");
		exit(1);
	}
	else if (proc->char_cnt >= 2)
	{
		printf("character start direction too much Error\n");
		exit(1);
	}
}

void	map_character_check(t_proc *proc)
{
	while (proc->map[proc->c_arg])
	{
		proc->c_idx = 0;
		while (proc->map[proc->c_arg][proc->c_idx])
		{
			if (proc->map[proc->c_arg] \
				[proc->c_idx] == 'N')
			proc->char_cnt += 1;
			else if (proc->map[proc->c_arg] \
					[proc->c_idx] == 'E')
			proc->char_cnt += 1;
			else if (proc->map[proc->c_arg] \
					[proc->c_idx] == 'S')
			proc->char_cnt += 1;
			else if (proc->map[proc->c_arg] \
					[proc->c_idx] == 'W')
			proc->char_cnt += 1;
			proc->c_idx++;
		}
		proc->c_arg++;
	}
	check_charif(proc);
}
