#include "doom_nukem.h"

t_frame		*new_frame(const t_frect ratio, SDL_Texture *texture, Uint32 frame_flags, t_button *buttons)
{
	t_frame		*frame;
	t_button	*button_tmp;

	if (!(frame = (t_frame*)ft_memalloc(sizeof(t_frame))))
		return (ret_null_perror("frame allocation failed in new_frame"));
	frame->ratio = ratio;
	frame->texture = texture;
	frame->buttons = buttons;
	frame->nb_buttons = 0;
	button_tmp = frame->buttons;
	while (button_tmp)
	{
		frame->nb_buttons++;
		button_tmp = button_tmp->next;
	}
	frame->flags = frame_flags;
	return (frame);
}

void		add_frame(t_frame **frames, t_frame *new_frame)
{
	new_frame->next = *frames;
	*frames = new_frame;
}

void		add_button_to_frame(t_frame **frame, t_button *button)
{
	button->rect = (SDL_Rect){button->ratio.x * (*frame)->rect.w + (*frame)->rect.x,
								button->ratio.y * (*frame)->rect.h + (*frame)->rect.y,
								button->ratio.w * (*frame)->rect.w,
								button->ratio.h * (*frame)->rect.h};
	button->next = (*frame)->buttons;
	(*frame)->buttons = button;
	(*frame)->nb_buttons++;
}

void		add_frame_flags(t_frame **frame, Uint32 target_flags, Uint32 added_flags)
{
	t_frame		*f;

	f = *frame;
	while (f)
	{
		if (f->flags & target_flags)
			f->flags |= added_flags;
		f = f->next;
	}
}

void		remove_frame_flags(t_frame **frame, Uint32 target_flags, Uint32 removed_flags)
{
	t_frame		*f;

	f = *frame;
	while (f)
	{
		if (f->flags & target_flags && f->flags & removed_flags)
			f->flags -= removed_flags;
		f = f->next;
	}
}