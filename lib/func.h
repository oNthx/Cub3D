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
}		t_proc;

#endif