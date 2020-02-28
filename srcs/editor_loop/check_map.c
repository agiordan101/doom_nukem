// #include "doom_nukem.h"

// static int		add_error_message(t_win *win, char *error_message)
// {
// 	int		i;
// 	char	**new_tab;

// 	if (error_message)
// 	{
// 		if (!(new_tab = (char**)ft_memalloc(sizeof(char*) * (win->nb_error_msg + 2))))
// 			return(ret_error("add_error_message : new_tab allaction failed"));
// 		i = 0;
// 		if (win->error_msg)
// 		{
// 			while (win->error_msg[i])
// 			{
// 				new_tab[i] = win->error_msg[i];
// 				i++;
// 			}
// 		}
// 		new_tab[i++] = error_message;
// 		new_tab[i] = NULL;
// 		win->error_msg = new_tab;
// 		win->nb_error_msg++;
// 	}
// 	return (1);
// }

// static char		*create_linedef_error(t_linedef *l, char *error_message)
// {
// 	char	*message;

// 	message = ft_strjoin("linedef ((",
// 				ft_strjoin(ft_itoa(l->p1.x),
// 				ft_strjoin(", ",
// 				ft_strjoin(ft_itoa(l->p1.y),
// 				ft_strjoin("), (",
// 				ft_strjoin(ft_itoa(l->p2.x),
// 				ft_strjoin(", ",
// 				ft_strjoin(ft_itoa(l->p2.y),
// 				ft_strjoin(")) error : ", error_message)))))))));
// 	return (message);
// }

// static int		check_linedefs(t_win *win, t_map_editor *map)
// {
//     t_sector	*s;
// 	t_linedef	*l;

// 	s = map->sectors;
// 	while (s)
// 	{
// 		l = s->lines;
// 		while (l)
// 		{
// 			if (l->p1.x == l->p2.x && l->p1.y == l->p2.y)
// 			{
// 				if (!add_error_message(win, create_linedef_error(l, "incorrect linedef, p1 = p2")))
// 					return (ret_error("check_linedefs : add_error_message failed"));
// 			}
// 			l = l->next;
// 		}
// 		s = s->next;
// 	}
// 	return (1);
// }

// void			check_map(t_win *win, t_map_editor *map)
// {
// 	win->nb_error_msg = 0;
// 	win->error_msg = NULL; // LEAKS
// 	check_linedefs(win, map);
// }

