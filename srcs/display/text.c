#include "doom_nukem.h"

SDL_Texture		*generate_text(SDL_Renderer *rend, TTF_Font *font, const char *text, SDL_Color fg)
{
	SDL_Surface		*tmp;
	SDL_Texture		*texture;

	if (!(tmp = TTF_RenderText_Solid(font, text, fg)))
		return (ret_null_error("tmp allocation failed in generate_text"));
	if (!(texture = SDL_CreateTextureFromSurface(rend, tmp)))
		return (ret_null_error("texture alloaction failed in generate text"));
	SDL_FreeSurface(tmp);
	return (texture);
}

SDL_Texture		*create_bg_text_input(t_win *win, SDL_Rect rect, SDL_Color l_color, SDL_Color r_color)
{
	SDL_Texture		*texture;

	if (!(texture = SDL_CreateTexture(win->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h)))
		return (ret_null_error("texture allocation failed in create_bg_text_input"));
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_SetRenderTarget(win->rend, texture);
	SDL_SetRenderDrawColor(win->rend, l_color.r, l_color.g, l_color.b, l_color.a);
	fill_rect(win, (SDL_Rect){0, 0, rect.x, rect.h});
	SDL_SetRenderDrawColor(win->rend, r_color.r, r_color.g, r_color.b, r_color.a);
	fill_rect(win, (SDL_Rect){rect.x, 0, rect.w - rect.x, rect.h});
	SDL_SetRenderTarget(win->rend, NULL);
	return (texture);
}

SDL_Texture		*blit_text(SDL_Renderer *rend, SDL_Texture *bg_texture, SDL_Texture *text, SDL_Rect *text_rect)
{
	SDL_Texture		*t;
	t_size			s;

	SDL_QueryTexture(bg_texture, NULL, NULL, &s.w, &s.h);
	if (!(t = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, s.w, s.h)))
		return (ret_null_error("t allocation failed in blit text"));
	SDL_SetRenderTarget(rend, t);
	SDL_RenderCopy(rend, bg_texture, NULL, &(SDL_Rect){0, 0, s.w, s.h});
	SDL_RenderCopy(rend, text, NULL, text_rect);
	SDL_SetRenderTarget(rend, NULL);
	return (t);
}

static char			*remove_first_word(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	new_str = ft_strdup(&str[i]);
	return (new_str);
}

t_dot			get_text_size(t_win *win, char *text)
{
	t_dot	size;
	int		y_size_goal;

	TTF_SizeText(win->font.ui, text, &size.x, &size.y);
	y_size_goal = TEXT_RATIO * win->h;
	size.x = (y_size_goal * size.x) / size.y;
	size.y = y_size_goal;
	return (size);
}

static int				display_splitted(t_win *win, t_dot pos, char **splitted)
{
	SDL_Texture	*text;
	int			i;
	t_dot		line_size;

	i = 0;
	if (splitted)
	{
		while (splitted[i])
		{
			line_size = get_text_size(win, splitted[i]);
			if (!(text = generate_text(win->rend, win->font.ui, splitted[i], (SDL_Color){255, 50, 50, 255})))
				return (ret_error("display_splitted : generate_text failed"));
			SDL_RenderCopy(win->rend, text, NULL, &(SDL_Rect){pos.x, pos.y, line_size.x, line_size.y});
			pos.y += line_size.y;
			i++;
		}
	}
	return (1);
}

static char		*jump_words(char *str, int nb_words)
{
	int		i;
	int		i_words;

	i_words = 0;
	i = 0;
	if (str)
	{
		while (str[i] && i_words < nb_words)
		{
			if (str[i] != ' ')
			{
				i_words++;
				while (str[i] && str[i] != ' ')
					i++;
			}
			while (str[i] && str[i] == ' ')
				i++;
		}
		if (str[i])
			return (ft_strdup(&str[i]));
	}
	return (NULL);
}

static int				count_words(char *str, char c)
{
	int		i;
	int		i_words;

	i_words = 0;
	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] != c)
			{
				i_words++;
				while (str[i] && str[i] != c)
					i++;
			}
			while (str[i] && str[i] == c)
				i++;
		}
	}
	return (i_words);

}

int			display_text(t_win *win, t_dot pos, int max_width, char *text)
{
	char	*current_line;
	void	*tmp_str;
	char	**splitted_text;
	int		nb_words;

	splitted_text = NULL;
	if (text)
	{
		nb_words = 0;
		current_line = ft_strdup(text);
		while (current_line)
		{
			nb_words = 0;
			tmp_str = current_line;
			current_line = ft_strrev(current_line);
			ft_strdel((char**)&tmp_str);
			while (get_text_size(win, current_line).x > max_width)
			{
				tmp_str = current_line;
				current_line = remove_first_word(current_line);
				ft_strdel((char**)&tmp_str);
				nb_words++;
			}
			tmp_str = current_line;
			current_line = ft_strrev(current_line);
			ft_strdel((char**)&tmp_str);

			splitted_text = ft_2dstrpushback(splitted_text, ft_2dstrlen(splitted_text), current_line); // LEAKS
			tmp_str = current_line;
			current_line = jump_words(text, count_words(text, ' ') -  nb_words);
			ft_strdel((char**)&tmp_str);
			if ((current_line && current_line[0] == '\0') || count_words(text, ' ') -  nb_words < 0)
				current_line = NULL;
		}
		display_splitted(win, pos, splitted_text);
	}
	return (ft_2dstrlen(splitted_text));
}