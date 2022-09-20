/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:57:35 by aozcelik          #+#    #+#             */
/*   Updated: 2022/09/17 14:57:37 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

//mapcheck.c

int		mapcheck(char *map);
int		check_imgs(void);
void	map_character_check(t_proc *proc);

//function.c

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c, t_proc *proc);

//mapread.c

void	map_read(t_proc *proc, char *av);
void	*get_map_free(void *f);
char	*get_map(int fd, char *av);
int		map_len(char *av);

#endif
