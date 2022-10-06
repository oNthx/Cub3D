/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:01:13 by aozcelik          #+#    #+#             */
/*   Updated: 2022/10/05 19:54:19 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

int	frgbtrans(char **rgbno)
{
	char	*frgb;
	int		rgbnu;

	frgb = ft_strjoin(rgbno[0], rgbno[1], rgbno[2]);
	rgbnu = ft_atoi(frgb);
	return (rgbnu);
}

int	crgbtrans(char **rgbno)
{
	char	*crgb;
	int		rgbnu;

	crgb = ft_strjoin(rgbno[0], rgbno[1], rgbno[2]);
	rgbnu = ft_atoi(crgb);
	return (rgbnu);
}

static int	g_maptointmap(t_proc *proc)
{
	int	i;
	int	j;
	int	idx;
	int	tab;

	i = 0;
	j = 0;
	idx = 0;
	tab = 0;
	while (proc->g_map.map[i])
	{
		if (j > idx)
			idx = j;
		if (i > j)
			idx = i;
		j = 0;
		while (proc->g_map.map[i][j])
		{
			if (proc->g_map.map[i][j] == '\t')
				tab += 8;
			j++;
		}
		i++;
	}
	return (idx + tab);
}

void	g_mapexportintmap(t_proc *proc)
{	
	int		i;
	int		j;
	int		idx;
	int		**imap;
	char	**cmap;

	i = 0;
	j = 0;
	cmap = proc->g_map.map;
	idx = g_maptointmap(proc);
	imap = (int **)malloc(sizeof(int *) * (idx + 1));
	while (j < idx)
	{
		imap[j] = malloc(sizeof(int) * (idx + 1));
		j++;
	}
	i = 0;
	poles_casting(cmap, imap);
	proc->g_map.mapi = imap;
}

void	poles_casting(char **cmap, int **imap)
{
	int	idx;
	int	jdx;

	idx = 0;
	jdx = 0;
	while (cmap[idx])
	{
		jdx = 0;
		while (cmap[idx][jdx])
		{
			if (cmap[idx][jdx] == 'E')
				set_e(cmap, imap);
			else if (cmap[idx][jdx] == 'W')
				set_w(cmap, imap);
			else if (cmap[idx][jdx] == 'N')
				set_n(cmap, imap);
			else if (cmap[idx][jdx] == 'S')
				set_s(cmap, imap);
			jdx++;
		}
		idx++;
	}
}
