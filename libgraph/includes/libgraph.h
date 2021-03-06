/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:33:59 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/20 17:01:42 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRAPH_H
# define LIBGRAPH_H

# include "libft.h"
# include "../../minilibx_macos/mlx.h"
# include <math.h>

# define ESC_KEY 53
# define ONE_KEY 83
# define TWO_KEY 84
# define THREE_KEY 85
# define PLUS_KEY 69
# define PAGE_UP 116
# define MINUS_KEY 78
# define PAGE_DOWN 121
# define UP_KEY 126
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define LEFT_KEY 123
# define SPACE_KEY 49
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define C_KEY 8
# define R_KEY 15
# define T_KEY 17
# define A_KEY 0
# define W_KEY 13
# define S_KEY 1
# define D_KEY 2
# define LEFTAWSD_KEY 0
# define UPAWSD_KEY 13
# define DOWNAWSD_KEY 1
# define RIGHTAWSD_KEY 2
# define RED 0xFF0000
# define LIGHTRED 0x550000
# define SILVER 0xc0c0c0
# define GOLD 0xFFDF00
# define EMERALD 0x50c878
# define CYAN 0x00FFFF
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define BLUEGREEN 0x00FFFF
# define MAGENTA 0xFF00FF
# define BLACK 0x000000
# define SQR(x) ((x) * (x))
# define CUBE(x) ((x) * (x) * (x))

# define ERROR "Error"
# define TERROR "Thread failed to create"

typedef struct		s_3dpt
{
	double x;
	double y;
	double z;
}					t_3dpt;

typedef struct		s_mlximg
{
	void	*ptr;
	int		bpp;
	int		s_l;
	int		endian;
	int		length;
	int		height;
	char	*str;
}					t_mlximg;

typedef struct		s_winenv
{
	void		*win;
	void		*mlxptr;
	t_mlximg	img;
	int			length;
	int			height;
	int			lpad;
	int			tpad;
}					t_winenv;

typedef struct		s_color
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
}					t_color;

typedef struct		s_texture
{
	int				width;
	int				height;
	int				n;
	int				valid;
	unsigned char	*data;
	double			xscale;
	double			yscale;
	double			xmove;
	double			ymove;
}					t_texture;

void				ft_error(char *str);
void				ft_mlx_init(t_winenv *mlxenv);
void				ft_create_window(t_winenv *mlxenv, int length,
											int height, char *title);
double				v_scale(t_3dpt *u1, t_3dpt *u2);
t_3dpt				v_sub(t_3dpt *u1, t_3dpt *u2);
t_3dpt				v_prod(t_3dpt *u1, t_3dpt *u2);

void				ft_fill_img(t_mlximg img, int x, int y, int color);
void				ft_fill_img_rgb(t_mlximg img, int x, int y, t_color color);
void				ft_create_img(t_winenv *mlxenv, int length, int height);
int					ft_key_hook_exit(int keycode);
void				ft_set_3dpt(t_3dpt *point, double x, double y, double z);
void				ft_set_color(t_color *color, int r, int g, int b);
t_color				ft_get_texture_color(t_texture *textur, int x, int y);
void				ft_stb_load_textur(t_texture *textur, char *file_path);
void				ft_get_texture_normal(t_3dpt *normal, t_texture *textur,
															int x, int y);
t_color				ft_read_img_rgb(t_mlximg *img, int x, int y);

#endif
