/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:27:28 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/25 20:04:42 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_get_coord_from_uv(t_texture *textur, t_3dpt *coord, t_uv *uv)
{
	double scale;

	scale = 1;
	coord->x = textur->width * uv->tu * textur->xscale;
	coord->y = textur->height * uv->tv * textur->yscale;
	if (coord->x >= textur->width && textur->width > 0)
	{
		if (textur->width <= 0)
			ft_error("Texture width needs to be bigger than 0");
		scale = coord->x / textur->width;
		coord->x = coord->x - (textur->width * (int)scale);
	}
	if (coord->y >= textur->height && textur->height > 0)
	{
		if (textur->height <= 0)
			ft_error("Texture height needs to be bigger than 0");
		scale = coord->y / textur->height;
		coord->y = coord->y - (textur->height * (int)scale);
	}
}

void		ft_get_texture_prim_coord(t_prim *prim, t_3dpt *coord, t_texture *t)
{
	if (prim->type == SPHERE)
		ft_get_textur_sphere(prim, coord, t);
	else if (prim->type == CYLINDER || prim->type == CONE || prim->type == TORE)
		ft_get_textur_cyl(prim, coord, t);
	else if (prim->type == PLANE || prim->type == CERCLE ||
								prim->type == TRIANGLE || prim->type == RECT)
		ft_get_textur_plane(prim, coord, t);
}

t_color		ft_get_prim_texture_color(t_prim *prim)
{
	t_3dpt	coord;
	t_color	color;

	ft_get_texture_prim_coord(prim, &coord, &(prim->textur));
	color = ft_get_texture_color(&(prim->textur), coord.x, coord.y);
	return (color);
}

void		ft_convert_normal_map(t_3dpt *result, t_3dpt *source)
{
	result->x = source->x / 128 - 1;
	result->y = source->y / 128 - 1;
	result->z = source->z / 255;
}

void		ft_get_texture_prim_normal(t_prim *prim)
{
	t_3dpt		coord;
	t_3dpt		text_normal;
	t_3dpt		textur_reference;
	t_3dpt		normal_bent;
	t_quater	textur_to_origin;

	if (prim)
		ft_get_texture_prim_coord(prim, &coord, &(prim->textur_n));
	else
		return ;
	ft_get_texture_normal(&(text_normal), &(prim->textur_n), coord.x, coord.y);
	ft_convert_normal_map(&(text_normal), &(text_normal));
	ft_normalize_vector(&(text_normal));
	ft_set_3dpt(&textur_reference, 0, 0, 1);
	ft_find_quaters_between(&textur_to_origin, &textur_reference,
													&(prim->original_normal));
	ft_vec_quater_rot(&normal_bent, &text_normal, &(textur_to_origin));
	ft_set_3dpt(&(prim->normal), normal_bent.x, normal_bent.y, normal_bent.z);
	ft_normalize_vector(&(prim->normal));
}
