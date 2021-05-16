/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:21:46 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/17 02:00:57 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene		*scene_init(void)
{
	t_scene		*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	scene->canvas = canvas(1, 1);
	
	return (scene);
}