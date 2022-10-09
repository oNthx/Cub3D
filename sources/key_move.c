/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:25:22 by aozcelik          #+#    #+#             */
/*   Updated: 2022/10/10 01:16:24 by bozgur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

static void	rotate_cam(t_proc *proc, t_cam *cam)
{
	double	old_dir_y;
	double	old_plane_y;

	old_dir_y = cam->dir_y;
	cam->dir_y = cam->dir_y * cos(-proc->g_plyr.rotspd) - cam->dir_x \
		* sin(-proc->g_plyr.rotspd);
	cam->dir_x = old_dir_y * sin(-proc->g_plyr.rotspd) + cam->dir_x \
		* cos(-proc->g_plyr.rotspd);
	old_plane_y = cam->plane_y;
	cam->plane_y = cam->plane_y * cos(-proc->g_plyr.rotspd) - cam->plane_x \
		* sin(-proc->g_plyr.rotspd);
	cam->plane_x = old_plane_y * sin(-proc->g_plyr.rotspd) + cam->plane_x \
		* cos(-proc->g_plyr.rotspd);
}

static void	key_move2(t_proc *proc, t_cam *cam, int **map)
{
	if (proc->kbd.l || proc->kbd.r)
	{
		rotate_cam(proc, cam);
	}
	if (proc->kbd.d)
	{
		if (!map[(int)(cam->pos_y + cam->plane_y * proc->g_plyr.movespd)]
			[(int)cam->pos_x])
			cam->pos_y += cam->plane_y * proc->g_plyr.movespd;
		if (!map[(int)cam->pos_y]
			[(int)(cam->pos_x + cam->plane_x * proc->g_plyr.movespd)])
			cam->pos_x += cam->plane_x * proc->g_plyr.movespd;
	}
	if (proc->kbd.a)
	{
		if (!map[(int)(cam->pos_y - cam->plane_y * proc->g_plyr.movespd)]
			[(int)cam->pos_x])
			cam->pos_y -= cam->plane_y * proc->g_plyr.movespd;
		if (!map[(int)cam->pos_y]
			[(int)(cam->pos_x - cam->plane_x * proc->g_plyr.movespd)])
			cam->pos_x -= cam->plane_x * proc->g_plyr.movespd;
	}
}

void	key_move(t_proc *proc, t_cam *cam)
{
	int	**map;

	map = proc->g_map.mapi;
	if (proc->kbd.w)
	{
		if (!map[(int)(cam->pos_y + cam->dir_y * proc->g_plyr.movespd)] \
		[(int)cam->pos_x])
			cam->pos_y += cam->dir_y * proc->g_plyr.movespd;
		if (!map[(int)cam->pos_y][(int)(cam->pos_x + cam->dir_x \
			* proc->g_plyr.movespd)])
			cam->pos_x += cam->dir_x * proc->g_plyr.movespd;
	}
	if (proc->kbd.s)
	{
		if (!map[(int)(cam->pos_y - cam->dir_y * proc->g_plyr.movespd)] \
			[(int)cam->pos_x])
			cam->pos_y -= cam->dir_y * proc->g_plyr.movespd;
		if (!map[(int)cam->pos_y][(int)(cam->pos_x - cam->dir_x \
			* proc->g_plyr.movespd)])
			cam->pos_x -= cam->dir_x * proc->g_plyr.movespd;
	}
	key_move2(proc, cam, map);
}
