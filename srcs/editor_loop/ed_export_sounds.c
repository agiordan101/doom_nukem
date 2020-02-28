/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_export_sounds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:35:55 by widrye            #+#    #+#             */
/*   Updated: 2020/02/27 19:41:11 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int ed_write_sounds(int fd)
{
	static char tmp[BUFSIZ];
	int fd_text;
	int n;

	ft_putendl_fd("\n\tshieldsound.mp3", fd);
	fd_text = open("sounds/shieldsound.mp3", O_RDONLY);
	if (fd_text < 0)
			return (0);
	while ((n = read(fd_text, tmp, sizeof(tmp))))
		write(fd, tmp, n);
	ft_putendl_fd("\n\tslotsound.mp3", fd);
	fd_text = open("sounds/slotsound.mp3", O_RDONLY);
	if (fd_text < 0)
			return (0);
	while ((n = read(fd_text, tmp, sizeof(tmp))))
		write(fd, tmp, n);
	ft_putendl_fd("\n\tdamageSound.mp3", fd);
	fd_text = open("sounds/damageSound.mp3", O_RDONLY);
	if (fd_text < 0)
			return (0);
	while ((n = read(fd_text, tmp, sizeof(tmp))))
		write(fd, tmp, n);
	return (1);
}

int ed_export_sounds(int fd)
{
	static char tmp[BUFSIZ];
	int fd_text;
	int n;

	ft_putendl_fd("\tshotGun.mp3", fd);
	fd_text = open("sounds/shotGun.mp3", O_RDONLY);
	if (fd_text < 0)
			return (0);
	while ((n = read(fd_text, tmp, sizeof(tmp))))
		write(fd, tmp, n);
	ft_putendl_fd("\n\treload.mp3", fd);
	fd_text = open("sounds/reload.mp3", O_RDONLY);
	if (fd_text < 0)
			return (0);
	while ((n = read(fd_text, tmp, sizeof(tmp))))
		write(fd, tmp, n);
	ft_putendl_fd("\n\thealsound.mp3", fd);
	fd_text = open("sounds/healsound.mp3", O_RDONLY);
	if (fd_text < 0)
			return (0);
	while ((n = read(fd_text, tmp, sizeof(tmp))))
		write(fd, tmp, n);
	return (ed_write_sounds(fd));
}