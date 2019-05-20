#include "doom_nukem.h"

void		ft_fill_coord(t_sector *sector, char **tab, int i)
{
	int y;
	int flag;

	y = 0;
	flag = 0;
	while (!(ft_strchr(tab[i], '}')))
	{
		if (ft_strstr(tab[i], "dot") && flag == 0)
		{
			ft_find_coord_p1(sector, tab[i]);
			flag++;
		}
		else if (ft_strstr(tab[i], "dot") && flag != 0)
			ft_find_coord_p2(sector, tab[i]);
		i++;
	}
}

int			count_line(int fp1)
{
	int		nb;
	char	*line;

	nb = 0;
	while (get_next_line(fp1, &line) > 0)
	{
		free(line);
		nb++;
	}
	return (nb);
}

char		**ft_fill_map(int fd, int fp1)
{
	char	*line;
	char	**tab;
	int		i;
	int		nb;

	i = 0;
	nb = count_line(fp1);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		tab[i] = ft_strdup(line);
		free(line);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void		ft_fill_data(char *tab, t_sector *sector)
{
	if (ft_strstr(tab, "floorHeight"))
		sector->floor_height =
		ft_atoi(ft_strrchr(tab, '=') + 1);
	if (ft_strstr(tab, "ceilHeight"))
		sector->ceil_height = ft_atoi(ft_strrchr(tab, '=') + 1);
}

void		ft_data_storing(int fd, int fp1)
{
	char		**tab;
	int			i;
	t_sector	*sector;

	i = -1;
	sector = NULL;
	tab = ft_fill_map(fd, fp1);
	ft_parse_error(tab);
	while (tab[++i])
	{
		if (ft_strstr(tab[i], "Sector"))
		{
			add_sector(&sector, new_void_sector());
			while ((ft_strchr(tab[i], '}') == NULL ||
			ft_strchr(tab[i - 1], '}') == NULL))
			{
				ft_fill_data(tab[i], sector);
				if (ft_strstr(tab[i], "line"))
				{
					add_linedef(&sector->lines, new_void_linedef());
					ft_fill_coord(sector, tab, i);
					//printf("floor_heignt = %d\n", sector->floor_height);
					//printf("ceil_height = %d\n", sector->ceil_height);
					//printf("p1.x = %d p1.y = %d\n", sector->lines->p1.x, sector->lines->p1.y);
					//printf("p2.x = %d p2.y = %d\n", sector->lines->p2.x, sector->lines->p2.y);
					//printf("\n");
				}
				i++;
			}
		}
	}
}

