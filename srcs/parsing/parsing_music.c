#include "doom_nukem.h"

void		attribute_music(t_music *music)
{
	music->tmusic[0] = Mix_LoadWAV("sounds/shotGun.mp3");
	music->tmusic[1] = Mix_LoadWAV("sounds/reload.mp3");
	music->tmusic[2] = Mix_LoadWAV("sounds/healsound.mp3");
	music->tmusic[3] = Mix_LoadWAV("sounds/shieldsound.mp3");
	music->tmusic[4] = Mix_LoadWAV("sounds/slotsound.mp3");
	music->tmusic[5] = Mix_LoadWAV("sounds/damageSound.mp3");
}

t_music		*define_music(void)
{
	t_music		*music;

	if (!(music = (t_music *)ft_memalloc(sizeof(t_music))))
		return (ret_null_error("Music allocation failed in parsing_music l7"));
	attribute_music(music);
	ft_putendl("Music_parse done →");
	return (music);
}
