#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "minirt.h"

# define SP 0
# define PLN 1
# define TRI 2
# define SQU 3
# define CYL 4
# define FALSE 0
# define TRUE 1
# define LIGHT_POINT 1
# define EPSILON 1e-6

typedef int		t_bool;
typedef struct	s_vec t_vec;
typedef struct	s_vec t_color;
typedef struct	s_vec t_point;
typedef int		t_object_type;


struct	s_vec
{
	double x;
	double y;
	double z;
};

typedef struct	s_ray
{
	t_point	origin;
	t_vec	dir;
}				t_ray;

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
}				t_object;

typedef struct		s_camera
{
    t_point			origin;
    double			viewport_h;
    double			viewport_w;
    t_vec			horizontal;
    t_vec			vertical;
    double			focal_len;
    t_point			left_bottom;
	t_camera		*next;
}               	t_camera;

typedef struct		s_light
{
	t_point		origin;
	t_color		light_color;
	double		bright_ratio;
}					t_light;

typedef struct s_canvas
{
    int     width;
    int     height;
    double  aspect_ratio;
}               t_canvas;

typedef struct	s_hit_record
{
	t_point		p;	//교점의 좌표
	t_vec		normal;	//교점에서의 법선
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color		albedo;
	double		cy_height;
}				t_hit_record;

typedef struct	s_scene
{
	t_canvas		canvas;
	t_object		*camera;
	t_object		*world;
	t_object		*light;
	t_color			ambient; // 8.4에서 설명할 요소
	t_ray			ray;
	t_hit_record	rec;
}				t_scene;

typedef struct	s_vars 
{
	void		*mlx;
	void		*win;
	t_scene		*scene;
}				t_vars;

#endif