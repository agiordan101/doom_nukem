/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 09:32:17 by gal               #+#    #+#             */
/*   Updated: 2020/06/05 14:07:48 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/stat.h>
# ifdef __linux__
#  include "SDL2/SDL.h"
#  include "SDL2/SDL_ttf.h"
#  include "SDL2/SDL_image.h"
#  include "SDL2/SDL_mixer.h"
# else
#  include "SDL.h"
#  include "SDL_ttf.h"
#  include "SDL_image.h"
#  include "SDL_mixer.h"
# endif
# include "libft.h"
# include <time.h>

# define WIDTH			    960
# define HEIGHT				720
# define SENSITIVE			0.0015

# define OBJECT_ROTATION_VELOCITY	10

# define MAX_SECTORS		25
# define NEXT_FACTOR		50
# define SIDE_LEN			40
# define ID_SIZE            20
# define ANG_HOR_VER        5
# define MIN_TEXT_SIZE      10
# define TEXT_RATIO         0.021
# define NEXT_RADIUS		20

# define _PI_4				0.78539816339
# define _3_PI_2		    4.71238898038
# define _2_PI			    6.28318530718
# define N_DOTS_POLY		4
# define N_THREADS			8

# include "bordel_struct.h"
# include "bordel_proto.h"
#endif
