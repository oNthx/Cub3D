/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_E.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:16:25 by bozgur            #+#    #+#             */
/*   Updated: 2022/10/06 11:32:18 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3D.h"

void	set_e(char **cmap, int **imap)
{
	int	_idx;
	int	_jdx;
	int	idx;
	int	jdx;

	idx = 0;
	jdx = 0;
	_idx = 0;
	_jdx = 0;
	printf("THE CMAP IS %s\n", cmap[idx]);
	while (cmap[idx][jdx])
	{
		_jdx = 0;
		while (cmap[idx + _jdx][jdx])
		{
			printf("BURA?\n");
			if (cmap[idx + _jdx][jdx] == 'E')
				cmap[idx + _jdx][jdx] = '0';
			else if (cmap[idx + _jdx][jdx] == ' ')
				cmap[idx + _jdx][jdx] = '1';
			printf("THE IDX IS %d ==%d== WARNING |%d|\n",_jdx, jdx, ft_atoic(cmap[idx + _jdx][jdx]));
			imap[_idx][_jdx] = ft_atoic(cmap[idx + _jdx][jdx]);
			_jdx++;
		}
		imap[_idx][_jdx] = 0;
		jdx++;
		_idx++;
	}
	imap[_idx] = 0;
}
