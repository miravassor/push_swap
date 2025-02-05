/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:19:58 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 14:46:21 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

void	ft_recover(t_stash **stash)
{
	char	*p1;
	char	*p2;
	t_stash	*new;
	t_stash	*end;

	new = malloc(sizeof(t_stash));
	if (!new || !stash)
		return ;
	new->next = NULL;
	end = ft_lst_get_last(*stash);
	p1 = end->str;
	while (*p1 && *p1 != '\n')
		p1++;
	if (*p1 == '\n')
		p1++;
	p2 = p1;
	while (*p2)
		p2++;
	ft_left(stash, new, p1, p2);
}

void	ft_addbuff(char *buf, t_stash **stash, int i)
{
	t_stash	*new;
	t_stash	*current;
	char	*p1;
	int		j;

	new = malloc(sizeof(t_stash));
	if (!new)
		return ;
	new->next = NULL;
	new->str = malloc(sizeof(char) * (i + 1));
	if (!new->str)
		return ;
	p1 = new->str;
	j = 0;
	while (*buf && (j++ < i))
		*p1++ = *buf++;
	*p1 = '\0';
	if (*stash == NULL)
	{
		*stash = new;
		return ;
	}
	current = ft_lst_get_last(*stash);
	current->next = new;
}

int	ft_reader(int fd, t_stash **stash)
{
	char	*buf;
	int		i;

	i = 1;
	while (!ft_scanner(*stash) && i != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (1);
		i = (int)read(fd, buf, BUFFER_SIZE);
		if ((!(*stash) && i == 0) || i < 0)
		{
			free(buf);
			return (0);
		}
		buf[i] = '\0';
		ft_addbuff(buf, stash, i);
		free(buf);
	}
	return (0);
}

void	ft_addline(t_stash *stash, char **line)
{
	char	*p1;
	char	*p2;

	if (!stash)
		return ;
	*line = malloc(sizeof(char) * (ft_linkbrows(stash) + 1));
	if (!*line)
		return ;
	p1 = *line;
	while (stash)
	{
		p2 = stash->str;
		while (*p2)
		{
			if (*p2 == '\n')
			{
				*p1++ = '\n';
				break ;
			}
			*p1++ = *p2++;
		}
		stash = stash->next;
	}
	*p1 = '\0';
}

char	*get_next_line(int fd)
{
	static t_stash	*stash = NULL;
	char			*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	if (ft_reader(fd, &stash))
		return ("T");
	if (!stash)
		return (NULL);
	ft_addline(stash, &line);
	if (ft_checklinea(&stash, line))
	{
		free(line);
		return ("T");
	}
	ft_recover(&stash);
	if (line[0] == '\0')
	{
		ft_unleash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
