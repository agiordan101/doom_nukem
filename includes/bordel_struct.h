#ifndef BORDEL_STRUCT_H
# define BORDEL_STRUCT_H

# include "ui_win.h"
# include "SDL.h"

typedef struct		s_fdot_3d
{
	float			x;
	float			y;
	float			z;
}					t_fdot_3d;

typedef struct		s_matrix
{
	float			_00;
	float			_01;
	float			_02;
	float			_10;
	float			_11;
	float			_12;
	float			_20;
	float			_21;
	float			_22;
}					t_matrix;

typedef struct		s_size
{
	int				w;
	int				h;
}					t_size;

typedef struct 		s_circle
{
	int				x;
	int				y;
	int				radius;
}					t_circle;

typedef struct		s_affine
{
	float			a;
	float			b;
	int				isequation;
	float			angle;
}					t_affine;

typedef struct		s_plan
{
	t_fdot_3d		v;
	float			d;
}					t_plan;

typedef struct		s_cartesienne
{
	float			ox;	//Utilise pour les tp de ray intersecteur
	float			oy;
	float			oz;
	float			vx;
	float			vy;
	float			vz;

	// int				launch;
	float			dist;
	struct s_poly	*poly;
	int				color;
	t_fdot_3d		collision;
	struct s_cartesienne	*next;
}					t_cartesienne;

/*
** =====================================================================================
** ================================== UI_FUNCTION ======================================
** =====================================================================================
*/

typedef struct	s_arg_menu
{
	int			*loop; // renommer en variable
	int			value;
}				t_arg_menu;

typedef enum	e_editor
{
	ED_NONE = 0,
	ED_MODE_CHANGED = 1,
	ED_SELECTION = 2,
	ED_PLACE = 4,
	ED_WALL = 8,
	ED_FLAT = 16,
	ED_INCLINED = 32,
	ED_PLAYER = 64,
	ED_DRAW_HELP = 128,
	ED_MOB	= 256,
	ED_HEAL = 512,
	ED_SHIELD = 1024,
	ED_TP = 2048,
	ED_BOX = 4096,
	ED_GRAVITY = 8192,
	ED_BULLET = 16384
}				t_editor_flag;

typedef enum	e_editor_calc
{
	ED_CALC_NONE = 0,
	ED_CALC_NORMAL = 1,
	ED_CALC_Z = 2
}				t_editor_calc;

# define ED_ALL_TYPES ED_WALL + ED_FLAT + ED_INCLINED + ED_PLAYER + ED_MOB\
+ ED_HEAL + ED_SHIELD + ED_GRAVITY + ED_BULLET + ED_BOX

typedef struct		s_kit_flags
{
	t_editor_flag	*variable;
	int				flags;
}					t_kit_flags;


/*
** ====================================================================================
** ================================== DATA ============================================
** ====================================================================================
*/

/*
**	---------------------------------- Music --------------------------------------------
*/

typedef struct s_music
{
	Mix_Chunk 	*tmusic[6];
}				t_music;

/*
**	---------------------------------- Timer --------------------------------------------
*/

typedef struct	s_timer
{
	uint32_t		time;
	uint32_t		save;
	int 			index;
}				t_timer;

typedef struct s_timers
{
	t_timer		bullet_cd;
	t_timer		item_cd;
	t_timer		text_cd;
	t_timer		reload_cd;
	t_timer		animation_cd;
	t_timer		shot_cd;
	t_timer		animation_shot_cd;
    t_timer     mouse;
}				t_timers;

/*
**	---------------------------------- png --------------------------------------------
*/

typedef struct	s_png
{
	Uint32		len;
	Uint32		width;
	Uint32		height;
	Uint8		pitch;
	Uint8		color_type;
	Uint8		compression_method;
	Uint8		filter_method;
	Uint8		interlace_method;
	Uint32		*data;
}				t_png;

/*
**	---------------------------------- color_picker --------------------------------------------
*/

typedef struct		s_color_picker
{
	//Uint16			abs_color;
	float			pos;
	SDL_Color		selected_color;
}					t_color_picker;

/*
**	---------------------------------- linedef --------------------------------------------
*/

