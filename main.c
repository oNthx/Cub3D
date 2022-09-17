/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:15:02 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/16 18:15:04 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

static int	set_zero(t_proc *proc)
{
	proc->height = 0;
	return (1);
}

static int	start_proc(t_proc *proc)
{
	proc->mlx = mlx_init();
	proc->mlx_win = mlx_new_window(proc->mlx, 1920, 1080, "Cub3D");
	mlx_loop(proc->mlx);
	return (0);
}

static int	checker(char **av, t_proc proc)
{
	if (!mapcheck(av[1]))
	{
		printf("Wrong Map Error\n");
		return (0);
	}
	if (!start_proc(&proc))
		printf("Error\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_proc	proc;

	if (ac == 2)
	{
		set_zero(&proc);
		checker(av, proc);
	}
	return (0);
}
