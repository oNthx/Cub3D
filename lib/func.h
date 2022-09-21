/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:18:35 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/17 13:18:36 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

typedef struct s_kbd
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	r;
	int	l;
}	t_kbd;

typedef struct s_rpg
{
	int		rpg_r;
	int		rpg_p;
	int		rpg_g;
}		t_rpg;

typedef struct s_proc
{
	void	*mlx;
	void	*mlx_win;
	void	**img_path;
	char	**map;
	int		height;
	int		row_cnt;
	int		row_len;
	int		new_cnt;
	int		c_arg;
	int		c_idx;
	int		char_cnt;
	t_rpg	f_rpg;
	t_rpg	c_rpg;
	t_kbd	button;
}		t_proc;

#endif