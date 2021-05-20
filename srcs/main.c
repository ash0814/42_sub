/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:55:42 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/21 00:40:31 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_bool		check_rt(char *s)
{
	int i;

	i = ft_strlen(s);
	if (!(s[--i] == 't' && s[--i] == 'r' && s[--i] == '.'))
		return (FALSE);
	else
		return (TRUE);
}

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			check_window_size(t_vars *vars)
{
	int			x;
	int			y;

	mlx_get_screen_size(vars->mlx, &x, &y);
	if (vars->scene->canvas.width > x)
		vars->scene->canvas.width = x;
	if (vars->scene->canvas.height > y)
		vars->scene->canvas.height = y;
}

int write_color(int t, t_color *pixel_color)
{
	return (t << 24 | (int)(255.999 * pixel_color->x) << 16 | (int)(255.999 * pixel_color->y) << 8 | (int)(255.999 * pixel_color->z));
}

void vec_print(char *str, t_point t) {
	printf("%s : %.2f %.2f %.2f\n", str, t.x, t.y, t.z);
}

void		print_image(t_vars *vars)
{
	t_data	image;
	t_color color;
	double	u;
	double	v;
	int 	i;
	int		j;

	t_camera *cam = (t_camera *)((t_object *)vars->scene->camera->next)->element;
	// vec_print("org", cam->org);
	// vec_print("normal", cam->normal);
	// printf("{fov : %f}\n", cam->fov);

	vars->win = mlx_new_window(vars->mlx, vars->scene->canvas.width,
							vars->scene->canvas.height, "ash_world!");
	image.img = mlx_new_image(vars->mlx, vars->scene->canvas.width,
							vars->scene->canvas.height);
	image.addr = mlx_get_data_addr(image.img,
				&image.bits_per_pixel, &image.line_length, &image.endian);
	j = vars->scene->canvas.height-1;
	while (j >= 0)
	{
		i = -1;
		while(++i < vars->scene->canvas.width)
		{
			u = (double) (i) / (vars->scene->canvas.width-1);
			v = (double)(j) / (vars->scene->canvas.height-1);
			vars->scene->ray = ray_primary(cam, u, v);
			color = ray_color(vars->scene);
			my_mlx_pixel_put(&image, i, vars->scene->canvas.height - 1 - j, write_color(0, &color));
		}
		j--;
	}
	// vec_print("orig test", ((t_light *)(vars->scene->light->element))->origin);
	mlx_put_image_to_window(vars->mlx, vars->win, image.img, 0, 0);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, (1L << 5), exit_hook, 0);
	mlx_loop(vars->mlx);
}

int			main(int argc, char *argv[])
{
	t_vars vars;


	vars.mlx = mlx_init();
	
	if ((argc == 2 || argc == 3) && check_rt(argv[1]) == TRUE)
	{
		vars.scene = scene_init( argv[1]);
	}
	else
		ft_error("input ERROR\n");
		
	check_window_size(&vars);
	print_image(&vars);
	return (0);
}	
