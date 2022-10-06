/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_S.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozgur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:30:00 by bozgur            #+#    #+#             */
/*   Updated: 2022/10/06 11:29:36 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3D.h"

//YOU SHOULD CHANGE THE IF ZONE

void	set_s(char **cmap, int **imap)
{
	int	idx;
	int	jdx;
	int	len;

	idx = 0;
	jdx = 0;
	len = 0;
	while (cmap[len])
		++len;
	while (cmap[len - idx])
	{
		jdx = 0;
		while (cmap[len][jdx])
		{
			if (cmap[len - idx][jdx] == 'S')
				cmap[len - idx][jdx] = '0';
			else if (cmap[len - idx][jdx] == ' ')
				cmap[len - idx][jdx] = '1';
			imap[idx][jdx] = ft_atoic(cmap[len - idx][jdx]);
			jdx++;
		}
		imap[idx][jdx] = 0;
		idx++;
	}
	imap[idx] = 0;
}