enum	e_linedef
{
	LINEDEF_NONE = 0b0000,
	LINEDEF_SELECTED = 0b0001,
	LINEDEF_MOUSE_POINTED = 0b0010,
	LINEDEF_MOUSE_NEXT = 0b0100
};

enum	e_glinedef
{
	WALL = 0b0001,
	PORTAL = 0b0010,
	FLOOR = 0b0100,
	CEIL = 0b1000,
	DOOR_OPEN = 0b00010000,
	DOOR_CLOSE = 0b00100000
};

typedef enum	e_linedef_side
{
	SIDE_NONE = 0,
	SIDE_RIGHT = 1,
	SIDE_LEFT = 2
}				t_linedef_side;

typedef struct			s_linedef
{
	char				*name;		//Inutile
	t_dot	    		p1;			//Stocke les donnees du fichier
	t_dot               p2;			//
	t_linedef_side		side;
	
	t_plan				equation;
	t_fdot_3d			origin;
	t_fdot_3d           i;
	t_fdot_3d  			j;
	
	SDL_Surface			*texture;
	Uint32				flags;
	Uint32				gflags;
	int					id;
	
	t_fdot_3d			poly_3d[4];
	t_dot				poly_2d[4];
	t_dot				poly_2d_origin;
	int					poly_w;
	int					poly_h;
	
	struct s_sector		*sector;
	struct s_linedef	*destline;
	struct s_linedef	*next;
}						t_linedef;

/*
** =======================================================================================
** ================================== DISPLAY ============================================
** =======================================================================================
*/

/*
**	---------------------------------- hud --------------------------------------------
*/
typedef struct 	s_texhud
{
	SDL_Texture		*tex[16];
	SDL_Texture		*tex_weapon[6];
	SDL_Texture		*tex_reload[5];
	TTF_Font		*police;
}					t_texhud;

/*
**	---------------------------------- main_menu --------------------------------------------
*/

typedef struct s_main_menu
{
	SDL_Texture *text[4];
	SDL_Texture	*textb[4];
	TTF_Font	*police;

}				t_main_menu;

/*
**	---------------------------------- Window ----------------------------------
*/

typedef struct		s_ed_texture
{
	SDL_Texture		*frame_texture;
	SDL_Texture		*button;
	SDL_Texture		*clear;
	SDL_Texture		*clicked_button;
	SDL_Texture		*on_mouse_button;
	SDL_Texture		*digit_tab[10];
}					t_ed_texture;

typedef struct		s_font
{
	TTF_Font		*digital;
	TTF_Font		*ui;
}					t_font;

typedef struct		s_doom_music
{
	Mix_Music		*editor_music;
	Mix_Music		*credit_music;
	Mix_Music		*menu_music;
}					t_doom_music;

typedef enum		e_view
{
	TEXTURE_VIEW = 0b0001,
	WALL_VIEW = 0b0010,
	BOX_VIEW = 0b0100,
	LIGHT_VIEW = 0b1000
}					t_view;

typedef struct		s_win
{
	struct s_map	*map;

	SDL_Window*		ptr;
	SDL_Renderer	*rend;
	Uint32			*pixels;
	SDL_Texture		*rend_texture;
	t_timer			view_change_time;

	struct s_thread	*threads;
	int				w;
	int				h;
	float			w_div_fov;
	float			h_div_fov;

	SDL_Texture		**sectors_texture;
	t_ed_texture	ed_texture;
	SDL_Texture		**sectors_texture_selected;
	SDL_Texture		*text_entry_texture;

	char			*text_entry;

	t_frame			*frames;
	t_frame			*selected_frame;

	t_button		*selected_button;

	t_font			font;
	t_texhud		*texhud;

	t_doom_music	music;
	t_main_menu		*main_menu;

	char			**error_msg;
	int				nb_error_msg;
	
	// libui
	t_winui			*winui;
}					t_win;

/*
**	---------------------------------- sector --------------------------------------------
*/

typedef struct				s_sector
{
	char					*name;
    t_linedef				*lines;
	int						floor_height;
	int						ceil_height;
	int						height;

	// SDL_Color				color;
	// t_plan					floor_equation;
	// SDL_Surface				*floor_texture;
	// t_plan					ceil_equation;
	// SDL_Surface				*ceil_texture;

	t_color_picker			color;
	int						light_level;
	// t_dot					center;
	struct	s_sector 		*next;
}							t_sector;

