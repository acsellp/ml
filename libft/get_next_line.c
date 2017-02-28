/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:04:14 by dplesca           #+#    #+#             */
/*   Updated: 2017/01/05 13:13:36 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	insert(t_lnparam **stat, t_lnparam **nd, int fd)
{
	t_lnparam *st;
	t_lnparam *tmp;

	if (!*stat)
	{
		*stat = (t_lnparam*)ft_memalloc(sizeof(t_lnparam));
		(*stat)->fd = fd;
		(*stat)->next = NULL;
		(*stat)->cpy = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE);
		*nd = *stat;
		return ;
	}
	tmp = *stat;
	while (tmp->next)
		tmp = tmp->next;
	st = (t_lnparam*)ft_memalloc(sizeof(t_lnparam));
	st->cpy = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE);
	st->fd = fd;
	st->next = NULL;
	tmp->next = st;
	*nd = st;
}

void	check_stat(t_lnparam **stat, int fd, t_lnparam **nd)
{
	t_lnparam *st;

	st = *stat;
	while (st)
	{
		if (st->fd == fd)
		{
			*nd = st;
			return ;
		}
		st = st->next;
	}
	insert(stat, nd, fd);
}

int		return_line(char **line, t_lnparam *fp)
{
	int		i;
	char	*str;

	*line = (char*)ft_memalloc(sizeof(char) * fp->sz);
	if (fp->null == 1)
		return (0);
	str = ft_strchr(fp->cpy, '\n');
	i = 0;
	while (*(fp->cpy + i) && *(fp->cpy + i) != '\n')
	{
		(*line)[i] = *(fp->cpy + i);
		i++;
	}
	*(*line + i) = '\0';
	if (str && *str)
	{
		str++;
		ft_memccpy(fp->cpy, str, '\0', fp->sz);
	}
	else if (fp->ret == 0 && !str)
		fp->null = 1;
	return (1);
}

void	read_file(t_lnparam *fp, int fd, int size, char *str)
{
	char	buff[BUFF_SIZE + 1];

	while ((fp->ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[fp->ret] = '\0';
		str = (char*)ft_memalloc(sizeof(char) * (size + 1));
		ft_memcpy(str, fp->cpy, fp->sz);
		ft_memdel((void**)&fp->cpy);
		size += fp->ret;
		fp->cpy = (char*)ft_memalloc(sizeof(char) * (size + 1));
		ft_memcpy(fp->cpy, str, fp->sz);
		ft_memdel((void**)&str);
		ft_strcat(fp->cpy, buff);
		fp->sz += fp->ret;
		if (ft_strchr(buff, '\n') || fp->ret == -1)
			break ;
	}
}

int		get_next_line(int fd, char **line)
{
	static t_lnparam		*stat;
	t_lnparam				*fp;
	int						size;
	char					c;

	if (line == NULL || fd < 0 || read(fd, &c, 0) < 0)
		return (-1);
	fp = NULL;
	check_stat(&stat, fd, &fp);
	fp->sz = ft_strlen(fp->cpy);
	size = BUFF_SIZE + fp->sz;
	read_file(fp, fd, size, NULL);
	if (!*fp->cpy && !fp->ret)
		return (0);
	if (return_line(line, fp))
		return (1);
	return (0);
}
