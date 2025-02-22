/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:38:42 by ash               #+#    #+#             */
/*   Updated: 2021/05/23 13:50:37 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_bool		hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	t_vec		oc;
	double		d;
	double		sqrtd;
	double		root;

	sp = (t_sphere *)sp_obj->element;
	oc = v_sub(ray->origin, sp->center);
	d = pow(v_dot(oc, ray->dir), 2) - (v_pow(ray->dir) * (v_pow(oc) - sp->r2));
	sqrtd = sqrt(d);
	root = (-v_dot(oc, ray->dir) - sqrtd) / v_pow(ray->dir);
	if (d < 0)
		return (FALSE);
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-v_dot(oc, ray->dir) + sqrtd) / v_pow(ray->dir);
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->albedo = sp->color;
	rec->p = ray_at(ray, root);
	rec->normal = v_unit(v_sub(rec->p, sp->center));
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool		hit_plane(t_object *plane_obj, t_ray *ray, t_hit_record *rec)
{
	double	t;
	double	den;
	t_plane	*pln;

	pln = (t_plane *)plane_obj->element;
	den = v_dot(ray->dir, pln->normal);
	if (fabs(den) < EPSILON)
		return (FALSE);
	t = v_dot(v_sub(pln->point, ray->origin), pln->normal) / den;
	if (t < rec->tmin || t > rec->tmax)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(ray, rec->t);
	rec->normal = pln->normal;
	rec->albedo = pln->color;
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool		hit_square(t_ray *r, t_object *obj, t_hit_record *rec)
{
	t_square	*square;
	t_vec		u;
	t_vec		v;
	double		a;
	double		b;

	square = (t_square *)obj->element;
	if (!hit_plane(obj, r, rec))
		return (FALSE);
	if (square->normal.x == 0 && square->normal.y == 1 && square->normal.z == 0)
		u = vec(0, 0, 1);
	else
		u = vec(0, 1, 0);
	v = v_unit(v_cross(u, square->normal));
	a = v_dot(u, v_sub(rec->p, square->point)) / v_dot(u, u);
	b = v_dot(v, v_sub(rec->p, square->point)) / v_dot(v, v);
	if ((a < square->len / -2.0) || (a > square->len / 2.0) ||
		(b < square->len / -2.0) || (b > square->len / 2.0))
		return (FALSE);
	rec->normal = square->normal;
	rec->albedo = square->color;
	return (TRUE);
}
