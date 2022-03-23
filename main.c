
#include "rtv1.h"

/////////////////////////////////////////////
/*void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
        if (action == GLFW_PRESS)
        {
                void *param = glfwGetWindowUserPointer(window);
                mouse_press(button, x, y, param);
        }
}
*/
/*
void cursor_position_callback(GLFWwindow* window, double x, double y)
{
	printf("cursor is %f,%f\n", x, y);
        void *param = glfwGetWindowUserPointer(window);
//        glBufferData(GL_ARRAY_BUFFER, sizeof(int) * 1000, img_ptr, GL_DYNAMIC_DRAW);
        mouse_move(x, y, param);
	glDrawArrays(GL_POINTS, 0, 1203);
}
*/
/*
void    key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	printf("hi\n");
	if (action == 0)
		return ;
        void *param = glfwGetWindowUserPointer(window);
        key_press(key, param);
}
*/

//////////////////////////////////////////////////////////////

int			con(t_global *g)
{
	return (shot.x == g->ray->x && shot.y == g->ray->y);
}

/*
int		mouse_press(int button, int x, int y, void *param)
{
	t_global *g;
	t_object a;

	g = param;
//	ft_bzero((int *)g->data_ptr, g->sz_l * HEIGHT);
	if (button == 1)
	{
		shot.x = -WIDTH / 2 + x;
		shot.y = HEIGHT / 2 - y;
		printf("\n%f, %f\n", shot.x, shot.y);
//		a = g->obj[g->objn];
//		printf("object is %d %s %f, %f, %f\n%f,%f, %f\n", g->objn, a.name, a.ctr->x, a.ctr->y, a.ctr->z, a.nr.x, a.nr.y, a.nr.z);
		printf("mouse press -> realc\n");
		start_threads(toimg, g);
//	start_threads(recalc, g);
	}
	return (1);
}
*/

void		free_arr(char **arr)
{
	int i;

	i = 0;
	while (*(arr + i) != NULL)
	{
		printf("now freeing %s\n", *(arr + i));
		free(*(arr + i));
		i++;
	}
}

int		putstr(char *s, int ret)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		write(1, s + i, 1);
		i++;
	}
	return (ret);
}

/*
void		screen(int *a, int x, int y, t_global *g)
{
	int i = 0;
	int j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			mlx_pixel_put(g->mlx_ptr, g->win_ptr, i, j, *(a + j * x + i));
			i++;
		}
		j++;
	}
}
*/

/*
void		draw_vectile(t_vector *t, int w, int h, t_global *g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
//			printf("we are at %d,%d\n", i, j);
			mlx_pixel_put(g->mlx_ptr, g->win_ptr, i, j, brg(scale(255, *(t + j * h + i))));
			i++;
		}
		j++;
	}
}
*/

/*
void		draw_func(t_global *g)
{
	int i = -WIDTH / 2;

	while (i < WIDTH / 2)
	{
		mlx_pixel_put(g->mlx_ptr, g->win_ptr, i + WIDTH / 2, HEIGHT / 2- 20 * acos(i / (float)20), 0xFFFFFF);
		i++;
	}
}
*/
int		main(int argc, char **argv)
{
	t_global g;
	t_vector ctr[argc];
	t_vector kenobi[5];
	int h;
	int w;

	h = WIDTH;
	w = HEIGHT;
	g.cam_pos = &kenobi[0];
	g.angle = &kenobi[1];
	g.ray = &kenobi[2];
	g.li = &kenobi[3];
	g.normal = &kenobi[4];

	g.mlx_ptr = mymlx_init();
	ginit(&g);
	if (!check_arg(argv, argc, &g, ctr))
		return (0);
	g.win_ptr = mymlx_new_window(g.mlx_ptr, WIDTH, HEIGHT, "window1");
	g.img_ptr = mymlx_new_image(g.mlx_ptr, WIDTH, HEIGHT);
	g.data_ptr = (int *)mymlx_get_data_addr(g.img_ptr, &g.bpp, &g.sz_l, &g.e);
	printf("data_ptr is %p\n", g.data_ptr);
//	g.win_ptr = mymlx_new_window(g.mlx_ptr, WIDTH, HEIGHT, "window1");
	copy_tcps(&g);
	start_threads(recalc, &g);
	printf("address of g is %p\n", &g);
	mymlx_hook(g.win_ptr, 4, 4, mouse_press, &g);
	mymlx_hook(g.win_ptr, 2, 2, key_press, &g);
	mymlx_hook(g.win_ptr, 6, 6, mouse_move, &g);
	mymlx_loop(g.mlx_ptr);
}
