/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:55:22 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 14:59:11 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_stash
{
	char			*str;
	struct s_stash	*next;
}	t_stash;

char	*get_next_line(int fd);

/* main functions */
void	ft_recover(t_stash **stash);
int		ft_reader(int fd, t_stash **stash);
void	ft_addline(t_stash *stash, char **line);
void	ft_addbuff(char *buf, t_stash **stash, int i);

/* utilities */
void	ft_unleash(t_stash *stash);
int		ft_checkiter(char *line);
int		ft_checklinea(t_stash **stash, char *line);
void	ft_left(t_stash **stash, t_stash *new, char *p1, char *p2);

int		ft_scanner(t_stash *stash);
int		ft_linkbrows(t_stash *stash);

t_stash	*ft_lst_get_last(t_stash *stash);

#endif