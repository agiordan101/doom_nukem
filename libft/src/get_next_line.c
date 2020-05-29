/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 21:57:26 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/29 13:26:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int		slice_ovf(char **ovf, char **line)
{
	size_t	len;
	char	*tmp;

	if (*ovf && ft_strchr(*ovf, '\n'))
	{
		len = ft_strcspn(*ovf, "\n");
		*line = ft_strndup(*ovf, len);
		tmp = ft_strsub(*ovf, len + 1, ft_strlen(*ovf) - len);
		ft_strdel(ovf);
		*ovf = tmp;
		return (1);
	}
	return (0);
}

static void		slice_n_stock(char *buf, char **line, char **ovf, int bytes)
{
	size_t	len;
	size_t	len_stock;
	char	*tmp;

	len = ft_strcspn(buf, "\n\0");
	len_stock = bytes - len;
	if (*ovf)
	{
		tmp = ft_strndup(buf, len);
		*line = ft_strjoin(*ovf, tmp);
		ft_strdel(&tmp);
	}
	else
		*line = ft_strndup(buf, len);
	tmp = ft_strsub(buf, len + 1, len_stock);
	ft_strdel(ovf);
	*ovf = tmp;
}

static void		stock_all(char *buf, char **ovf)
{
	char	*tmp;

	if (!*ovf)
		*ovf = ft_strdup(buf);
	else
	{
		tmp = ft_strjoin(*ovf, buf);
		ft_strdel(ovf);
		*ovf = tmp;
	}
}

static int		check_end(char **line, char **ovf)
{
	if (*ovf && **ovf)
	{
		*line = ft_strdup(*ovf);
		ft_strdel(ovf);
		return (1);
	}
	else
		return (0);
}

int				get_next_line(const int fd, char **line)
{
	int						bytes;
	char					buf[BUFF_SIZE + 1];
	static char				*ovf[42000] = { NULL };

	if (fd < 0 || !line || (read(fd, buf, 0) < 0) || BUFF_SIZE < 1)
		return (-1);
	if (ovf[fd] && slice_ovf(&ovf[fd], line))
		return (1);
	while ((bytes = read(fd, buf, BUFF_SIZE)))
	{
		buf[bytes] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			slice_n_stock(buf, line, &ovf[fd], bytes);
			return (1);
		}
		else
			stock_all(buf, &ovf[fd]);
	}
	if (check_end(line, &ovf[fd]))
		return (1);
	return (0);
}
