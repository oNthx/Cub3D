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

	fd = open("./xpm/W.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/S.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/A.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/D.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/C.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/B.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/M.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/E.xpm", O_RDONLY) == -1;
	return (fd);
}
