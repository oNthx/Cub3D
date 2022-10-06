/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_W.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:34:20 by bozgur            #+#    #+#             */
/*   Updated: 2022/10/06 11:13:20 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3D.h"

void	set_w(char **cmap, int **imap)
{
	int	idx;
	int	jdx;
	int	_idx;
	int	_jdx;

	idx = 0;
	_idx = 0;
	_jdx = 0;
	jdx = ft_strlen(cmap[idx]) - 1;
	while (cmap[idx][jdx])
	{
		while (cmap[idx][jdx])
		{
			if (cmap[idx][jdx] == 'W')
				cmap[idx][jdx] = '0';
			else if (cmap[idx][jdx] == ' ')
				cmap[idx][jdx] = '1';
			imap[_idx][_jdx++] = ft_atoic(cmap[idx++][jdx]);
		}
		imap[_idx][_jdx] = 0;
		_idx++;
		jdx--;
	}
	imap[_idx] = 0;
}
