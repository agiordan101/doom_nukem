/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:29:01 by widrye            #+#    #+#             */
/*   Updated: 2020/06/03 17:39:29 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int			write_tmp_file(int fd, char *name, size_t bytes, char *dir)
{
	int		fd_tex;
	char	*tmp;
	int		n;

	if (!(tmp = (char *)malloc(sizeof(char) * bytes)))
		return (0);
	fd_tex = open(ft_strjoin(dir, name),
	O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 0777);
	n = read(fd, tmp, bytes);
	if (write(fd_tex, tmp, n) < 0)
		return (0);
	return (1);
}

int			is_new_bin_dir(char *name)
{
	return (!ft_strcmp(name, "Sounds") ||
			!ft_strcmp(name, "Fonts") ||
			!ft_strcmp(name, "Interfaces") ||
			!ft_strcmp(name, "###########"));
}

int			recurse_through_tmp_files(int fd, char *name, char *len, char *dir)
{
	return ((!write_tmp_file(fd, ft_strdup(name),
			ft_atoi(len), dir) || !create_tmp_files(fd, dir)) ? 0 : 1);
}

int			create_tmp_files(int fd, char *dir)
{
	char		tmp[1];
	t_fdot_3d	index;
	char		name[BUFSIZ];
	char		len[BUFSIZ];

	index = (t_fdot_3d){0, 0, 0};
	ft_bzero(name, BUFSIZ);
	ft_bzero(len, BUFSIZ);
	while ((read(fd, tmp, 1)) && (int)index.x < 3)
	{
		if (*tmp == '\n')
		{
			if ((int)index.x == 1 && (name[(int)index.y] = '\0') == '\0')
				if (is_new_bin_dir(name))
					return (1);
			if ((int)index.x == 2 && (len[(int)index.z] = '\0') == '\0')
				return (recurse_through_tmp_files(fd, name, len, dir));
			index.x++;
		}
		if ((int)index.x == 1 && *tmp != '\n')
			name[(int)index.y++] = *tmp;
		if ((int)index.x == 2 && *tmp != '\n')
			len[(int)index.z++] = *tmp;
	}
	return (1);
}

void		create_tmp_bin_files(int fd)
{
	mkdir("textures", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	mkdir("sounds", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	mkdir("TTF", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	mkdir("interfaces", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (!create_tmp_files(fd, "textures/"))
		ft_putendl("failed to create tmp textures files");
	if (!create_tmp_files(fd, "sounds/"))
		ft_putendl("failed to create tmp sound files");
	if (!create_tmp_files(fd, "TTF/"))
		ft_putendl("failed to create tmp .TTF files");
	if (!create_tmp_files(fd, "interfaces/"))
		ft_putendl("failed to create tmp interfaces files");
}
