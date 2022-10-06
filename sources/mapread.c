/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:55:49 by aozcelik          #+#    #+#             */
/*   Updated: 2022/10/05 19:53:54 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void	map_read(t_proc *proc, char *av)
{
	char	*map;
	int		fd;

	fd = open(av, O_RDONLY);
	while (fd < 0)
	{
		printf("Error\nMap Not Found!!\n");
		exit(1);
	}
	map = get_map(fd, av);
	proc->map = ft_split(map, '\n', proc);
	free(map);
}

char	*get_map(int fd, char *av)
{
	char	*map;
	int		bufsize;

	bufsize = map_len(av);
	map = (char *)ft_calloc(bufsize + 1, sizeof(char));
	if (!map)
		return (0);
	read(fd, map, bufsize);
	map[bufsize] = 0;
	if (!*map)
		return (get_map_free(map));
	return (map);
}

void	*get_map_free(void *f)
{
	free (f);
	return (NULL);
}

int	map_len(char *av)
{
	int		fd;
	int		i;
	int		m_cnt;
	char	s;

	m_cnt = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	i = read(fd, &s, 1);
	while (i > 0)
	{
		i = read(fd, &s, 1);
		m_cnt++;
	}
	close(fd);
	if (m_cnt == 0)
	{
		printf("Error\nCould not read file!!\n");
		exit(0);
	}
	return (m_cnt);
}
