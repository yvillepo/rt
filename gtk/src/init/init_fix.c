/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:14:50 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 17:00:32 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_init_3d_button(t_3d_button *button)
{
	button->box_h = NULL;
	button->label_x = NULL;
	button->x = NULL;
	button->label_y = NULL;
	button->y = NULL;
	button->label_z = NULL;
	button->z = NULL;
}

static void	ft_init_triangle(t_interface *inter)
{
	ft_init_3d_button(&inter->triang.p1);
	ft_init_3d_button(&inter->triang.p2);
	ft_init_3d_button(&inter->triang.p3);
}

void		ft_init_fix(t_interface *inter)
{
	ft_init_3d_button(&inter->fix.pos);
	ft_init_3d_button(&inter->fix.translation);
	ft_init_3d_button(&inter->fix.vec);
	ft_init_3d_button(&inter->fix.rot);
	ft_init_1d_button(&inter->fix.angle_rot);
	ft_init_3d_button(&inter->fix.color);
	ft_init_triangle(inter);
}
