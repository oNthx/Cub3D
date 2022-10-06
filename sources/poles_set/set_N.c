/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_N.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:20:57 by bozgur            #+#    #+#             */
/*   Updated: 2022/10/06 02:12:54 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3D.h"

void	set_n(char **cmap, int **imap)
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
			if (cmap[idx][jdx] == 'N' )
				cmap[idx][jdx] = '0';
			else if (cmap[idx][jdx] == ' ')
				cmap[idx][jdx] = '1';
			imap[idx][jdx] = ft_atoic(cmap[idx][jdx]);
			jdx++;
		}
		imap[idx][jdx] = 0;
		idx++;
	}
	imap[idx] = 0;
}