typedef struct				s_textures
{
	SDL_Surface				*wall_1;
	SDL_Surface				*wall_2;
	SDL_Surface				*floor;
	SDL_Surface				*ceil;
}							t_textures;

/*
**	----------------------------------- Raycasting ---------------------------------------
*/

typedef	struct				s_poly
{
	int						index;
	int						visible;
	int						collide;
	struct s_object			*object; 
	struct s_mob			*mob; 

	t_fdot_3d				dots_rotz_only[N_DOTS_POLY];
	t_fdot_3d				dots[N_DOTS_POLY];

	t_plan					equation_rotz_only;
	t_plan					equation;
	t_fdot_3d				i_rotz_only;
	t_fdot_3d				j_rotz_only;
	t_fdot_3d				i;
	t_fdot_3d				j;
	float					i_mag;
	float					j_mag;
	float					ii;
	float					jj;

	int						is_slide_ban;	//Utile pour les angles
	int						segment_code;

	t_fdot_3d				dots_new[N_DOTS_POLY + 2];	//Un poly ne peut passe que 2 fois sur x
	int						n_dot;
	t_dot					dots_proj[N_DOTS_POLY * 2];
	int						n_proj;	//*2 car une droite ne peut couper que 2 fois le bord de l'ecran
	t_dot					box_x;
	t_dot					box_y;

	SDL_Surface				*texture;
	float					light_coef;
	char					*texture_name;
	// t_enum_object			object;
	struct s_poly			*next;
}							t_poly;

typedef struct				s_thread
{
	pthread_t				thread;
	int						i;
	t_win					*win;
	struct s_map			*map;
	struct s_player			*player;
	t_poly					*poly;
}							t_thread;

/*
**	---------------------------------- mob --------------------------------------------
*/

typedef struct s_mob
{
	t_poly			*poly;
	t_fdot_3d		pos;
	int 			width;
	int 			width_2;
	int 			height;
	int 			height_2;
	int 			vel;
	int				alive;
	int 			health;
	int				damage;
	int 			type;
	struct s_mob	*next;
	int				dir;
	char 			*texture;
	float			light_coef;
}					t_mob;

/*
**	---------------------------------- Inventory --------------------------------------------
*/

typedef struct		s_item
{
	SDL_Texture		*text;
	SDL_Rect		*pos;
	int				nb;
}					t_item;

typedef struct		s_inventory
{
	t_item			*item[5];
	int				weapon;
	int 			magazine;
	int				ammo;
	int         	selected_slot;
}					t_inventory;

/*
**	---------------------------------- player --------------------------------------------
*/

typedef struct		s_player
{
	// int				debug;
	int				win_w;
	int				win_h;
	t_fdot_3d		pos;
	// t_fdot_3d		pos_up;
	int				flys;
	t_sector		*sector;
	t_dot			dpos;
	t_fdot			vel;
	float			const_vel;
	float			dir_init;
	float			fov;
	float			fov_2;
	float			fov_up;
	float			fov_up_2;
	float			ddir;
	float			rot_y;
	int				width;
	float			width_2;
	int				height;
	float			_4_height_10;
	int				sneak;
	// int				front_montant_sneak;
	int				collision_on;
	int				fly;
	t_timer			fly_timer;
	int				jump;
	float			sprint;

	// int				numsector;
	int 			damage;
	int 			currentHp;
	int 			maxHp;
	int 			currentArmor;
	int				maxArmor;
	t_inventory		*inventory;
	int				interaction_inventaire;
	t_timer			interaction_inventaire_time;
	t_timers		timers;
	int				i_sector;
	t_line			l[5];
	int 			*bullet_drop;
	int 			len_bullet;
	float			demipetitaxe;

	// t_cartesienne	*rays;
	t_cartesienne	**rays;
	t_matrix		rx;
	t_matrix		rx_inv;
	t_matrix		ry;
	t_matrix		ry_inv;
	t_matrix		rz;
	t_matrix		rz_inv;

}					t_player;

