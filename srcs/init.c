/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:21:46 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/18 14:01:36 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// t_scene		*scene_init(void)
// {
// 	t_scene		*scene;

// 	scene = (t_scene *)malloc(sizeof(t_scene));
// 	scene->canvas = canvas(1, 1);
// 	scene->light = object(LIGHT_POINT, light_point(point(0, 0, 0), color(0, 0, 0), 0.0));
// 	scene->camera = object(CAM, camera(scene->canvas, point(0, 0, 0), vec(0, 0, 0), 0));
// 	return (scene);
// }

void			scene_init(t_scene *scene, char *argv)
{
	void		*temp;

	scene->camera = object(CAM, camera(canvas(1, 1), point(0, 0, 0), vec(0, 0, 0), 0));
	scene->world = object(SQU, square(point(0, 0, 0), vec(0, 0, 0), 0, color(0, 0, 0)));
	scene->light = object(LIGHT_POINT, light_point(point(0, 0, 0), color(0, 0, 0), 0));
	scene->ambient.x = -1;
	parse(argv, scene);
	temp = scene->camera;
	scene->camera = scene->camera->next;
	free(temp);
	temp = scene->world;
	free(scene->world->element);
	scene->world = scene->world->next;
	free(temp);
	temp = scene->light;
	free(scene->light->element);
	scene->light = scene->light->next;
	free(temp);
	if (!(scene->camera) || scene->canvas.aspect_ratio == 0 || scene->ambient.x == -1)
		ft_error("missing camera or canvas");
}