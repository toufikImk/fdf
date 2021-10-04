/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:41:29 by oahieiev          #+#    #+#             */
/*   Updated: 2021/10/03 05:11:15 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	mouse_pressed(int button, int mousex, int mousey, void *param)
{
	t_fdf			*fdf;

	fdf = (t_fdf *)param;
	(void)mousex;
	if (mousey < 0)
		return (1);
	else if (button == LMB)
	{
		fdf->cam->xoff = mousex - (WIDTH >> 1);
		fdf->cam->yoff = mousey - (HEIGHT >> 1);
	}
	else if (button == MWD)
		fdf->cam->zoom--;
	else if (button == MWU)
		fdf->cam->zoom++;
	if (fdf->cam->zoom == 0)
		fdf->cam->zoom = 1;
	draw(fdf, (*(*fdf).map).w, (*(*fdf).map).h);
	return (0);
}

static void	switch_view(t_fdf *fdf, int key)
{
	if (key == KB_U)
		fdf->map->cm += 5;
	else
	{
		fdf->cam->yoff -= (fdf->map->w * (fdf->cam->zoom >> 1)) * \
			((fdf->cam->isom) ? 1 : -1);
		fdf->cam->alph = fdf->cam->isom ? 0.0f : rad(ISOMETRIC_ANGLE_A);
		fdf->cam->beta = fdf->cam->isom ? 0.0f : rad(ISOMETRIC_ANGLE_B);
		fdf->cam->gamm = fdf->cam->isom ? 0.0f : rad(ISOMETRIC_ANGLE_G);
		fdf->cam->isom = !(fdf->cam->isom);
	}
}

static void	move(int key, t_fdf *p)
{
	const int	step = 10;

	if (key == KP_4)
		p->cam->xoff += step;
	else if (key == KP_6)
		p->cam->xoff -= step;
	else if (key == KP_8)
		p->cam->yoff += step;
	else
		p->cam->yoff -= step;
}

static void	rotate(int key, t_fdf *fdf)
{
	const float	step = rad(2.0f);

	if (key == KB_UP)
		fdf->cam->alph += step;
	else if (key == KB_DOWN)
		fdf->cam->alph -= step;
	else if (key == KB_LEFT)
		fdf->cam->gamm += step;
	else if (key == KB_RIGHT)
		fdf->cam->gamm -= step;
	else if (key == KB_W)
		fdf->cam->beta -= step;
	else
		fdf->cam->beta += step;
}

int	key_pressed(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == KB_ESC)
	{
		cleanall(fdf);
		exit(0);
		return (0);
	}
	else if (key == KB_UP || key == KB_DOWN || key == KB_LEFT || \
		key == KB_RIGHT || key == KB_W || key == KB_S)
		rotate(key, fdf);
	else if (key == KP_4 || key == KP_6 || key == KP_8 || key == KP_2)
		move(key, fdf);
	else if (key == KB_I || key == KB_U)
		switch_view(fdf, key);
	else if (key == KP_SUBTRACT)
		fdf->cam->zdiv += 0.333f;
	else if (key == KP_ADD && fdf->cam->zdiv >= 1.3f)
		fdf->cam->zdiv -= 0.333f;
	else if (key == KB_H)
		fdf->showhelp = !fdf->showhelp;
	draw(fdf, (*(*fdf).map).w, (*(*fdf).map).h);
	return (0);
}