/*
**	---------------------------------- objects --------------------------------------------
*/

typedef enum				e_enum_object
{
	HEAL = 0b0001,
	ARMOR = 0b0010,
	TP = 0b0100,
	GUN = 0b1000,
	BULLET = 0b10000,
	GRAVITY_INV = 0b100000,
	BOX = 0b1000000,
	LIGHT = 0b10000000,
	END = 0b100000000,
	DOOR = 0b1000000000
}							t_enum_object;

// typedef struct bordel_struct
// {
// 	/* data */
// }					


typedef struct		s_object
{
	int				main_poly;
	t_fdot_3d		pos_rotz_only;
	t_fdot_3d		pos;
	t_enum_object	type;
	float			data;
	int				visible;
	int				collide;

	float			rot_y_save;

	int 			id;
	int				id_texture;

	t_poly			*poly;
	int 			width;
	int 			width_2;
	int 			height;
	int 			height_2;
	float			light_coef;

	int 			dir;
	char 			*texture;
	struct s_object	*next;
	// struct s_object	*next_light;
}					t_object;

/*
**	---------------------------------- map_editor --------------------------------------------
*/

enum	e_map_editor
{
	MAP_NONE = 0,
	DRAWING_LINE = 1,
	MAP_SELECTING = 2,
	MAP_TEXT_EDITING = 4,
	MAP_MOVING_PLAYER = 8
};

typedef struct		s_map_editor
{
	char			*name;
	int				x;
	int				y;
	int				w;
	int				h;
	float			unit;
	t_sector		*sectors;
	t_sector		*selected_sector;
	SDL_Rect		rect_util;
	Uint32			flags;
	int				nb_lines;
	t_player		player;
	t_line			ordinate;
	t_line			abscissa;
	SDL_bool		abscissa_b;
	SDL_bool		ordinate_b;
}					t_map_editor;

enum
{
	CURSOR_DEFAULT = 0,
	CURSOR_SELECTING = 1
};


/*
**	---------------------------------- save --------------------------------------------
*/

typedef struct s_save
{
	int ifPars;
}				t_save;

/*
**	---------------------------------- map --------------------------------------------
*/

typedef struct	s_export
{
	char		*path;
	void		*map;
}				t_export;

#define	NEXT_RADIUS 20

typedef struct		s_mob_settings
{
	int				z;
	int				width;
	int				height;
	int				health;
	int				damage;
	int				velocity;
}					t_mob_settings;

typedef struct		s_min_max
{
	int				min;
	int				max;
}					t_min_max;

typedef struct		s_inclined_settings
{
	int				z1;
	int				z2;
}					t_inclined_settings;

typedef struct		s_object_settings
{
	int				z;
	int				width;
}					t_object_settings;

typedef struct			s_settings
{
	t_mob_settings		mob;
	t_inclined_settings	inclined;
	t_min_max			wall;
	t_object_settings	object;
	int					flat_z;
	char				*texture;
}						t_settings;

typedef struct		s_editor
{
	t_dot			pos;
	t_dot			size;
	float			unit;
	int				z_min;
	int				z_max;
	t_settings		settings;
	int				place_step;
	t_rect			select_rect;
	t_poly			*selected_poly;
	t_mob			*selected_mob;
	t_object		*selected_obj;
	t_poly			*placing_poly;
	int				min_pos_z;
	int				max_pos_z;
	t_editor_flag	flags;
	t_editor_calc	calc;
	t_arg_menu		arg_menu_tab[15];
	SDL_Cursor		*cursor[2];
	t_export		export;
}					t_editor;

typedef struct		s_map
{
	t_poly			*polys;
	t_poly			*polys_save;
	t_fdot_3d		last_move;
	t_textures		textures;
	t_player		player;
	t_view			view;
	float			gravity;
	t_timer			gravity_inv_time;
	t_object		*objects;
	t_object		*objects_save;
	t_timer			objects_animation;
	t_timer			objects_tp_timer;
	// t_object		*lights;
	t_mob			*mob;
	t_main_menu		main_menu;
	SDL_Event		*event;
	t_music			*music;
	t_editor		editor;
	t_save			save;
}					t_map;

#endif
