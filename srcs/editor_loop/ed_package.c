/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_package.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:48:29 by widrye            #+#    #+#             */
/*   Updated: 2020/06/03 18:04:57 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

static int	ed_write_interfaces(int fd, char *name)
{
	static char		tmp[BUFSIZ];
	int				fd_interf;
	int				n;
	int				bytes;

	fd_interf = open(ft_strjoin("interfaces/", name), O_RDONLY);
	if (fd_interf < 0)
		return (0);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd(name, fd);
	bytes = 0;
	while ((n = read(fd_interf, tmp, sizeof(tmp))))
		bytes += n;
	ft_putendl_fd(ft_itoa(bytes), fd);
	fd_interf = open(ft_strjoin("interfaces/", name), O_RDONLY);
	while ((n = read(fd_interf, tmp, sizeof(tmp))))
	{
		if (write(fd, tmp, n) < 0)
			return (0);
	}
	return (1);
}

static int	ed_export_interfaces(int fd)
{
	if (!ed_write_interfaces(fd, "editor_interface"))
		return (0);
	if (!ed_write_interfaces(fd, "menu_dead"))
		return (0);
	if (!ed_write_interfaces(fd, "menu_interface"))
		return (0);
	if (!ed_write_interfaces(fd, "menu_win"))
		return (0);
	return (1);
}

int			ed_package_2(int fd)
{
	ft_putendl_fd("\nFonts", fd);
	if (!ed_export_fonts(fd))
	{
		ui_ret_error("ed_package", "failed to export fonts", 0);
		return (0);
	}
	ft_putendl_fd("\nInterfaces", fd);
	if (!ed_export_interfaces(fd))
	{
		ui_ret_error("ed_package", "failed to export libui interfaces", 0);
		return (0);
	}
	return (1);
}

void		ed_package(void *ed_exp)
{
	t_export	*export;

	export = (t_export*)ed_exp;
	export->fd = open(export->path, O_CREAT | O_WRONLY | O_TRUNC,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	export->pack = 1;
	ft_putendl_fd("#GAMEREADY#\nTextures", export->fd);
	if (!ed_export_textures(export->fd, (t_map *)export->map))
	{
		ui_ret_error("ed_package", "failed to export textures", 0);
		return ;
	}
	ft_putendl_fd("Sounds", export->fd);
	if (!ed_export_sounds(export->fd))
	{
		ui_ret_error("ed_package", "failed to export sounds", 0);
		return ;
	}
	if (!ed_package_2(export->fd))
		return ;
	ed_export(ed_exp);
}
