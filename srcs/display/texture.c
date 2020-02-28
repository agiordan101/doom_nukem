#include "doom_nukem.h"

/*
**	En attendant de terminer le parser de png qui renverra aussi un SDL_Texture
*/
SDL_Texture		*load_texture(SDL_Renderer *rend, const char *file)
{
	SDL_Surface		*surface;
	SDL_Texture		*texture;

	if (!(surface = IMG_Load(file)))
		return (ret_null_error("failed to load surface in load_texture"));
	if (!(texture = SDL_CreateTextureFromSurface(rend, surface)))
		return (ret_null_error("failed to create texture from surface in load_texture"));
	SDL_FreeSurface(surface);
	return (texture);
}